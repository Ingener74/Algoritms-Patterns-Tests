cmake_minimum_required(VERSION 2.8)

include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(test_boost_asio)

add_subdirectory(big_alloc_test)

add_subdirectory(patterns)

add_subdirectory(MyQt)

#if(Java_FOUND)
    add_subdirectory(JavaTest)
#endif()

add_subdirectory(highload)

if(PYTHONLIBS_FOUND)
    add_subdirectory(python)
endif()

if(LUA_FOUND)
    add_subdirectory(lua)
endif()

add_subdirectory(exceptions)

add_subdirectory(io)

add_subdirectory(sorts)