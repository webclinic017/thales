cmake_minimum_required(VERSION 3.12)

# Add the test executable
add_executable(thales_tests test_black_scholes.cpp)

# Link the test executable with the necessary libraries
target_link_libraries(thales_tests PRIVATE
    shared_code
    utils
    config
    GTest::GTest
    GTest::Main
    CURL::libcurl
    Threads::Threads
)

# Include the necessary directories for the test executable
target_include_directories(thales_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/trading
)

# Add the test command
add_test(NAME TestBlackScholes COMMAND thales_tests)
