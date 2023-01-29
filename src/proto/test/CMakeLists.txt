find_package(GTest REQUIRED)

add_executable(
	test_proto
	test.cpp
)

target_link_libraries(
  test_proto PRIVATE
	pthread
  proto::msg
	glog::glog
	GTest::GTest
  GTest::Main
)
