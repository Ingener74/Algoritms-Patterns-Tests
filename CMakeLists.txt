cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")

find_package(Boost 1.53.0 REQUIRED system thread)

find_package(Qt4 REQUIRED QtCore QtGui)
include(${QT_USE_FILE})

find_package(Java)
include(UseJava)

option(WITH_JAVA "Compile Java parts" OFF)

find_package(JNI)
if(JNI_FOUND)
    include_directories(${JNI_INCLUDE_DIRS})
endif()

find_package(PythonLibs)
if(PYTHONLIBS_FOUND)
    include_directories(${PYTHON_INCLUDE_DIRS})
endif()

find_package(Lua)
if(LUA_FOUND)
    include_directories(${LUA_INCLUDE_DIR})
endif()

find_package(FLTK)
if(FLTK_FOUND)
    include_directories(${FLTK_INCLUDE_DIR})
endif()

add_definitions(-std=c++11)

add_subdirectory(modules)
add_subdirectory(apps)