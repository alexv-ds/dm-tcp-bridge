#include <iostream>
#include <dm-tcp-bridge/IdGenerator_UUIDv4.hpp>


int main() {
  dm_bridge::IdGenerator_UUIDv4 gen;
  for (std::size_t i = 0; i < 20000000; ++i) {
    std::cout << gen.generate() << std::endl;
  }
  
}