cmake_minimum_required(VERSION 2.8)

find_package(Boost 1.53.0 REQUIRED system thread)

add_definitions(-std=c++11)

add_subdirectory(apps)
