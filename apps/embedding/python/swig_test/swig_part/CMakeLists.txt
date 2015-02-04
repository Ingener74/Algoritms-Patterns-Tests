cmake_minimum_required(VERSION 2.8)

add_definitions(-fPIC)
add_library(shapes ../cpp_c_part/shapes.cpp)

SET_SOURCE_FILES_PROPERTIES(shapes.i PROPERTIES CPLUSPLUS ON)
SET_SOURCE_FILES_PROPERTIES(shapes.i PROPERTIES SWIG_FLAGS "-includeall")
SWIG_ADD_MODULE(shapes python shapes.i)
SWIG_LINK_LIBRARIES(shapes ${PYTHON_LIBRARIES} shapes)
