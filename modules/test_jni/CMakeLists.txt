cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME test_jni)
project(${PROJECT_NAME})

set(SOURCES
    src/Main.cpp
)
add_library(${PROJECT_NAME} SHARED ${SOURCES})

set(LIBS
    ${JNI_LIBRARIES}
)
target_link_libraries(${PROJECT_NAME} ${LIBS})