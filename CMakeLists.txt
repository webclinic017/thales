cmake_minimum_required(VERSION 3.12)
project(thales)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find dependencies
find_package(Threads REQUIRED)
find_package(CURL REQUIRED)

# Google Test
find_package(GTest CONFIG REQUIRED)

# Google Benchmark
find_package(benchmark CONFIG REQUIRED)

# Include directories
include_directories(
    include
    ${CURL_INCLUDE_DIRS}
    ${GTEST_INCLUDE_DIRS}
    ${BENCHMARK_INCLUDE_DIRS}
)

# Source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/*/*.cpp
)

file(GLOB_RECURSE HEADERS
    include/*.h
    include/*/*.h
)

# Main executable
add_executable(thales ${SOURCES} ${HEADERS})
target_link_libraries(thales PRIVATE
    Threads::Threads
    ${CURL_LIBRARIES}
)

# Tests
enable_testing()
add_subdirectory(tests)

# Benchmarks
add_subdirectory(benchmarks)

# Installation
install(TARGETS thales DESTINATION bin)
install(FILES ${HEADERS} DESTINATION include/thales)
