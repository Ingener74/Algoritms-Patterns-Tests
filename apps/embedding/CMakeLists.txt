cmake_minimum_required(VERSION 2.8)

if(PYTHONLIBS_FOUND)
    add_subdirectory(python)
endif()

if(LUA_FOUND)
    add_subdirectory(lua)
endif()
