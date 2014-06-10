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

class CustomStreamBuf: public std::streambuf
{
public:
    CustomStreamBuf(const string& fileName)
    {
        _file.open(fileName, ios::out);
    }
    virtual ~CustomStreamBuf()
    {
        _file.flush();
    }

    virtual int_type
    overflow(int_type c  = traits_type::eof())
    {
        _file << static_cast<char>(c);
        return c;
    }

private:
    fstream _file;
};

int main(int argc, char **argv)
{
    try
    {
        cout << "before redirection" << endl;

        CustomStreamBuf csb("cout2custom");

        streambuf* temp = cout.rdbuf();

        cout.rdbuf(&csb);

        cout << "after redirection" << endl;

        cout.rdbuf(temp);
    }
    catch (exception const & e)
    {
        cout << "error: " << e.what() << endl;
    }
    return 0;
}

