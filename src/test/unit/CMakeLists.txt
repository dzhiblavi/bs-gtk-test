find_package(GTest REQUIRED)

add_executable(
	unit_tests
	unit_tests_main.cpp
	test.cpp
)

target_link_libraries(
	unit_tests
	pthread
	glog::glog
	GTest::GTest
)
