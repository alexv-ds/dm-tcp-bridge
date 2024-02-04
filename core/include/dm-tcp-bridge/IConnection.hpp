#pragma once
#include <functional>
#include <nlohmann/json.hpp>
#include "IRequest.hpp"

namespace dm_bridge {

  class IConnection {
  public:
    using json = nlohmann::json;
    using on_msg_cb = std::function<void(std::unique_ptr<IRequest>&&, IConnection&)>;
    using on_error_cb = std::function<void(const std::string&, IConnection&)>;
    using on_close_cb = std::function<void(IConnection&)>;

    virtual void send(std::unique_ptr<IRequest>&&) = 0;

    virtual void connect_on_request(on_msg_cb&&) = 0;
    virtual void connect_on_error(on_error_cb&&) = 0;
    virtual void connect_on_close(on_close_cb&&) = 0;

    virtual void disconnect_on_request() noexcept = 0;
    virtual void disconnect_on_error() noexcept = 0;
    virtual void disconnect_on_close() noexcept = 0;

    inline void disconnect_all() noexcept;

    virtual bool is_closed() const noexcept = 0;
    virtual void close() noexcept = 0;
  };

  inline void IConnection::disconnect_all() noexcept {
    this->disconnect_on_request();
    this->disconnect_on_error();
    this->disconnect_on_close();
  }

} //dm_bridge