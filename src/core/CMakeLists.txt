add_library(libcore-compiler INTERFACE)
add_library(core::compiler ALIAS libcore-compiler)

target_sources(
  libcore-compiler INTERFACE
  compiler.h
)

add_library(libcore-logging STATIC)
add_library(core::logging ALIAS libcore-logging)

target_sources(
  libcore-logging PRIVATE
  logging.cpp
)
target_sources(
  libcore-logging INTERFACE
  logging.h
)
target_link_libraries(
  libcore-logging PUBLIC
  glog::glog
  core::compiler
)
