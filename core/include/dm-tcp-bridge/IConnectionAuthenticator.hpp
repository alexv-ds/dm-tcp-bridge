#pragma once
#include <memory>
#include <functional>
#include "IConnection.hpp"


namespace dm_bridge {

  class IConnectionAuthenticator {
  public:
    using on_accept_cb = std::function<void(std::shared_ptr<IConnection>&&)>;
    using on_reject_cb = std::function<void(const std::string& reason, std::shared_ptr<IConnection>&&)>;
    using on_error_cb = std::function<void(const std::string& what, std::shared_ptr<IConnection>&&)>;

    virtual void authenticate(std::shared_ptr<IConnection>&& conn) = 0;
    
    virtual void connect_on_accept(on_accept_cb&&) = 0;
    virtual void connect_on_reject(on_reject_cb&&) = 0;
    virtual void connect_on_error(on_error_cb&&) = 0;
    virtual void disconnect_on_accept() noexcept = 0;
    virtual void disconnect_on_reject() noexcept = 0;
    virtual void disconnect_on_error() noexcept = 0;
    
    inline void disconnect_all() noexcept;
  };

  inline void IConnectionAuthenticator::disconnect_all() noexcept {
    this->disconnect_on_accept();
    this->disconnect_on_reject();
    this->disconnect_on_error();
  }

} // dm_bridge