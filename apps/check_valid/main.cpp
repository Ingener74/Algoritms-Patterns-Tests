/*
 * main.cpp
 *
 *  Created on: Aug 4, 2014
 *      Author: pavel
 */

#include <iostream>
#include <stdexcept>

#include <typeinfo>

using namespace std;

string backtrace()
{
    return "";
}
template <typename T>
T* check_valid( T* a )
{
    if ( a == nullptr ) throw runtime_error(
            string("check_valid\n") + typeid(T).name() + " * == nullptr\n" + backtrace());
    return a;
}

int main( int argc, char **argv )
{
    try
    {
        cout << "check valid" << endl;

        int a1 = 0;
        int * a2 = check_valid(&a1);

        int * a3 = nullptr;
        int * a4 = check_valid(a3);
    }
    catch ( exception const & e )
    {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

