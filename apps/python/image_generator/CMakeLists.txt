cmake_minimum_required(VERSION 2.8)

set(LIBRARY_NAME imagegen)

include_directories(.)

if(MINGW)
else()
    add_definitions(-fPIC)
endif()

add_library(${LIBRARY_NAME} ImageGenerator.cpp)

set(SWIG_FILE imagegen.i) 
set(SWIG_MODULE imagegen)

SET_SOURCE_FILES_PROPERTIES(${SWIG_FILE} PROPERTIES CPLUSPLUS ON)
SET_SOURCE_FILES_PROPERTIES(${SWIG_FILE} PROPERTIES SWIG_FLAGS "-includeall")
SWIG_ADD_MODULE(${SWIG_MODULE} python ${SWIG_FILE})
SWIG_LINK_LIBRARIES(${SWIG_MODULE} ${PYTHON_LIBRARIES} ${LIBRARY_NAME})
