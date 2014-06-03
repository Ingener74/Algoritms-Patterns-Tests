cmake_minimum_required(VERSION 2.8)

project(lcm_generator)
add_executable(lcm_generator main.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--no-as-needed")
target_link_libraries(lcm_generator pthread)