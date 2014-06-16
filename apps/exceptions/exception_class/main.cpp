/*
 * main.cpp
 *
 *  Created on: Jun 9, 2014
 *      Author: ingener
 */

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <list>
#include <functional>
#include <binders.h>

using namespace std;

class Exception
{
public:
    using ExceptionCallback = function<void(Exception&)>;

    Exception()
    {
    }
    virtual ~Exception()
    {
    }

    Exception& operator<<(ExceptionCallback ec)
    {
        _cb.push_back(ec);
        return *this;
    }

    template<typename T>
    Exception& operator<<(const T& other)
    {
        _ << other;
        return *this;
    }

    Exception& operator<<(bool exceptionCondition)
    {
        if (exceptionCondition)
        {
            for (auto &cb : _cb)
                cb(*this);
            throw runtime_error(_.str());
        }
        return *this;
    }

private:
    stringstream _;
    list<ExceptionCallback> _cb;
};

void foo(Exception& e){
    e << "foo " << 48;
}

int main(int argc, char **argv)
{
    try
    {
        int c = 38;

        cout << "before test exception" << endl;

        Exception::ExceptionCallback ec = [&](Exception& e)
        {
            e << "i was called in exception " << c;
        };
        Exception() << "Test exception " << ec << (5 > 1);

        Exception() << "Test exception " << (5 > 1);

        cout << "after test exception" << endl;
    }
    catch (exception const & e)
    {
        cerr << "error: " << e.what() << endl;
    }
    return 0;
}

