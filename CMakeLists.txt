cmake_minimum_required(VERSION 3.21)

cmake_policy(SET CMP0083 NEW)
cmake_policy(SET CMP0091 NEW)

project(dm-tcp-bridge
  VERSION 0.0.1
  LANGUAGES CXX C
  DESCRIPTION "BYOND tcp server for interprocess communication"
  HOMEPAGE_URL ""
)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds not allowed >:[")
endif()

#############################
########## OPTIONS ##########
#############################
set(BUILD_TESTING OFF CACHE BOOL "")

#############################
####### GLOBAL FLAGS ########
#############################
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_VISIBILITY_PRESET=hidden)
set(CMAKE_C_VISIBILITY_PRESET=hidden)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
add_compile_options($<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->)

set(CMAKE_C_FLAGS -m32)
set(CMAKE_CXX_FLAGS -m32)

add_compile_options(-march=native)

#######

include(cmake/get_cpm.cmake)

CPMAddPackage(
  NAME spdlog
  VERSION 1.13.0
  URL https://github.com/gabime/spdlog/archive/refs/tags/v1.13.0.tar.gz
  URL_HASH SHA3_256=5207d1b63e3c1466d30b3e28a0d7accfccad6eca283df8c04999dde9fdf3de68
  OPTIONS
  "SPDLOG_USE_STD_FORMAT ON"
  "SPDLOG_BUILD_SHARED OFF"
  "SPDLOG_ENABLE_PCH ON"
  "SPDLOG_BUILD_PIC ON"
  "SPDLOG_SYSTEM_INCLUDES ON"
)

add_subdirectory(core)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE dm-tcp-bridge::core)