/*
 * main.cpp
 *
 *  Created on: Jul 18, 2014
 *      Author: pavel
 */

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <typeinfo>

#include <cxxabi.h>

using namespace std;

template<typename T>
string typeName(const T& obj)
{
    int status;
    char *realname = abi::__cxa_demangle(typeid(obj).name(), 0, 0, &status);
    string res(realname);
    free(realname);
    return res;
}

int main(int argc, char **argv)
{
    try
    {
        class Test
        {
        public:
            Test()
            {
            }
            virtual ~Test()
            {
            }
        };

        Test t;

        cout << "test name " << typeid(t).name() << endl;

        cout << "real test name " << typeName(t) << endl;
    }
    catch (exception const & e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

