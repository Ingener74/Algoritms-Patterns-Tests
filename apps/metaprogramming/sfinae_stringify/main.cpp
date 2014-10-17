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

using namespace std;

//auto stringify(const T& t, bool) const ->decltype(std::declval<std::ostream>() << t, void(), std::string
//        {})
//{
//    std::stringstream ss;
//    ss << t;
//    return ss.str();
//}
//auto stringify(const T& t, int) const -> std::string
//{
//    return "RemoteProperty";
//}

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




template<typename T>
class RemoteVariable
{
    using Getter = std::function<T()>;
    using Setter = std::function<void(const T&)>;

    Getter _g;
    Setter _s;


    template<typename P>
    struct can_ostream
    {
        // static std::ostream o; // std::declval<std::ostream>()

        template<typename U>
        auto deduce(const U& u) -> decltype(std::declval<std::ostream>() << u, void(), std::true_type{});

        template<typename >
        auto deduce(...) -> std::false_type;

        static constexpr bool value = (deduce(std::declval<P>()) == std::true_type{});
    };

    string stringify_impl(const T& t, true_type)
    {
        stringstream ss;
        ss << t;
        return ss.str();
    }
    string stringify_impl(const T&, false_type)
    {
        return "RemoveVariable";
    }

    auto stringify(const T& t) -> decltype(stringify_impl(t, result_of<>::type))
    {
        return stringify_impl(...);
    }

public:
    RemoteVariable(Getter g  = Getter(), Setter s = Setter()): _g(g), _s(s){}
    virtual ~RemoteVariable() = default;

    operator T()
    {
        return _g();
    }

    RemoteVariable& operator=(const T& t)
    {
        _s(t);
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const RemoteVariable& rho)
    {
        out << rho.stringify(rho._g(), true);
        return out;
    }
};

int main(int argc, char **argv)
{
    try
    {
        string s1;
        auto r1 = RemoteVariable<string>{[&s1](){ return s1; }, [&s1](string s){ s1 = s; }};

        cout << r1 << endl;

        class Test {
        public:
            Test() = default;
            virtual ~Test() = default;

        private:
            int i = 0;
        };

        Test t1;
        auto r2 = RemoteVariable<Test>{[&t1](){ return t1; }, [&t1](const Test& t){ t1 = t; }};

        cout << r2 << endl;
    }
    catch (exception const & e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}

