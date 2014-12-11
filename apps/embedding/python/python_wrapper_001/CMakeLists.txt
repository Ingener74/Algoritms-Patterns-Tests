cmake_minimum_required(VERSION 2.8)

add_library(python_wrapper_001 SHARED main.cpp)
target_link_libraries(python_wrapper_001 ${PYTHON_LIBRARIES})
