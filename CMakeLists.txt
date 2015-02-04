cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")

option(WITH_JAVA "Compile Java parts" OFF)
option(WITH_GUI  "Compile GUI parts(Qt/FLTK)" OFF)
option(WITH_SWIG "Compile python test wrapper" OFF)

# find boost
set(Boost_USE_STATIC_LIBS    ON)
set(Boost_USE_MULTITHREADED  ON)
if(MINGW)
    set(Boost_COMPILER -mgw48)
else(MINGW)
    set(Boost_COMPILER -gcc)
endif(MINGW)
find_package(Boost 1.53.0 REQUIRED system thread)

if(WITH_GUI)
    find_package(Qt4 REQUIRED QtCore QtGui)
    include(${QT_USE_FILE})
    
    find_package(FLTK)
    if(FLTK_FOUND)
        include_directories(${FLTK_INCLUDE_DIR})
    endif()
endif()

find_package(Java)
include(UseJava)

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


if(WITH_SWIG)
    find_package(SWIG)
    include(${SWIG_USE_FILE})
    
    if(SWIG_FOUND)
        include_directories(${CMAKE_CURRENT_SOURCE_DIR})
        set(CMAKE_SWIG_FLAGS "")
    endif()
endif()

add_definitions(-std=c++11)

include_directories(
    modules/test_externC/src
    modules/test_jni/src
)

add_subdirectory(modules)
add_subdirectory(apps)
