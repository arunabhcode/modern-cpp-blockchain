cmake_minimum_required(VERSION 3.5)
project(unit-test)

add_executable(test_codec test_codec.cpp)
target_link_libraries(test_codec PUBLIC gtest gtest_main mcb)
gtest_discover_tests(test_codec)
