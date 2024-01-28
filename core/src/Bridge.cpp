#include <dm-tcp-bridge/Bridge.hpp>

namespace dm_bridge {

  std::shared_ptr<Bridge> Bridge::create(const Bridge::Options& opts) {
    return std::shared_ptr<Bridge>();
  }

}