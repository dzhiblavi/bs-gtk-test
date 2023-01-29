project(cpp-gtk LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a" ".so")

if(MSVC)
  add_compile_options(/W3 /WX)
else()
  add_compile_options(-W -Wall -Werror)
endif()

find_package(
  PkgConfig REQUIRED
)
find_package(
  glog REQUIRED
)
find_package(
  Boost 1.76 COMPONENTS
  filesystem
  program_options
  timer
  thread
  REQUIRED
)

## For generated files (protobuf etc.)
#include_directories(${CMAKE_BINARY_DIR})

add_subdirectory(third_party)
add_subdirectory(src)
