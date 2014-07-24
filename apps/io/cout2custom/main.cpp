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

class printf_buffer: public streambuf
{
public:
    printf_buffer() :
            streambuf(), _buffer(1024)
    {
        setp(&_buffer.front(), &_buffer.back() + 1);
    }
    virtual ~printf_buffer()
    {
    }

    /*
    virtual streamsize xsputn( const char_type* __s, streamsize __n )
    {
        if ( (epptr() - pptr()) >= __n )
        {
            memcpy(pptr(), __s, __n);
            pbump(__n);
        }
        else
        {
            sync();
            xsputn(__s, __n);
        }
        return __n;
    }
    */

    virtual int sync()
    {
        printf("%s", pbase());
        pbump(-(pptr() - pbase()));
        for ( auto &b : _buffer )
        {
            b = 0;
        }
        return 0;
    }
private:
    vector<char> _buffer;
};

int main( int argc, char **argv )
{
    try
    {
        cout << "before redirection" << endl;

        printf_buffer csb;

        streambuf* temp = cout.rdbuf();

        cout.rdbuf(&csb);

        cout << "after redirection " << 100.4 << " bla " << 100500 << endl;

        cout.rdbuf(temp);
    }
    catch ( exception const & e )
    {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}

