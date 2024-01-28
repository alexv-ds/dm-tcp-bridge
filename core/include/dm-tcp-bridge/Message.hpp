#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace dm_bridge {

  struct Message {
    using json = nlohmann::json;

    std::string id;
    std::string method;
    json params;
  };

} // dm_bridge
