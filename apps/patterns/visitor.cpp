/*
 * visitor.cpp
 *
 *  Created on: Oct 21, 2014
 *      Author: pavel
 */

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    try
    {
        cout << "visitor example" << endl;

        return 0;
    }
    catch (exception const & e)
    {
        cerr << e.what() << endl;
        return 1;
    }
}

