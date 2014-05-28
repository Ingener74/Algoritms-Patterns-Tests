/*
 * main.cpp
 *
 *  Created on: May 28, 2014
 *      Author: pavel
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

int main(int argc, char **argv)
{
    try
    {
        cout << "lcm generator" << endl;

        if (argc < 3) throw std::runtime_error(
                "Invalid arguments...\nUsage: ./lcm_generator <number> <file>");

        ofstream file;
        file.open(argv[2], ios::trunc);

        stringstream ss;
        ss << argv[1];
        int imax;
        ss >> imax;

        for (int i = 0; i < imax; ++i)
        {
            uint64_t random = rand()/* / RAND_MAX*/;
            file << random << endl;
        }
    }
    catch (const std::exception & e)
    {
        cout << "error: " << e.what() << endl;
    }
    return 0;
}

