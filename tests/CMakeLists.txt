cmake_minimum_required(VERSION 3.12)

# Add the test executable
add_executable(thales_tests test_main.cpp)

# Link the test executable with the necessary libraries
target_link_libraries(thales_tests PRIVATE
    utils
    GTest::gtest
    GTest::gtest_main
    CURL::libcurl
)

# Include the necessary directories for the test executable
target_include_directories(thales_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# Add the test command
add_test(NAME thales_tests COMMAND thales_tests)
