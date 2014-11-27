/*
 * automatic_exception_deduction.cpp
 *
 *  Created on: Nov 26, 2014
 *      Author: pavel
 */

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void foo() throw (runtime_error)
{
    throw runtime_error{"bla bla"};

    // throw {"bla bla"}; compilation error
}

int main(int argc, char **argv)
{
    try
    {
        foo();
    }
    catch (exception const & e)
    {
        cerr << e.what() << endl;
    }
}

