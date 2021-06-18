cmake_minimum_required(VERSION 3.5)
project(unit-test)

add_executable(test_codec test_codec.cpp)
target_link_libraries(test_codec PUBLIC gtest gtest_main mcb)
gtest_discover_tests(test_codec)

add_executable(test_db test_db.cpp)
target_link_libraries(test_db PUBLIC gtest gtest_main mcb)
gtest_discover_tests(test_db)
