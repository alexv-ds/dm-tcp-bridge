#pragma once

#include <memory>
#include <cstdint>
#include <numeric>
#include <vector>
#include "Connection.hpp"

namespace dm_bridge {
  class Bridge : public std::enable_shared_from_this<Bridge> {
  public:
    struct Options;

    static std::shared_ptr<Bridge> create(const Options& opts);

    virtual void get_all_connections(std::vector<std::shared_ptr<Connection>>& connections) = 0;

    virtual std::shared_ptr<Connection> get_connection(const std::string& id) = 0;

    Bridge() = default;

    Bridge(const Bridge&) = delete;

    Bridge& operator=(const Bridge&) = delete;

    virtual ~Bridge() = default;
  };

  ////////////////
  struct Bridge::Options {
    std::string ip = "0.0.0.0";
    std::string auth_token;
    std::uint16_t max_connections = std::numeric_limits<decltype(max_connections)>::max();
    std::uint16_t message_queue_size = 20;
  };
}


