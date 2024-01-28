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

#######

include(cmake/get_cpm.cmake)

add_subdirectory(core)