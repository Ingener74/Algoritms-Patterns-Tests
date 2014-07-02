/*
 * main.cpp
 *
 *  Created on: Jun 5, 2014
 *      Author: pavel
 */

#include <memory>
#include <iostream>
#include <stdexcept>

#include <boost/format.hpp>

#include <python2.7/Python.h>

using namespace std;
using namespace boost;

int main(int argc, char **argv)
{
    try
    {
//        shared_ptr<PyObject> name, module, dict, func;
//        shared_ptr<PyObject> args, value;
        int i;

        if (argc < 3) throw runtime_error(
                "Usage: ./py_emb_002 <python-file> <function-name> [arguments]");

        Py_Initialize();

        auto name = std::shared_ptr<PyObject>(PyString_FromString(argv[1]), [](PyObject* p)
        {
            cout << "delete name" << endl;
            Py_DECREF(p);
        });

        auto module = std::shared_ptr<PyObject>(PyImport_Import(name.get()), [](PyObject* p)
        {
            cout << "delete module" << endl;
            Py_DECREF(p);
        });

        if (!module) throw runtime_error(
                (format("can't load module %1%") % argv[1]).str());


    }
    catch (std::exception const & e)
    {
        cout << "error: " << e.what() << endl;
    }
    return 0;
}

