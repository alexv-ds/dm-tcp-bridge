
add_library(${PROJECT_NAME}-core STATIC
  src/Connection.cpp
  include/dm-tcp-bridge/Connection.hpp
  include/dm-tcp-bridge/Bridge.hpp
  include/dm-tcp-bridge/Message.hpp
  src/Bridge.cpp
  src/BridgeImpl.cpp
  src/BridgeImpl.hpp
)
target_include_directories(${PROJECT_NAME}-core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(${PROJECT_NAME}::core ALIAS ${PROJECT_NAME}-core)

target_compile_options(${PROJECT_NAME}-core PRIVATE
  $<IF:$<CXX_COMPILER_ID:MSVC>,/W4,-Wall -Wextra -Wpedantic>
)

CPMAddPackage(
  NAME json
  VERSION 3.11.3
  URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
  URL_HASH SHA3_256=27fefc76c69854ef6c604350871859e586bda6199c557dcaa51b9849becd4c4b
  OPTIONS
  "JSON_BuildTests OFF"
  "JSON_SystemInclude ON"
)
target_link_libraries(${PROJECT_NAME}-core PUBLIC nlohmann_json::nlohmann_json)

CPMAddPackage(
  NAME libuv
  VERSION 1.46.0
  URL https://github.com/libuv/libuv/archive/refs/tags/v1.47.0.tar.gz
  URL_HASH SHA3_256=a7499acafe8ff368fb525459b9e02ca7c994a70acd7c31411537b10ec0c3b3d4
  OPTIONS
  "LIBUV_BUILD_SHARED OFF"
  "LIBUV_BUILD_TESTS OFF"
  "LIBUV_BUILD_BENCH OFF"
  "QEMU OFF"
  "ASAN OFF"
  "MSAN OFF"
  "TSAN OFF"
  "UBSAN OFF"
)
target_link_libraries(${PROJECT_NAME}-core PRIVATE uv_a)

CPMAddPackage(
  NAME uvw
  VERSION 3.2.0
  URL https://github.com/skypjack/uvw/archive/refs/tags/v3.2.0_libuv_v1.46.tar.gz
  URL_HASH SHA3_256=0b82039ac6fcff490caeb85b77408eb925146690cb812c4e9303757263d8ce12
  OPTIONS
  "USE_LIBCPP OFF"
  "USE_ASAN OFF"
  "USE_UBSAN OFF"
  "BUILD_UVW_LIBS OFF"
  "BUILD_UVW_SHARED_LIB OFF"
  "FIND_LIBUV OFF"
)
target_link_libraries(${PROJECT_NAME}-core PRIVATE uvw::uvw)

CPMAddPackage(
  NAME uvw
  VERSION 3.2.0
  URL https://github.com/skypjack/uvw/archive/refs/tags/v3.2.0_libuv_v1.46.tar.gz
  URL_HASH SHA3_256=0b82039ac6fcff490caeb85b77408eb925146690cb812c4e9303757263d8ce12
  OPTIONS
  "USE_LIBCPP OFF"
  "USE_ASAN OFF"
  "USE_UBSAN OFF"
  "BUILD_UVW_LIBS OFF"
  "BUILD_UVW_SHARED_LIB OFF"
  "FIND_LIBUV OFF"
)
target_link_libraries(${PROJECT_NAME}-core PRIVATE uvw::uvw)

CPMAddPackage(
  NAME concurrentqueue
  VERSION 1.0.4
  URL https://github.com/cameron314/concurrentqueue/archive/refs/tags/v1.0.4.tar.gz
  URL_HASH SHA3_256=4ed9f2b413939ec3cee40cbccd1353e071efa964ae2a8f494df61ad2c80dfb1f
)
target_link_libraries(${PROJECT_NAME}-core PRIVATE concurrentqueue)