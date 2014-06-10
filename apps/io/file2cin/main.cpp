/*
 * main.cpp
 *
 *  Created on: Jun 10, 2014
 *      Author: pavel
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    try
    {
        cout << "before redirection" << endl;

        ifstream file;
        file.open("file2cin", ios::in);

        streambuf* temp = cin.rdbuf();

        cin.rdbuf(file.rdbuf());

        for(string line; cin >> line;){
            cout << line << endl;
        }

        cout.rdbuf(temp);
    }
    catch (exception const & e)
    {
        cout << "error: " << e.what() << endl;
    }
    return 0;
}

