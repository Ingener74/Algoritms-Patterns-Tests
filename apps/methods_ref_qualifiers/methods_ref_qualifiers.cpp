/*
 * methods_ref_qualifiers.cpp
 *
 *  Created on: Nov 26, 2014
 *      Author: pavel
 */

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/*
 * Test
 */
class Test{
public:
    Test(string test = "test"): _test(test){
    }
    virtual ~Test(){
    }

    Test toTest() const &{
        cout << __PRETTY_FUNCTION__ << endl;
        Test{"toTest"};
        return *this;
    }

    Test toTest() && {
        cout << __PRETTY_FUNCTION__ << endl;
        _test = "toTest";
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Test& r)
    {
        return out << r._test;
    }

private:
    string _test = "test";
};

int main(int argc, char **argv)
{
    try
    {
        auto t1 = Test{}.toTest();

        auto t2 = Test{};

        auto t3 = t2.toTest();

        cout << t1 << endl;
        cout << t2 << endl;
        cout << t3 << endl;
    }
    catch (exception const & e)
    {
        cerr << e.what() << endl;
    }
}

