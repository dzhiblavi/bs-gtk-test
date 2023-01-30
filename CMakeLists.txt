project(cpp-gtk LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a" ".so")

include(third_party/CMakeLists.txt)
include(cmake/CMakeLists.txt)

add_subdirectory(src)
