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
#include <type_traits>

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
        cout << this << ":" << _.str() << endl;
    }

    template<typename T>
    Exception& operator<<(T other)
    {
        foo(other);
        return *this;
    }

private:
    template<typename T>
    void foo(T&& t, typename enable_if<is_same<decltype(t(declval<Exception>())), void>::value>::type* = nullptr)
    {
        _cb.push_back(t);
    }

    template<typename T>
    void foo(T t, typename enable_if<is_same<bool, T>::value>::type* = nullptr)
    {
        if (t)
        {
            for (auto cb : _cb)
                cb(*this);
            throw runtime_error(_.str());
        }
    }

    // operator() not exist
    template<typename T>
    void foo(T t, typename enable_if<!is_same<bool, T>::value>::type* = nullptr)
    {
        _ << t;
    }

    stringstream _;
    list<ExceptionCallback> _cb;
};

template<typename T>
void bar(T&& t)
{
    cout << boolalpha;

    cout << is_same<decltype(declval<T>()(declval<Exception>())), void>::value << endl;

//    cout << has_call_op<T>::value << endl;

    cout << noboolalpha;
}

int main(int argc, char **argv)
{
    try
    {
        bar([](Exception&& e){});

        int c = 38;

        cout << "before test exception" << endl;

//        Exception() << "Test exception 1" << [&](Exception&& e)
//        {
//            e << "i was called in exception " << c;
//        } << (5 > 1);

        Exception() << "Test exception 2" << true;
//        Exception() << "Test exception 3" << (5 > 1);

        cout << "after test exception" << endl;
    }
    catch (exception const & e)
    {
        cerr << "error: " << e.what() << endl;
    }
    return 0;
}

