// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <cmath>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <map>
#include <memory>
#include <mutex>
#include <optional>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include <glog/logging.h>

namespace facebook {
namespace dynolog {

/*
  A class to manage the periodic scheduling of e.g. Monitors.

  Multiple periodicities are supported: major, minor, and a templated number of
  levels of sub-minor ticks. Template parameters:

    - major_tick_ms: the interval between major ticks
    - minor_tick_ms: the interval between minor ticks
    - base: the number of sub-minor ticks per higher level of sub-minor tick (or
      minor tick)
    - levels: the number of levels, major, minor and any sub-minor ticks

  A subscriber must provide a callback function and a sample_rate vector, which
  determines the % of sub-minor ticks that will be called for each level. Major
  and minor ticks are always called. The callback function must accept a bitwise
  mask which will indicate to the subscriber which levels a given tick
  corresponds to. Sub-minor ticks are always called sequentially within a minor
  tick, with the length of the sequence being specified by the sample_rate. For
  instance, for a minor_tick_ms of 1000, base of 10 and a sample_rate of {1.0,
  0.2}, the caller will be called every 100 ms, and for 20% of the time within
  each minor tick, every 10ms (20 ticks spaced 10ms apart and positioned
  randomly between the previous and subsequent minor tick).

  Subscribers may be added or amended by calling the subscribe() function, but
  these changes are only effected at the next major_tick.

  The ticker is started by calling the run() method. A mutex ensures only one
  instance of the run() loop can be active.

  The implementation favors minimization of the compute overhead of the actively
  running ticker at the expense of some memory overhead. To achieve this, each
  minor tick to be called is represented in a vector. The high compute expense
  of populating this vector is borne only on major ticks where a subscriber
  change has occurred, which is expected to be rare.
*/

template <std::size_t N, uint64_t base, bool reverse>
constexpr std::array<uint64_t, N> make_geometric_array_impl(
    std::array<uint64_t, N> ret,
    std::size_t i = 0) {
  if (i == N) {
    return ret;
  }
  if (i == 0) {
    if (reverse) {
      ret[N - 1] = 1;
    } else {
      ret[0] = 1;
    }
  } else {
    if (reverse) {
      ret[N - 1 - i] = ret[N - i] * base;
    } else {
      ret[i] = ret[i - 1] * base;
    }
  }
  return make_geometric_array_impl<N, base, reverse>(ret, i + 1);
}
template <std::size_t N, uint64_t base, bool reverse>
constexpr std::array<uint64_t, N> make_geometric_array() {
  static_assert(N > 0, "cannot instantiate empty array");
  return make_geometric_array_impl<N, base, reverse>(std::array<uint64_t, N>{});
}

static_assert(make_geometric_array<3, 2, false>()[0] == 1);
static_assert(make_geometric_array<3, 2, false>()[1] == 2);
static_assert(make_geometric_array<3, 2, false>()[2] == 4);
static_assert(make_geometric_array<4, 10, true>()[0] == 1000);
static_assert(make_geometric_array<4, 10, true>()[1] == 100);
static_assert(make_geometric_array<4, 10, true>()[2] == 10);
static_assert(make_geometric_array<4, 10, true>()[3] == 1);

template <
    uint64_t major_tick_ms,
    uint64_t minor_tick_ms,
    uint64_t base,
    std::size_t levels>
class Ticker {
  static constexpr std::size_t k_max_levels = 16; // including major and minor
  static_assert(major_tick_ms > 0, "invalid major tick");
  static_assert(minor_tick_ms > 0, "invalid minor tick");
  static_assert(base > 1 || levels == 2, "invalid base");
  static_assert(levels > 1, "need at least two levels, major and minor");
  static_assert(levels <= k_max_levels, "too many levels");
  static_assert(
      major_tick_ms % minor_tick_ms == 0,
      "major tick interval must be a multiple of minor tick");

  static constexpr uint64_t minor_ticks_per_major_tick =
      major_tick_ms / minor_tick_ms;
  static constexpr std::array<uint64_t, levels - 1>
      _level_ticks_per_minor_tick =
          make_geometric_array<levels - 1, base, false>();
  static constexpr std::array<uint64_t, levels - 1>
      _fundamental_tick_per_level =
          make_geometric_array<levels - 1, base, true>();
  static constexpr uint64_t _fundamental_tick_per_minor_tick =
      _fundamental_tick_per_level[0];
  static constexpr uint64_t _fundamental_tick_ns =
      minor_tick_ms * 1000000 / _fundamental_tick_per_minor_tick;

