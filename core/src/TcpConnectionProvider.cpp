#include <dm-tcp-bridge/TcpConnectionProvider.hpp>

namespace dm_bridge {

  TcpConnectionProvider::TcpConnectionProvider(Settings&& settings, std::shared_ptr<uvw::loop>&&) {

  }

  void TcpConnectionProvider::connect_on_new_connection(on_new_connection_cb&& cb) {
    this->connection_cb = std::move(cb);
  }

  void TcpConnectionProvider::disconnect_on_new_connection() noexcept {
    this->connection_cb = nullptr;
  }
}