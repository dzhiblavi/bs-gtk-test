find_package(benchmark REQUIRED)

add_executable(
	benchmarks
	benchmark_main.cpp
)

target_link_libraries(
	benchmarks
	benchmark::benchmark
)
