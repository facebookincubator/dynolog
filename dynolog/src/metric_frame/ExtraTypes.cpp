#include "dynolog/src/metric_frame/ExtraTypes.h"

namespace facebook::dynolog {

std::ostream& operator<<(
    std::ostream& os,
    const PerfReadValues& perfReadValues) {
  os << perfReadValues.toString();
  return os;
}

} // namespace facebook::dynolog
