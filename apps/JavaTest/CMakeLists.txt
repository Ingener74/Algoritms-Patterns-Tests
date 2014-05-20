cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME JavaTest)
project(${PROJECT_NAME})

add_jar(${PROJECT_NAME} 
    src/com/shnaider/Main.java
)

get_target_property(_JAR_FILE ${PROJECT_NAME} JAR_FILE)
get_target_property(_CLASSDIR ${PROJECT_NAME} CLASSDIR)

