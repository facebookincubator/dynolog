// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <glog/logging.h>
#include <memory>

namespace facebook {
namespace dynolog {

/* Skeleton Monitor class for Dyno which subscribes to a DynoTicker for
 * scheduling.
 */
template <typename TDynoTicker>
class DynoMonitorBase {
 public:
  using TMask = typename TDynoTicker::TMask;
  DynoMonitorBase(
      std::shared_ptr<TDynoTicker> ticker,
      const std::string& name,
      std::vector<double> subminor_tick_sample_rates)
      : _ticker(ticker),
        _name(name),
        _subminor_tick_sample_rates(subminor_tick_sample_rates) {
    _ticker->subscribe(
        name,
        TDynoTicker::TSubscriberConfig::make(
            name,
            [this](TMask mask) { this->tick(mask); },
            subminor_tick_sample_rates));
  }

  bool try_change_sample_rates(std::vector<double> subminor_tick_sample_rates) {
    std::shared_ptr<typename TDynoTicker::TSubscriberConfig> new_config;
    try {
      new_config = std::make_shared<typename TDynoTicker::TSubscriberConfig>(
          TDynoTicker::TSubscriberConfig::make(
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
  virtual ~DynoMonitorBase() {}

 private:
  std::shared_ptr<TDynoTicker> _ticker;
  std::string _name;
  std::vector<double> _subminor_tick_sample_rates;

 protected:
  std::string get_name() const {
    return _name;
  }
  std::array<double, TDynoTicker::_subtick_levels>
  get_subminor_tick_sample_rates() const {
    return _ticker->get_config(_name)->get_subminor_tick_sample_rates();
  }
};

} // namespace dynolog
} // namespace facebook
