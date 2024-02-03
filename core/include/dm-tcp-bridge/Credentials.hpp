#pragma once
#include <string>
#include <set>

namespace dm_bridge {

  struct Credentials {
    std::string token;
    std::set<std::string> methods;
  };


} // namespace dm_bridge