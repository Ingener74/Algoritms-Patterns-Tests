/*
 * main.cpp
 *
 *  Created on: Jun 5, 2014
 *      Author: pavel
 */

#include <string>
#include <iostream>
#include <stdexcept>

#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>
#include <lua5.1/lualib.h>

using namespace std;

int main(int argc, char **argv)
{
    try
    {
        cout << "Lua embedding tests" << endl;

        lua_State *L = lua_open();

        string text = ""
                "local function main()"
                "   print('Lua test')"
                "end"
                "main()";

        luaopen_io(L);
        luaopen_base(L);
        luaopen_table(L);
        luaopen_string(L);
        luaopen_math(L);

        int res = luaL_loadstring(L, text.c_str());
        if (!res)
        {
            res = lua_pcall(L, 0, LUA_MULTRET, 0);
        }

        lua_close(L);

        return EXIT_SUCCESS;
    }
    catch (std::exception const & e)
    {
        cout << "error: " << e.what() << endl;
    }
    return EXIT_FAILURE;
}

