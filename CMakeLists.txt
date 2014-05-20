cmake_minimum_required(VERSION 2.8)

find_package(Boost 1.53.0 REQUIRED system thread)

find_package(Qt4 REQUIRED QtCore QtGui)
include(${QT_USE_FILE})

find_package(Java)
include(UseJava)

message(STATUS "java status ${Java_FOUND}")

find_package(JNI)
if(JNI_FOUND)
    include_directories(${JNI_INCLUDE_DIRS})
endif()

add_definitions(-std=c++11)

add_subdirectory(modules)
add_subdirectory(apps)