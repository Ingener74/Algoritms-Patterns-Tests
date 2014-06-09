/*
 * main.cpp
 *
 *  Created on: Jun 5, 2014
 *      Author: pavel
 */

#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include <lua.hpp>

using namespace std;

/*
 * helpful
 *
 * * https://code.google.com/p/zester/wiki/Lua_C
 * * http://lua-users.org/wiki/BindingCodeToLua
 */

extern "C"
{

    static int l_testMul2Pi(lua_State* L)
    {
        double t = lua_tonumber(L, 1);
        lua_pushnumber(L, t * 3.141592);
        return 1;
    }

    static int l_testString(lua_State* L){
        lua_pushstring(L, "This string returned from C function");
        return 1;
    }

    static int l_new_print(lua_State* L){

        for(int i = 1; i < lua_gettop(L) + 1; ++i){
            cout << lua_tostring(L, i);
        }
        cout << endl;
        return 0;
    }

}

int getB(lua_State* L)
{
    lua_getglobal(L, "testGetFromLua");
    lua_pcall(L, 0, 1, 0);

    int res = lua_tointeger(L, -1);
    lua_pop(L, 1);

    return res;
}
void setB(lua_State* L, int b)
{
    lua_getglobal(L, "testSetInLua");
    lua_pushnumber(L, b);
    lua_call(L, 1, 0);
}

void printB(lua_State* L)
{
    lua_getglobal(L, "printB");
    lua_call(L, 0, 0);
}

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2) throw runtime_error(
                "\nUsage: ./embed_lua <path-to-lua-script>");

        cout << "Lua embedding tests" << endl << endl;

        lua_State *L = luaL_newstate();
        luaL_openlibs(L);

        fstream file(argv[1]);
        string text((std::istreambuf_iterator<char>(file)),
                std::istreambuf_iterator<char>());

        lua_register(L, "testMul2Pi", l_testMul2Pi);
        lua_register(L, "testString", l_testString);
        lua_register(L, "new_print", l_new_print);

        int res = luaL_loadstring(L, text.c_str());
        if (!res)
        {
            res = lua_pcall(L, 0, 0, 0);
        }

        lua_getglobal(L, "testLuaFunc");
        lua_pcall(L, 0, 0, 0);

        printB(L);
        cout << "b = " << getB(L) << endl;
        setB(L, 72);
        printB(L);
        cout << "b = " << getB(L) << endl;

        lua_close(L);

        return EXIT_SUCCESS;
    }
    catch (std::exception const & e)
    {
        cout << "error: " << e.what() << endl;
    }
    return EXIT_FAILURE;
}

