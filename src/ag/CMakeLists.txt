add_library(app.ag_LIBRARY STATIC)
add_library(app::ag ALIAS app.ag_LIBRARY)

target_sources(
  app.ag_LIBRARY PRIVATE
  ag_entry.cpp
  ag_search.cpp
)

target_link_libraries(
  app.ag_LIBRARY PUBLIC
  core::logging
  Boost::boost
  Boost::filesystem
)

# Tests
find_package(GTest REQUIRED)

add_executable(
  ag_search_test
  test/ag_search_test.cpp
)

target_link_libraries(
  ag_search_test PRIVATE
  app::ag
  pthread
  GTest::GTest
  GTest::Main
)
