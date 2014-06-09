/*
 * main.cpp
 *
 *  Created on: Jun 9, 2014
 *      Author: ingener
 */

#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

class Exception
{
public:
    Exception() :
            _cond(true)
    {
    }
    Exception(bool condition) :
            _cond(condition)
    {
    }
    virtual ~Exception()
    {
    }

    template<typename T>
    Exception& operator<<(const T& other)
    {
        _s << other;
        return *this;
    }

    Exception& operator<<(const Exception&)
    {
        if (_cond) throw runtime_error(_s.str());
        return *this;
    }

private:
    stringstream _s;
    bool _cond;
};

int main(int argc, char **argv)
{
    try
    {
        cout << "before test exception" << endl;

        Exception(5 > 1) << "Test exception " << 3.1415 << Exception();

        cout << "after test exception" << endl;
    }
    catch (exception const & e)
    {
        cerr << "error: " << e.what() << endl;
    }
    return 0;
}

