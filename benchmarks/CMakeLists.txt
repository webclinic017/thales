cmake_minimum_required(VERSION 3.12)

# Add the benchmark executable
add_executable(thales_benchmarks
    benchmark_main.cpp
    # Add other benchmark source files here
)

# Link the benchmark executable with the necessary libraries
target_link_libraries(thales_benchmarks PRIVATE
    utils
    config
    benchmark::benchmark
    benchmark::benchmark_main
    CURL::libcurl
)

# Include the necessary directories for the benchmark executable
target_include_directories(thales_benchmarks PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
