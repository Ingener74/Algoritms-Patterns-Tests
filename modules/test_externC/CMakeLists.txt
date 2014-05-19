cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME test_externC)
project(${PROJECT_NAME})

set(SOURCES
    src/Test.cpp
)
add_library(${PROJECT_NAME} SHARED ${SOURCES})

set(LIBS
)
target_link_libraries(${PROJECT_NAME} ${LIBS})