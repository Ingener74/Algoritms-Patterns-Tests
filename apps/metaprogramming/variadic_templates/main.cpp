/*
 * main.cpp
 *
 *  Created on: Jun 30, 2014
 *      Author: ingener
 */

#include <iostream>

using namespace std;

class Pony
{
public:
    Pony()
    {
    }
    virtual ~Pony()
    {
    }

    friend ostream& operator<<(ostream& out, const Pony& rho);

private:
    string pony_name_ = "Little Pony";
};
ostream& operator<<(ostream& out, const Pony& rho)
{
    out << rho.pony_name_;
    return out;
}

template<typename T>
void foo(T t)
{
    cout << t << endl;
}
template<typename T, typename ... Args>
void foo(T t, Args ... args)
{
    cout << t << " ";
    foo(args...);
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

template<int I, typename Head, typename ... Tail>
struct getter
{
    using return_type = typename getter<I - 1, Tail...>::return_type;

    static return_type get(tuple<Head, Tail...> t)
    {
        return getter<I - 1, Tail...>::get(t);
    }
};
template<typename Head, typename ... Tail>
struct getter<0, Head, Tail...>
{
    using return_type = typename tuple<Head, Tail...>::value_type;
    static return_type get(tuple<Head, Tail...> t)
    {
        return t.head_;
    }
};

template<int I, typename Head, typename ... Tail>
typename getter<I, Head, Tail...>::return_type get(tuple<Head, Tail...> t)
{
    return getter<I, Head, Tail...>::get(t);
}

}  // namespace st

int main(int argc, char **argv)
{
    try
    {
        foo("One", 2, "Three", Pony());

        st::tuple<const char*, double, const char*, int> tuple_("Pi equal ", 3.1415926, " in america equal ", 4);

        cout << st::get<0>(tuple_) << " " << st::get<1>(tuple_) << " " << st::get<2>(tuple_) << " " << st::get<3>(tuple_) << endl;
    }
    catch (exception const & e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

