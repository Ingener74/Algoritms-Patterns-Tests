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
#include <boost/type_traits.hpp>

#include <boost/function_types/parameter_types.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/int.hpp>

using namespace std;

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
//auto get(P&& p, const string& name, T&& t) -> decltype(t.operator()(p.get<boost::function_traits<T>::arg1_type>(name)), void())
//{
//    t(p.get<boost::function_traits<T>::arg1_type>(name));
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

template<typename F>
void quuz(F&& f)
{
//    using lam_type = decltype(f);
//    using lam_args = boost::function_types::parameter_types<decltype(&lam_type::operator())>::type;
//    using lam_arg1 = boost::mpl::at<lam_args, boost::mpl::int_<1>>::type;

    cout << __PRETTY_FUNCTION__ << endl;
}

int main(int argc, char **argv)
{
    try
    {
//        boost::function_traits<void(int)>::arg1_type t;
//        quuz(baz);
//        quuz(quz);
//        quuz(foo);

//        quuz(&bar::operator());

//        boost::function_traits<&foo_type::operator()>::arg1_type t1;
//        quuz(bind(baz, placeholders::_1));

        auto lambda1 = [](string s){};

        quuz(lambda1);

        using lam_type = decltype(lambda1);

        using lam_args = boost::function_types::parameter_types<decltype(&lam_type::operator())>::type;

        using lam_arg1 = boost::mpl::at<lam_args, boost::mpl::int_<1>>::type;

        lam_arg1 la1 = "";


        bar f;

        boost::property_tree::ptree p;
        boost::property_tree::read_json("test_config.json", p);

        int i = 0;
        string s;
        bool b = false;

//        get(p, "test_int", i, "test_string", s, "test_bool", b);
//        get(p, "test_int", i, "test_string", s, "test_bool", b, "test_bind", f);
//        get(p, "test_int", i, "test_string", s, "test_bool", b, "test_bind", [](int i){ cout << "test_bind with lambda " << i << endl; });
//        get(p, "test_int", i, "test_string", s, "test_bool", b, "test_bind", bind(foo, placeholders::_1));
//        get(p, "test_int", i, "test_string", s, "test_bool", b, "test_bind", bind(foo, placeholders::_1));
//        get(p, "test_bind_string", bind(baz, placeholders::_1));
////        get(p, "test_bind_bool", bind(quz, placeholders::_1));

        get(p, "test_int", i, "test_string", s, "test_bool", b);
        get(p, "test_bind", bind(foo, placeholders::_1));

        cout << i << " " << s << " " << b << endl;

        assert(42 == i);
        assert("foo" == s);
        assert(b);

        cout << "successful" << endl;
    }
    catch (exception const & e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}

