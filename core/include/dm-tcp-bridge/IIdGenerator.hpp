#pragma once 
#include <string>

namespace dm_bridge {
  class IIdGenerator {
    virtual std::string generate() = 0;
  };
}