/*
 * main.cpp
 *
 *  Created on: Jun 10, 2014
 *      Author: pavel
 */

#include <vector>
#include <cstring>
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

class CustomStreamBuf: public std::streambuf
{
public:
    CustomStreamBuf(const string& fileName)
    {
        _file.open(fileName.c_str(), ios::out);
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

class PrintfBuf: public streambuf
{
public:
    PrintfBuf(): streambuf(), _buffer(1024)
	{
        setp(&_buffer.front(), &_buffer.back() + 1);
	}
	virtual ~PrintfBuf()
	{
	}

    virtual streamsize xsputn( const char_type* __s, streamsize __n )
    {
        if ( (epptr() - pptr()) >= __n )
        {
            memcpy( pptr(), __s, __n );
            pbump( __n );
        }
        else
        {
            sync();
            xsputn(__s, __n);
        }
        return __n;
    }

	virtual int sync()
	{
        printf("%s", pbase());
        pbump(-(pptr() - pbase()));
        for(auto &b: _buffer)
        {
            b = 0;
        }
		return 0;
	}
private:
	vector<char> _buffer;
};

int main(int argc, char **argv)
{
    try
    {
        cout << "before redirection" << endl;

//        CustomStreamBuf csb("cout2custom");
        PrintfBuf csb;

        streambuf* temp = cout.rdbuf();

        cout.rdbuf(&csb);

        cout << "after redirection " << 100.4 << " bla " << 100500 << endl;

        cout.rdbuf(temp);
    }
    catch (exception const & e)
    {
        cout << "error: " << e.what() << endl;
    }
    return 0;
}

