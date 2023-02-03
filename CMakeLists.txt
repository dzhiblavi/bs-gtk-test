cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(
  cpp_gtk
  VERSION 0.1
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a" ".so")

include(third_party/module.cmake)
include(cmake/module.cmake)

add_subdirectory(src)
