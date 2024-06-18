cmake_minimum_required(VERSION 3.12)
project(thales)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable AddressSanitizer
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address")

# Find dependencies
find_package(Threads REQUIRED)
find_package(CURL REQUIRED)
find_package(GTest REQUIRED)
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
    src/trading/portfolio.cpp
    src/trading/order.cpp
    src/trading/position.cpp
)
target_include_directories(shared_code PUBLIC include include/trading)
target_link_libraries(shared_code PRIVATE utils config)

# Main executable
add_executable(thales
    src/main.cpp
)
target_link_libraries(thales PRIVATE shared_code utils config)

# Tests
enable_testing()

# Black Scholes tests
add_executable(test_black_scholes
    tests/test_black_scholes.cpp
)
target_link_libraries(test_black_scholes PRIVATE shared_code utils config GTest::GTest GTest::Main CURL::libcurl Threads::Threads)
add_test(NAME TestBlackScholes COMMAND test_black_scholes)

# Portfolio tests
add_executable(test_portfolio
    tests/test_portfolio.cpp
)
target_link_libraries(test_portfolio PRIVATE shared_code utils config GTest::GTest GTest::Main CURL::libcurl Threads::Threads)
add_test(NAME TestPortfolio COMMAND test_portfolio)

# Combined benchmarks
add_executable(thales_benchmarks
    benchmarks/benchmark_main.cpp
    benchmarks/benchmark_black_scholes.cpp
    benchmarks/benchmark_portfolio.cpp
)
target_link_libraries(thales_benchmarks PRIVATE shared_code utils config benchmark::benchmark Threads::Threads)

# Installation
install(TARGETS thales DESTINATION bin)
install(DIRECTORY include/ DESTINATION include/thales)
