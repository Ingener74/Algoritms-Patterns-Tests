/*
 * main.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: pavel
 */

#include <iostream>
#include <tuple>
#include <utility>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace std;

namespace pt = boost::property_tree;
/*

template<typename T>
void get(const pt::ptree &p, tuple<pair<string, T>>& t)
{
    get<0>(t).second = p.get<T>(get<0>(t).first);
}

template<typename T, typename... Args>
void get(const pt::ptree &p, tuple<pair<string, T>, pair<string, Args>...>& t)
{
    get(p.);
}
*/

/*
template<typename T>
void get(const pt::ptree& p, pair<string, T> t)
{
    t.second = p.get<T>(t.first);
}

template<typename T, typename ... Args>
void get(const pt::ptree& p, pair<string, T> t, pair<string, T> ... args)
{
    t.second = p.get<T>(t.first);
    get(t, args);
}
*/

template<typename T>
void get(const pt::ptree& p, const string& name, T& t)
{
    t = p.get<T>(name);
}

template<typename T, typename ... Args>
void get(const pt::ptree& p, const string& name, T& t, Args&... args)
{
    t = p.get<T>(name);
    get(p, args...);
}

int main(int argc, char **argv)
{
    try
    {
        cout << "" << endl;

        pt::ptree p;

        pt::read_json("test_config.json", p);

//        assert(100 == p.get<int>("test_int"));
//        assert("pahan" == p.get<string>("test_string"));
//        assert(p.get<bool>("test_bool"));

        int i = 0;
        string s;
        bool b = false;

        get(p, "test_int", i, "test_string", s, "test_bool", b);

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

