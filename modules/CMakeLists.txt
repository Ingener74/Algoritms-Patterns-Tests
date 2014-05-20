cmake_minimum_required(VERSION 2.8)

add_subdirectory(test_externC)

if(JNI_FOUND)
    add_subdirectory(test_jni)
endif()