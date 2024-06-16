cmake_minimum_required(VERSION 3.12)
add_executable(thales_benchmarks benchmark_main.cpp)
target_link_libraries(thales_benchmarks PRIVATE benchmark::benchmark)