  static_assert(
      _fundamental_tick_ns > 10000,
      "last level tick must be at least 10 us");

 public:
  using TMask = uint16_t;
  using TTicker = Ticker<major_tick_ms, minor_tick_ms, base, levels>;
  using TFunc = std::function<void(TMask level_mask)>;
  using TFuncBound = std::function<void()>;
  using Tick = std::pair<uint64_t, TFuncBound>; // idx, mask, callback

  static constexpr uint64_t _major_tick_ms = major_tick_ms;
  static constexpr uint64_t _minor_tick_ms = minor_tick_ms;
  static constexpr uint64_t _base = base;
  static constexpr uint64_t _levels = levels;
  static constexpr uint64_t _subtick_levels = levels - 2;

  class SubscriberConfig {
   public:
    SubscriberConfig(
        const std::string& name,
        const TFunc& f,
        const std::array<double, _subtick_levels>& subminor_tick_sample_rates)
        : _name(name),
          _f(f),
          _subminor_tick_sample_rates(subminor_tick_sample_rates) {
      reseed();
      LOG(INFO) << print_plan();
    }

    static SubscriberConfig make(
        const std::string& name,
        const TFunc& f,
        const std::vector<double>& subminor_tick_sample_rates) {
      if (subminor_tick_sample_rates.size() > _subtick_levels) {
        throw std::runtime_error(std::string(
            "config is invalid because there are more sample_rates (" +
            std::to_string(subminor_tick_sample_rates.size()) +
            ") than tick levels (" + std::to_string(_subtick_levels) + ")"));
      }
      for (const auto& rate : subminor_tick_sample_rates) {
        if (rate < 0.0 || rate > 1.0) {
          throw std::runtime_error(std::string(
              "config is invalid because sample_rates (" +
              std::to_string(rate) + ") are not between 0.0 and 1.0"));
        }
      }
      std::array<double, _subtick_levels> sample_rates_array;
      for (auto& elem : sample_rates_array) {
        elem = 0.0;
      }
      std::copy(
          subminor_tick_sample_rates.begin(),
          subminor_tick_sample_rates.end(),
          sample_rates_array.begin());
      return SubscriberConfig(name, f, sample_rates_array);
    }

    const std::string print_plan() const {
      std::stringstream ss;
      ss << std::endl << std::endl;
      ss << "print_plan for SubscriberConfig: " << _name << std::endl
         << std::endl;
      ss << "major tick us:                   " << major_tick_ms * 1000
         << std::endl;
      ss << "minor tick us:                   " << minor_tick_ms * 1000
         << std::endl;
      ss << "fundamental tick us:             " << _fundamental_tick_ns / 1000
         << std::endl;
      ss << "base:                            " << base << std::endl;
      ss << "levels:                          " << levels << std::endl;
      ss << "subtick levels:                  " << _subtick_levels << std::endl;
      ss << "subminor tick sample rates:      ";
      for (const auto& elem : _subminor_tick_sample_rates) {
        ss << elem << " ";
      }
      ss << std::endl;
      ss << std::endl;
      ss << std::setw(20) << "fundamental tick # |" << std::setw(20)
         << "minor tick (L1) |";
      for (std::size_t i = 2; i != levels; ++i) {
        ss << std::setw(20) << std::string("L") + std::to_string(i) + " tick |";
      }
      ss << std::endl;
      ss << std::setw(20) << "|" << std::setw(20) << "|";
      for (std::size_t i = 2; i != levels; ++i) {
        ss << std::setw(20) << "|";
      }
      ss << std::endl;
      for (std::size_t i = 0; i != _fundamental_tick_per_minor_tick; ++i) {
        ss << std::setw(20) << i;
        auto mask = make_mask(i, false);
        for (std::size_t j = 0; j != levels - 1; ++j) {
          if (mask & (1 << 1 << j)) {
            ss << std::setw(20) << "X";
          } else {
            ss << std::setw(20) << " ";
          }
        }
        ss << std::endl;
      }
      return ss.str();
    }

