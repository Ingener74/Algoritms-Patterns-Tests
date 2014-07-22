/*
 * main.cpp
 *
 *  Created on: Jul 23, 2014
 *      Author: ingener
 */

#include <execinfo.h>

#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;

string get_stack_trace()
{
    const int buffer_size = 1000;
    void *buffer[ buffer_size ];
    int n = backtrace(buffer, buffer_size);

    char** strings = backtrace_symbols(buffer, n);
    if ( strings == nullptr ) return string("i can't print stack trace");

    stringstream res;
    res << endl << "Call stack" << endl;
    for ( int i = 1; i < n; ++i )
    {
        res << i << ": " << strings[ i ] << endl;
    }
    free(strings);
    return res.str();
}

void bar()
{
    throw runtime_error("test exception " + get_stack_trace());
}

void foo()
{
    bar();
}

int main( int argc, char **argv )
{
    try
    {
        foo();
    }
    catch ( exception const & e )
    {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

