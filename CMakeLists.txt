cmake_minimum_required(VERSION 2.8)

find_package(Boost 1.53.0 REQUIRED system thread)

find_package(Qt4 REQUIRED QtCore QtGui)
include(${QT_USE_FILE})

add_definitions(-std=c++11)

add_subdirectory(apps)
