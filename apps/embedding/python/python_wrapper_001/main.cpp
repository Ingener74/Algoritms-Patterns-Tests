#include <iostream>

#include <python2.7/Python.h>

using namespace std;

static PyObject* foo_add(PyObject* self, PyObject* args)
{
    int a, b;
    if (!PyArg_ParseTuple(args, "ii", &a, &b))
    {
        return nullptr;
    }
    return Py_BuildValue("i", 10);
}

static PyMethodDef method[] = {
        {"add", foo_add, METH_VARARGS, "method for adding two numbers"},
        {nullptr, nullptr, 0, nullptr},
};

PyMODINIT_FUNC initfoo(){
    Py_InitModule3("foo", method, "my first extension module");
}
