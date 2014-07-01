/*
 * main.cpp
 *
 *  Created on: Jun 30, 2014
 *      Author: ingener
 */

#include <iostream>

using namespace std;

template<typename T>
void bar(T t)
{
    cout << t << endl;
}

template<typename ... Args>
void foo(Args ... args)
{
    cout << "sizeof... " << sizeof...(args) << endl;
    foo(bar(args)...);
}

namespace st
{

template<typename ... Args>
struct tuple;

template<typename Head, typename ... Tail>
struct tuple<Head, Tail...> : tuple<Tail...>
{
    tuple(Head h, Tail ... tail) :
            tuple<Tail...>(tail...), head_(h)
    {
    }

    using base_type = tuple<Tail...>;
    using value_type = Head;

    base_type& base_ = static_cast<base_type&>(*this);
    Head head_;
};

template<>
struct tuple<>
{
};

}  // namespace st

int main(int argc, char **argv)
{
    try
    {
        st::tuple<double, const char*, const char*, int> testTuple(3.1415926, "Pi", "In america", 4);

        cout << testTuple.head_ << " " << testTuple.base_.head_ << " " << testTuple.base_.base_.head_ << " " << testTuple.base_.base_.base_.head_ << endl;
    }
    catch (exception const & e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

