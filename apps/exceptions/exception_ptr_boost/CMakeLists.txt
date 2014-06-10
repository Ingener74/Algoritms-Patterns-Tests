cmake_minimum_required(VERSION 2.8)

add_executable(exception_ptr_boost main.cpp)
target_link_libraries(exception_ptr_boost ${Boost_LIBRARIES})