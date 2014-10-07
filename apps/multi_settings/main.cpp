/*
 * main.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: pavel
 */

#include <iostream>
#include <tuple>
#include <utility>
#include <type_traits>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace std;

namespace pt = boost::property_tree;

/*
template<typename T>
auto get(const pt::ptree& p, const string& name, T& t) -> decltype(t.operator()(p.get<int>(name)), void())
{
    t(p.get<int>(name));
}

template<typename T>
auto get(const pt::ptree& p, const string& name, T& t) -> decltype(t = p.get<T>(name), void())
{
    t = p.get<T>(name);
}

template<typename T, typename ... Args>
void get(const pt::ptree& p, const string& name, T& t, Args&... args)
{
    get(p, name, t);
    get(p, args...);
}
*/

template<typename P, typename T>
auto get(P&& p, const string& name, T&& t) -> decltype(t.operator()(p.get<int>(name)), void())
{
    t(p.get<int>(name));
}

template<typename P, typename T>
auto get(P&& p, const string& name, T&& t) -> decltype(t = p.get<T>(name), void())
{
    t = p.get<T>(name);
}

template<typename P, typename T, typename ... Args>
void get(P&& p, const string& name, T&& t, Args&&... args)
{
    get(p, name, t);
    get(p, args...);
}

class TestGetter
{
public:
    template<typename T>
    T get(const string& name)
    {
        T t;
        return t;
    }
};

void foo(int i)
{
    cout << "i " << i << endl;
}

template<typename F>
void bar(F&& f){
    f = 10;
}

class foo1{
public:
    foo1(){
    }

    foo1(const foo1&) = delete;
    foo1& operator=(const foo1&) = delete;

    void operator()(int i){
        cout << "call operator " << i << endl;
    }
};

int main(int argc, char **argv)
{
    try
    {
        int j = 20;
        bar(j);

        cout << "i " << j << endl;

        foo1 f;

        pt::ptree p;

        pt::read_json("test_config.json", p);

        int i = 0;
        string s;
        bool b = false;

//        get(p, "test_int", i, "test_string", s, "test_bool", b);
//        get(p, "test_int", i, "test_string", s, "test_bool", b, "test_bind", f);
//
//        auto f2 = [](int i){ cout << "f2 lambda " << i << endl; };
//        get(p, "test_int", i, "test_string", s, "test_bool", b, "test_bind", f2);
//
//        auto f3 = bind(foo, placeholders::_1);
//        get(p, "test_int", i, "test_string", s, "test_bool", b, "test_bind", f3);

        TestGetter tg;
        auto p1 = tg;

        get(p1, "test_int", i, "test_string", s, "test_bool", b);
        get(p1, "test_int", i, "test_string", s, "test_bool", b, "test_bind", f);

        get(p1, "test_int", i, "test_string", s, "test_bool", b, "test_bind", [](int i){ cout << "f2 lambda " << i << endl; });

        get(p1, "test_int", i, "test_string", s, "test_bool", b, "test_bind", bind(foo, placeholders::_1));

        cout << i << " " << s << " " << b << endl;

        assert(100 == i);
        assert("pahan" == s);
        assert(b);

        cout << "successful" << endl;
    }
    catch (exception const & e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}

