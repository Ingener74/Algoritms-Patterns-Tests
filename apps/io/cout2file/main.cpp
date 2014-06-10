/*
 * main.cpp
 *
 *  Created on: Jun 10, 2014
 *      Author: pavel
 */

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

int main(int argc, char **argv)
{
    try
    {
        cout << "before redirection" << endl;

        fstream file("cout2file", ios::out);

        streambuf* temp = cout.rdbuf();

        cout.rdbuf(file.rdbuf());

        cout << "after redirection" << endl;

        cout.rdbuf(temp);
    }
    catch (exception const & e)
    {
        cout << "error: " << e.what() << endl;
    }
    return 0;
}

