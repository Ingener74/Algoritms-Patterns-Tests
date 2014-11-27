/*
 * main.cpp
 *
 *  Created on: Oct 17, 2014
 *      Author: pavel
 */

#include <iostream>
#include <tuple>
#include <utility>
#include <type_traits>
#include <functional>
#include <sstream>

using namespace std;

//auto stringify(const T& t, bool) const ->decltype(declval<ostream>() << t, void(), string
//        {})
//{
//    stringstream ss;
//    ss << t;
//    return ss.str();
//}
//auto stringify(const T& t, int) const -> string
//{
//    return "RemoteProperty";
//}

//template<typename A, typename enable_if<can_ostream<T>::value>::type* = nullptr>
//string stringify(const A& t)
//{
//    stringstream ss;
//    ss << t;
//    return ss.str();
//}
//template<typename A, typename enable_if<!can_ostream<T>::value>::type* = nullptr>
//string stringify(const A& t)
//{
//    return "RemoteProperty";
//}

/******************************************************************************************
 *
 *
 *
 ******************************************************************************************/
//namespace stringify_detail {
//
//template<typename T>
//auto stringify(T&& t, bool) -> decltype(declval<ostream>() << t, string{})
//{
//    stringstream ss;
//    ss << t;
//    return ss.str();
//}
//
//template<typename T>
//string stringify(T&& t, int)
//{
//    return "can not be string";
//}
//
//}  // namespace stringify_detail
//
//template<typename T>
//string stringify(T&& t)
//{
//    return stringify_detail::stringify(t, true);
//}

/******************************************************************************************
 *
 *
 *
 ******************************************************************************************/

template<typename T>
struct can_ostream
{
    template<typename U>
    static auto deduce(U&& u) -> decltype(declval<ostream>() << u, true_type{});

    template<typename >
    static false_type deduce(...);

    static constexpr bool value = is_same<decltype(deduce(declval<T>())), true_type>::value;
};

//template<typename T>
//class RemoteVariable
//{
//    using Getter = function<T()>;
//    using Setter = function<void(const T&)>;
//
//    Getter _g;
//    Setter _s;
//
//
//    template<typename P>
//    struct can_ostream
//    {
//        // static ostream o; // declval<ostream>()
//
//        template<typename U>
//        auto deduce(const U& u) -> decltype(declval<ostream>() << u, void(), true_type{});
//
//        template<typename >
//        auto deduce(...) -> false_type;
//
//        static constexpr bool value = (deduce(declval<P>()) == true_type{});
//    };
//
//    string stringify_impl(const T& t, true_type)
//    {
//        stringstream ss;
//        ss << t;
//        return ss.str();
//    }
//    string stringify_impl(const T&, false_type)
//    {
//        return "RemoveVariable";
//    }
//
//    auto stringify(const T& t) -> decltype(stringify_impl(t, result_of<>::type))
//    {
//        return stringify_impl(...);
//    }
//
//public:
//    RemoteVariable(Getter g  = Getter(), Setter s = Setter()): _g(g), _s(s){}
//    virtual ~RemoteVariable() = default;
//
//    operator T()
//    {
//        return _g();
//    }
//
//    RemoteVariable& operator=(const T& t)
//    {
//        _s(t);
//        return *this;
//    }
//
//    friend ostream& operator<<(ostream& out, const RemoteVariable& rho)
//    {
//        out << rho.stringify(rho._g(), true);
//        return out;
//    }
//};

int main(int argc, char **argv)
{
    try
    {
        string s1;
//        auto r1 = RemoteVariable<string>{[&s1](){ return s1; }, [&s1](string s){ s1 = s; }};
//        cout << r1 << endl;

        class Test {
        public:
            Test() = default;
            virtual ~Test() = default;

        private:
            int i = 0;
        };

        Test t1;
//        auto r2 = RemoteVariable<Test>{[&t1](){ return t1; }, [&t1](const Test& t){ t1 = t; }};
//        cout << r2 << endl;

//        cout << "can_ostream<decltype(s1)>::value << " << can_ostream<decltype(s1)>::value << endl;
//        cout << "can_ostream<decltype(t1)>::value << " << can_ostream<decltype(t1)>::value << endl;
//
//        cout << "stringify(s1) << " << stringify(s1) << endl;
//        cout << "stringify(t1) << " << stringify(t1) << endl;

//        cout << s1 << endl;
//        cout << t1 << endl;
    }
    catch (exception const & e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}

