cmake_minimum_required(VERSION 2.8)

include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(test0001)

add_subdirectory(test_boost_asio)

add_subdirectory(tests)

add_subdirectory(patterns)

add_subdirectory(MyQt)