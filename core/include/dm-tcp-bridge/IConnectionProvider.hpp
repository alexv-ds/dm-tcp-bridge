#pragma once
#include <functional>
#include <memory>
#include "IConnection.hpp"

namespace dm_bridge {

  class IConnectionProvider {
  public:
    using on_new_connection_cb = std::function<void(std::shared_ptr<IConnection>)>;

    virtual void connect_on_new_connection(on_new_connection_cb&&) = 0;
    virtual void disconnect_on_new_connection() noexcept = 0;
  };

} // dm_bridge