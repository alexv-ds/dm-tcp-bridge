#pragma once

#include <string>
#include <vector>
#include <memory>
#include <nlohmann/json.hpp>
#include "Message.hpp"

namespace dm_bridge {
  class Connection : std::enable_shared_from_this<Connection> {
    using json = nlohmann::json;
  public:
    /**
     * Gets the connection ID
     * @multithreading{Thread-safe}
     */
    inline const std::string& id() const noexcept;

    /**
     * Sends a message. This is a non-blocking call.
     * @multithreading{Thread-safe}
     */
    virtual void send(const Message& message) = 0;

    /**
     * Receives messages. This is a non-blocking call.
     * If there are no new messages, then nothing is written to "messages".
     * @multithreading{Thread-safe}
     */
    virtual void recv(std::vector<Message>& messages) = 0;

    Connection(const Connection&) = delete;

    Connection& operator=(const Connection&) = delete;

    virtual ~Connection() = default;

  protected:
    const std::string id_;
  };

  /////////////////////
  inline const std::string& Connection::id() const noexcept {
    return id_;
  }

} // dm_bridge


