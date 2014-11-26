/*
 * methods_ref_qualifiers.cpp
 *
 *  Created on: Nov 26, 2014
 *      Author: pavel
 */

#include <iostream>
#include <stdexcept>

using namespace std;

/*
 * Test
 */
class Test{
public:
    Test(){
    }
    virtual ~Test(){
    }

    Test toTest() const &{
        cout << __PRETTY_FUNCTION__ << endl;
        return *this;
    }

    Test toTest() && {
        cout << __PRETTY_FUNCTION__ << endl;
        return *this;
    }

private:
};

int main(int argc, char **argv)
{
    try
    {
        auto t1 = Test{}.toTest();

        auto t2 = Test{};

        auto t3 = t2.toTest();
    }
    catch (exception const & e)
    {
        cerr << e.what() << endl;
    }
}

