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

template<typename T>
auto get(const pt::ptree& p, const string& name, T& t) -> decltype(t.foo(p.get<int>(name)), void())
{
    t.foo(p.get<int>(name));
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

void foo(int i)
{
    cout << "i " << i << endl;
}

class foo1{
public:
    foo1(){
    }

    foo1(const foo1&) = delete;
    foo1& operator=(const foo1&) = delete;

    void foo(int i){
        cout << "foo1::foo " << i << endl;
    }
};

int main(int argc, char **argv)
{
    try
    {
        foo1 f;
//
//        cout << boolalpha << endl;
//        cout << "f1 is callable: " << is_callable<foo1>::value << endl;
//
//        auto f2 = bind(&foo1::foo, &f);
//
//        cout << "f2 is callable: " << is_callable<decltype(bind(&foo1::foo, &f))>::value << endl;
//
//        auto f3 = [](){};
//
//        cout << "f3 is callable: " << is_callable<decltype(f3)>::value << endl;
//
//        cout << "" << is_callable<int>::value << endl;
//        cout << "" << is_callable<float>::value << endl;
//
//        cout << "" << endl;

        pt::ptree p;

        pt::read_json("test_config.json", p);

        int i = 0;
        string s;
        bool b = false;

        get(p, "test_int", i, "test_string", s, "test_bool", b);
//        get(p, "test_bind", bind(foo, placeholders::_1));
//        get(p, "test_int", i, "test_string", s, "test_bool", b, "test_bind", bind(foo, placeholders::_1));
        get(p, "test_int", i, "test_string", s, "test_bool", b, "test_bind", f);

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

