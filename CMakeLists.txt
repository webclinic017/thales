cmake_minimum_required(VERSION 3.12)
project(thales)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find dependencies
find_package(Threads REQUIRED)
find_package(CURL REQUIRED)

# Google Test
find_package(GTest REQUIRED)

# Google Benchmark
find_package(benchmark CONFIG REQUIRED)

# Include directories
include_directories(
    include
    include/trading
    ${CURL_INCLUDE_DIRS}
    ${BENCHMARK_INCLUDE_DIRS}
)

# Config library
add_library(config STATIC
    src/config/config.cpp
)
target_include_directories(config PUBLIC include)

# Utils library
add_library(utils STATIC
    src/utils/http_client.cpp
    src/utils/logging.cpp
)
target_include_directories(utils PUBLIC include)
target_link_libraries(utils PRIVATE
    Threads::Threads
    ${CURL_LIBRARIES}
)

# Shared library for common code
add_library(shared_code STATIC
    src/trading/black_scholes.cpp
    # Add other shared source files if needed
)
target_include_directories(shared_code PUBLIC include include/trading)
target_link_libraries(shared_code PRIVATE utils config)

# Main executable
add_executable(thales
    src/main.cpp
    # Add other source files for the 'thales' executable
)
target_link_libraries(thales PRIVATE shared_code utils config)

# Tests
enable_testing()
add_subdirectory(tests)

# Benchmarks
add_subdirectory(benchmarks)

# Installation
install(TARGETS thales DESTINATION bin)
install(DIRECTORY include/ DESTINATION include/thales)
