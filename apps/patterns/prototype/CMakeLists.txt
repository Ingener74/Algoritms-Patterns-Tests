cmake_minimum_required(VERSION 2.8)

add_executable(prototype main.cpp)
target_link_libraries(prototype ${Boost_LIBRARIES})