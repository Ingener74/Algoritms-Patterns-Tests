cmake_minimum_required(VERSION 2.8)

add_executable(embed_lua_001 main.cpp)
target_link_libraries(embed_lua_001 ${LUA_LIBRARIES})