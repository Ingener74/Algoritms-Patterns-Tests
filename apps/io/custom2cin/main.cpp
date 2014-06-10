/*
 * main.cpp
 *
 *  Created on: Jun 10, 2014
 *      Author: pavel
 */

#include <iostream>
#include <fstream>

using namespace std;

class CustomStreamBuf: public std::streambuf
{
public:
    CustomStreamBuf(const string& file)
    {
        _file.open(file.c_str(), ios::in);
    }
    virtual ~CustomStreamBuf()
    {
        _file.close();
    }

    virtual int_type underflow()
    {
//        cout << "underflow" << endl;
        return _file.get();
//        return traits_type::eof();
    }

    virtual int_type overflow(int_type c = traits_type::eof())
    {
        cout << "overflow " << c << endl;
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

        CustomStreamBuf csb("file2cin");

        streambuf* temp = cin.rdbuf();

        cin.rdbuf(&csb);

        for (string line; cin >> line;)
        {
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

