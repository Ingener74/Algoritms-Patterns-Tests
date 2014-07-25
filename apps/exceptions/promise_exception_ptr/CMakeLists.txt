cmake_minimum_required(VERSION 2.8)

add_executable(promise_exception_ptr main.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--no-as-needed")
target_link_libraries(promise_exception_ptr pthread)