cmake_minimum_required(VERSION 2.8)

add_executable(fltk_test main.cpp)
target_link_libraries(fltk_test ${FLTK_LIBRARIES} dl)