enable_testing()

add_executable(
  test_ag_search
  ag_search_test.cpp
)
target_link_libraries(
  test_ag_search PRIVATE
  app::ag
  pthread
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_ag_search)
