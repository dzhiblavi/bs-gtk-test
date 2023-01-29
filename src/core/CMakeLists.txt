add_library(core.compiler_LIBRARY INTERFACE)
add_library(core::compiler ALIAS core.compiler_LIBRARY)
target_sources(core.compiler_LIBRARY INTERFACE compiler.h)

add_library(core.logging_LIBRARY STATIC)
add_library(core::logging ALIAS core.logging_LIBRARY)
target_sources(core.logging_LIBRARY PRIVATE logging.cpp)
target_link_libraries(core.logging_LIBRARY PUBLIC glog::glog)
