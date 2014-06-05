cmake_minimum_required(VERSION 2.8)

find_package(Boost 1.53.0 REQUIRED system thread)

find_package(Qt4 REQUIRED QtCore QtGui)
include(${QT_USE_FILE})

find_package(Java)
include(UseJava)

find_package(JNI)

find_package(PythonLibs)

include_directories(
    ${JNI_INCLUDE_DIRS}
    ${PYTHON_INCLUDE_DIRS}
)

add_definitions(-std=c++11)

add_subdirectory(modules)
add_subdirectory(apps)