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

template<typename T, typename... Args>
struct is_callable
{
	enum
	{
		isCallable = 0
	};
};

template<typename T, typename... Args>
struct is_callable<T(Args...)>
{
	enum
	{
		isCallable = 1
	};
};

template<typename T, typename... Args>
struct is_callable<function<T(Args...)>>
{
	enum
	{
		isCallable = 1
	};
};

void bar()
{
	string	call[] {
			"not callable",
			"callable"
	};
	auto la = [](){};

	cout << "void()                       is " << call[is_callable<void()>::isCallable] << endl;
	cout << "int                          is " << call[is_callable<int>::isCallable] << endl;
	cout << "function<void(int, double)>  is " << call[is_callable<function<void(int, double)>>::isCallable] << endl;
	cout << "lambda is                    is " << call[is_callable<decltype(la)>::isCallable] << endl;
}

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
    	bar();

        int c = 38;

        cout << "before test exception" << endl;

        Exception::ExceptionCallback ec = [&](Exception& e)
        {
            e << "i was called in exception " << c;
        };

        Exception() << "Test exception " << ec
			/*[&](Exception& e)
			{
				e << "i was called in exception " << c;
			}*/ << (5 > 1);

        Exception() << "Test exception " << (5 > 1);

        cout << "after test exception" << endl;
    }
    catch (exception const & e)
    {
        cerr << "error: " << e.what() << endl;
    }
    return 0;
}

