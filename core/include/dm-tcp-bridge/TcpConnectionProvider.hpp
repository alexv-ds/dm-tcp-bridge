#pragma once
#include <limits>
#include <cstdint>
#include <uvw/loop.h>
#include <uvw/tcp.h>
#include <uvw/timer.h>
#include "IConnectionProvider.hpp"

namespace dm_bridge {

  class TcpConnectionProvider final : public IConnectionProvider {
  public:
    struct Settings;

    TcpConnectionProvider(Settings&& settings, std::shared_ptr<uvw::loop>&&);

    void connect_on_new_connection(on_new_connection_cb&&);
    void disconnect_on_new_connection() noexcept;

  private:
    on_new_connection_cb connection_cb;
  };


  struct TcpConnectionProvider::Settings {
    std::string ip = "127.0.0.1";
    unsigned int port = 8001;
    std::uint16_t max_connections = std::numeric_limits<decltype(max_connections)>::max();
  };


}