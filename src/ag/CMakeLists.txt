add_library(libapp-ag STATIC)
add_library(app::ag ALIAS libapp-ag)

target_sources(
  libapp-ag PRIVATE
  ag_entry.cpp
  ag_search.cpp
)

target_link_libraries(
  libapp-ag PUBLIC
  core::logging
  Boost::boost
  Boost::filesystem
)

add_subdirectory(test)
