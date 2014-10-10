cmake_minimum_required(VERSION 2.8)

add_executable(sfinae_settings_getter main.cpp)
target_link_libraries(sfinae_settings_getter boost_system)
