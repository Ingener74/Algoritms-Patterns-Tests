cmake_minimum_required(VERSION 2.8)

if(WITH_SWIG)
    add_subdirectory(image_generator)
    add_subdirectory(SwigTest)
endif()