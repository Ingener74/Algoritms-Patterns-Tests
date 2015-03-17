cmake_minimum_required(VERSION 2.8)

add_subdirectory(py_embedding_001)
# add_subdirectory(py_embedding_002)

add_subdirectory(python_wrapper_001)

include_directories(swig_test/cpp_c_part)

if(WITH_SWIG AND SWIG_FOUND)
    add_subdirectory(swig_test/swig_part)
endif()
