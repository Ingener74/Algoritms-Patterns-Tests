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

//  auto stringify(const T& t, bool) const ->decltype(std::declval<std::ostream>() << t, void(), std::string{})
//  {
//      std::stringstream ss;
//      ss << t;
//      return ss.str();
//  }
//  auto stringify(const T& t, int) const -> std::string
//  {
//      return "RemoteProperty";
//  }

//template<typename P>
//struct can_ostream{
//
//    static std::ostream o; // std::declval<std::ostream>()
//
//    template<typename U>
//    auto deduce(const U& u) -> decltype(o << u, void(), std::true_type{});
//
//    template<typename>
//    auto deduce(...) -> std::false_type;
//
//    static constexpr bool value = (deduce(std::declval<P>()) == std::true_type{});
//};
//
//template<typename A, typename std::enable_if<can_ostream<T>::value>::type* = nullptr>
//std::string stringify(const A& t)
//{
//    std::stringstream ss;
//    ss << t;
//    return ss.str();
//}
//template<typename A, typename std::enable_if<!can_ostream<T>::value>::type* = nullptr>
//std::string stringify(const A& t)
//{
//    return "RemoteProperty";
//}
//
//friend std::ostream& operator<<(std::ostream& out, const RemoteProperty<T>& rho){
//    out << rho.stringify(rho._getter(), true);
//    return out;
//}

/*
std::string foo;

auto rp = RemoteProperty<std::string>{[&foo](std::string s){ foo = s; }, [&foo](){ return foo; }};

rp = "Test";

std::string testString = rp;

std::cout << rp << std::endl;

class Test{
public:
    Test(){}
    virtual ~Test(){}
};

Test t;

auto rp2 = RemoteProperty<Test>{[&t](const Test& bar){ t = bar; }, [&t](){ return t; }};
std::cout << rp2 << std::endl;
*/

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

string quuuz(){
    return "";
}

template<typename T>
void quuuuz(T t)
{
    auto t1 = [](int){};
//    cout << boost::function_traits<decltype(&decltype(t1)::operator())>::arity << endl;

    cout << typeid(decltype(t1)).name() << endl;

    t(1);
}

int main(int argc, char **argv)
{
    try
    {
        typename result_of<decltype(&quuuz)()>::type t3;

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

        quuuuz(
          quz
//        [](int i)
//        {
//            cout << i << endl;
//        }
        );

        cout << "successful" << endl;
    }
    catch (exception const & e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}

