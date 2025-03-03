// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <glog/logging.h>
#include <memory>

namespace facebook {
namespace dynolog {

/* Skeleton Monitor class which subscribes to a Ticker for
 * scheduling.
 */
template <typename TTicker>
class MonitorBase {
 public:
  using TMask = typename TTicker::TMask;
  MonitorBase(
      std::shared_ptr<TTicker> ticker,
      const std::string& name,
      std::vector<double> subminor_tick_sample_rates)
      : _ticker(ticker),
        _name(name),
        _subminor_tick_sample_rates(subminor_tick_sample_rates) {
    _ticker->subscribe(
        name,
        TTicker::TSubscriberConfig::make(
            name,
            [this](TMask mask) { this->tick(mask); },
            subminor_tick_sample_rates));
  }

  bool try_change_sample_rates(std::vector<double> subminor_tick_sample_rates) {
    std::shared_ptr<typename TTicker::TSubscriberConfig> new_config;
    try {
      new_config = std::make_shared<typename TTicker::TSubscriberConfig>(
          TTicker::TSubscriberConfig::make(
              _name,
              [this](TMask mask) { this->tick(mask); },
              subminor_tick_sample_rates));
    } catch (std::exception& e) {
      LOG(ERROR) << "Failed to create new config: " << e.what();
      return false;
    }
    // At this point assume config is valid
    _ticker->subscribe(_name, *new_config);
    _subminor_tick_sample_rates = subminor_tick_sample_rates;
    return true;
  }

  virtual void tick(TMask mask) = 0;
  virtual ~MonitorBase() {}

 private:
  std::shared_ptr<TTicker> _ticker;
  std::string _name;
  std::vector<double> _subminor_tick_sample_rates;

 protected:
  std::string get_name() const {
    return _name;
  }
  std::array<double, TTicker::_subtick_levels> get_subminor_tick_sample_rates()
      const {
    return _ticker->get_config(_name)->get_subminor_tick_sample_rates();
  }
};

} // namespace dynolog
} // namespace facebook
