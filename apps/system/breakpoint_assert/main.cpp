/*
 * main.cpp
 *
 *  Created on: Jan 28, 2015
 *      Author: pavel
 */

#include <iostream>

using namespace std;

#define ASSERT(condition) if(!condition) __asm__("int $3");

int main(int argc, char **argv)
{
    try
    {
        ASSERT(false);
    }
    catch (exception const & e)
    {
        cerr << e.what() << endl;
    }
}

