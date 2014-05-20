cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME JavaTest)
project(${PROJECT_NAME})

set(CMAKE_JAVA_EXECUTABLE src/com/shnaider/Main)
add_jar(${PROJECT_NAME}
    src/com/shnaider/Main.java
    ENTRY_POINT com/shnaider/Main
)

get_target_property(_JAR_FILE ${PROJECT_NAME} JAR_FILE)
get_target_property(_CLASSDIR ${PROJECT_NAME} CLASSDIR)

