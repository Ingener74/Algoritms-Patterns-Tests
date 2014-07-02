/*
 * main.cpp
 *
 *  Created on: Jun 5, 2014
 *      Author: pavel
 */

#include <iostream>
#include <stdexcept>

#include <python2.7/Python.h>

using namespace std;

int main(int argc, char **argv)
{
    try
    {
        Py_SetProgramName(argv[0]);
        Py_Initialize();

        PyRun_SimpleString(""
                "print 'Python embedding test'\n"
                "");

        Py_Finalize();
    }
    catch (std::exception const & e)
    {
        cout << "error: " << e.what() << endl;
    }

    return 0;
}

