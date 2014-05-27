cmake_minimum_required(VERSION 2.8)

project(nok_reader)
add_executable(nok_reader main.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--no-as-needed")
target_link_libraries(nok_reader pthread)