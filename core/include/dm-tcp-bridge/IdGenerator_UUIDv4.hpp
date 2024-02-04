#pragma once
#include <atomic>
#include <random>
#include <array>
#include <algorithm>
#include <cstddef>
#include "IIdGenerator.hpp"

namespace dm_bridge {

  class IdGenerator_UUIDv4 final : public IIdGenerator {
  public:
    std::string generate() override; ///!< thread safe    
  };
}