#pragma once
#include <thread>
#include <uvw/loop.h>
#include <uvw/tcp.h>
#include <uvw/timer.h>
#include <dm-tcp-bridge/Bridge.hpp>

namespace dm_bridge {

  class BridgeImpl final : public Bridge {
  public:
    explicit BridgeImpl(Options& opts);
    ~BridgeImpl() override;
  private:

    std::shared_ptr<uvw::loop> loop;
  };

} // dm_bridge