    const std::array<double, _subtick_levels> get_subminor_tick_sample_rates() {
      return _subminor_tick_sample_rates;
    }

   private:
    void reseed() {
      // subminor ticks: randomize when they occur, i.e. the offset within a
      // minor tick interval when the sequence starts
      for (std::size_t i = 0; i != _subtick_levels; ++i) {
        uint64_t n_ticks = floor(
            _level_ticks_per_minor_tick[i + 1] *
            _subminor_tick_sample_rates[i]);
        // Max possible start index to still achieve the desired sample rate
        _start_idx[i] = _level_ticks_per_minor_tick[i + 1] - n_ticks;
        if (_start_idx[i] != 0) {
          // Randomize the offset
          _start_idx[i] = rand() % _start_idx[i];
        }
        _end_idx[i] = _start_idx[i] + n_ticks;
        // Convert to fundamental ticks
        _start_idx[i] *= _fundamental_tick_per_level[i + 1];
        _end_idx[i] *= _fundamental_tick_per_level[i + 1];
      }
    }

    inline TMask make_mask(uint64_t idx, bool is_major_tick) const {
      // idx is an index in units of fundamental ticks
      uint64_t mask = 0;
      if (is_major_tick) {
        mask = 1;
      }
      if (idx % _fundamental_tick_per_minor_tick == 0) {
        // minor_tick
        mask |= 1 << 1;
      }
      for (std::size_t i = 0; i != _subtick_levels; ++i) {
        if (idx % _fundamental_tick_per_level[i + 1] == 0 &&
            idx >= _start_idx[i] && idx < _end_idx[i]) {
          mask |= 1 << 2 << i;
        }
      }
      return mask;
    }

    std::optional<Tick> get_tick_maybe(uint64_t idx) {
      // Returns a Tick if we are subscribing to the given fundamental interval
      // idx.
      TMask mask = make_mask(idx, false);
      if (mask > 0) {
        return std::make_pair(mask, std::bind(_f, mask));
      }
      return std::nullopt;
    }

    TFuncBound get_major_tick() {
      TMask mask = make_mask(0, true);
      return std::bind(_f, mask);
    }

    const std::string _name;
    const TFunc _f;
    const std::array<double, _subtick_levels> _subminor_tick_sample_rates;
    std::array<uint64_t, _subtick_levels> _start_idx;
    std::array<uint64_t, _subtick_levels> _end_idx;

    friend class MonitorTickerTest;
    friend class Ticker;
  };

  using TSubscriberConfig = typename TTicker::SubscriberConfig;

  void subscribe(const std::string& name, const SubscriberConfig& config) {
    const std::lock_guard<std::mutex> lock(_rebuild_mutex);
    LOG(INFO) << "subscribe " << name;
    _configs.erase(name);
    _configs.emplace(name, config);
    _rebuild_needed = true;
  }

  std::optional<TSubscriberConfig> get_config(const std::string& name) {
    const std::lock_guard<std::mutex> lock(_rebuild_mutex);
    if (_configs.find(name) != _configs.end()) {
      return _configs.at(name);
    }
    return std::nullopt;
  }

  void run() {
    // Run forever
    run_inner();
  }

