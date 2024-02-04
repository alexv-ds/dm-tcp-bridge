#include <uuid_v4.h>
#include <dm-tcp-bridge/IdGenerator_UUIDv4.hpp>

namespace dm_bridge { 

  std::string IdGenerator_UUIDv4::generate() {
    thread_local UUIDv4::UUIDGenerator<std::mt19937_64> uuid_generator;
    return uuid_generator.getUUID().str();
  }

}