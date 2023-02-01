cc_library(
  NAME app-ag
  ALIAS app::ag
  TYPE STATIC
  SRCS
    ag_entry.cpp
    ag_search.cpp
  DEPS
    core::logging
  SYSTEM
    Boost::filesystem
)

add_subdirectory(test)
