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
 * functor setter with deduce argument type
 */

template<typename P, typename T>
auto get(P&& p, const string& name, T&& t) -> decltype(t.operator()(p.get<int>(name)), void())
{
    t(p.get<int>(name));
}

template<typename P, typename T>
auto get(P&& p, const string& name, T&& t) -> decltype(t.operator()(p.get<string>(name)), void())
{
    t(p.get<string>(name));
}

//template<typename P, typename T>
//auto get(P&& p, const string& name, T&& t) -> decltype(t.operator()(p.get<bool>(name)), void())
//{
//    t(p.get<bool>(name));
//}

template<typename P, typename T>
auto get(P&& p, const string& name, T&& t) -> decltype(t = p.get<T>(name), void())
{
    t = p.get<typename remove_reference<T>::type>(name);
}

template<typename P, typename T, typename ... Args>
void get(P&& p, const string& name, T&& t, Args&&... args)
{
    get(p, name, t);
    get(p, args...);
}

void foo(int i)
{
    cout << "test_bind with bind " << i << endl;
}

class bar{
public:
    bar(){
    }

    bar(const bar&) = delete;
    bar& operator=(const bar&) = delete;

    void operator()(int i){
        cout << "test_bind with custom functor " << i << endl;
    }
};

void baz(string s){
    cout << "test_bind_string " << s << endl;
}

void quz(bool b){
    cout << "test bind bool " << b << endl;
}

int main(int argc, char **argv)
{
    try
    {
        bar f;

        pt::ptree p;
        pt::read_json("test_config.json", p);

        int i = 0;
        string s;
        bool b = false;

        get(p, "test_int", i, "test_string", s, "test_bool", b);
        get(p, "test_int", i, "test_string", s, "test_bool", b, "test_bind", f);
        get(p, "test_int", i, "test_string", s, "test_bool", b, "test_bind", [](int i){ cout << "test_bind with lambda " << i << endl; });
        get(p, "test_int", i, "test_string", s, "test_bool", b, "test_bind", bind(foo, placeholders::_1));
        get(p, "test_bind_string", bind(baz, placeholders::_1));
//        get(p, "test_bind_bool", bind(quz, placeholders::_1));

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