  void run_inner(uint64_t major_tick_limit = 0) {
    bool l = _run_mutex.try_lock();
    if (!l) {
      throw std::runtime_error("cannot run a Ticker that is already running");
    }
    uint64_t major_tick_count = 0;
    const std::chrono::steady_clock::time_point ticker_start =
        std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point major_tick_start =
        std::chrono::steady_clock::now();

    // Loop over major ticks
    while (major_tick_limit == 0 || major_tick_count != major_tick_limit) {
      if (_rebuild_needed) {
        // Get here if subscribe() was called in the last major_tick
        rebuild_plan();
      }
      major_tick_start = ticker_start +
          std::chrono::milliseconds(major_tick_ms * major_tick_count);
      const auto delay = major_tick_start - std::chrono::steady_clock::now();
      if (delay > std::chrono::milliseconds(100)) {
        // This means that the time we ought to have been here is more than
        // 100ms in the past, implying we are backlogged.
        LOG(WARNING) << "ticker backlog "
                     << std::chrono::duration_cast<std::chrono::milliseconds>(
                            delay)
                            .count()
                     << " ms at " << major_tick_count << " major ticks";
      }
      std::this_thread::sleep_until(major_tick_start);
      LOG(INFO) << "major_tick " << major_tick_count;
      for (const auto& callback : _major_tick_callbacks) {
        callback->operator()();
      }
      // Loop over minor ticks
      for (std::size_t i = 0; i != minor_ticks_per_major_tick; ++i) {
        // The actual callbacks on minor ticks are included in _tick_idx
        for (std::size_t j = 0; j != _tick_idx.size(); ++j) {
          if (i == 0 && j < _major_tick_callbacks.size()) {
            // This would be a major tick, which we already handled above
            continue;
          }
          const auto& tick_idx = _tick_idx[j];
          const auto& tick_callback = _tick_callbacks[j];
          if (j == 0 || tick_idx != _tick_idx[j - 1]) {
            std::this_thread::sleep_until(
                major_tick_start +
                std::chrono::milliseconds(minor_tick_ms * i) +
                std::chrono::nanoseconds(tick_idx * _fundamental_tick_ns));
          }
          tick_callback->operator()();
        }
      }
      ++major_tick_count;
    }
    _run_mutex.unlock();
  }

  static inline bool is_major_tick(TMask mask) {
    return (mask & 1u) != 0;
  }

  static inline bool is_minor_tick(TMask mask) {
    return (mask & (1u << 1)) != 0;
  }

  static inline bool is_subminor_tick(TMask mask, std::size_t sublevel) {
    // sublevel == 0 is a minor tick
    return (mask & (1u << (sublevel + 2))) != 0;
  }

 private:
  void rebuild_plan() {
    const std::lock_guard<std::mutex> lock(_rebuild_mutex);
    LOG(INFO) << "rebuild_plan";
    _tick_idx.clear();
    _tick_callbacks.clear();
    _bound_subscribers.clear();
    _major_tick_callbacks.clear();

    // Add the major tick explicitly for each subscriber
    for (auto& [name, config] : _configs) {
      auto major_tick = config.get_major_tick();
      const auto bound_subscriber_key = std::make_pair(name, 0);
      _bound_subscribers.emplace(
          bound_subscriber_key, std::make_shared<TFuncBound>(major_tick));
      _major_tick_callbacks.push_back(_bound_subscribers[bound_subscriber_key]);
    }

    // For each possible tick, see if each subscriber is interested by calling
    // its get_tick_maybe() function. If yes, add it to the vector of callbacks.
    for (std::size_t i = 0; i != _fundamental_tick_per_minor_tick; ++i) {
      for (auto& [name, config] : _configs) {
        auto tick_maybe = config.get_tick_maybe(i);
        if (tick_maybe) {
          uint64_t mask = tick_maybe->first;
          const auto bound_subscriber_key = std::make_pair(name, mask);
          if (_bound_subscribers.find(bound_subscriber_key) ==
              _bound_subscribers.end()) {
            _bound_subscribers.emplace(
                bound_subscriber_key,
                std::make_shared<TFuncBound>(tick_maybe->second));
          }
          _tick_idx.push_back(i);
          _tick_callbacks.push_back(_bound_subscribers[bound_subscriber_key]);
        }
      }
    }
    _rebuild_needed = false;
  }

  std::map<std::string, SubscriberConfig> _configs;
  std::map<std::pair<std::string, uint64_t>, std::shared_ptr<TFuncBound>>
      _bound_subscribers;
  std::vector<uint64_t> _tick_idx;
  std::vector<std::shared_ptr<TFuncBound>> _tick_callbacks;
  std::vector<std::shared_ptr<TFuncBound>> _major_tick_callbacks;
  bool _rebuild_needed = true;
  std::mutex _rebuild_mutex;
  std::mutex _run_mutex;
};

using TickerMinuteSecondBase10 = Ticker<60000, 1000, 10, 4>;
using TickerConfigMinuteSecondBase10 =
    TickerMinuteSecondBase10::TSubscriberConfig;

} // namespace dynolog
} // namespace facebook
