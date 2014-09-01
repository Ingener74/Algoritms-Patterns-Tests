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

        int status;
        char *realname = abi::__cxa_demangle(typeid(t).name(), 0, 0, &status);
        std::cout << "real test name " << realname << endl;
        free(realname);

    } catch (exception const & e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

