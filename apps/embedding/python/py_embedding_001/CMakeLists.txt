cmake_minimum_required(VERSION 2.8)

add_executable(py_emb_001 main.cpp)
target_link_libraries(py_emb_001 ${PYTHON_LIBRARIES})