/*
 * main.cpp
 *
 *  Created on: Jun 30, 2014
 *      Author: ingener
 */

#include <iostream>

using namespace std;

template<typename T>
void bar(T t)
{
    cout << t << endl;
}

template<typename... Args>
void foo(Args... args)
{
    cout << "foo size of argumens " << sizeof...(args) << endl;
    bar (args)...;
}

int main(int argc, char **argv)
{
try
{
    foo(2.3, "Test variadic", 123);
}
catch (exception const & e)
{
    cerr << "Error: " << e.what() << endl;
}
return 0;
}

