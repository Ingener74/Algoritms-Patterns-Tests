/*
 * main.cpp
 *
 *  Created on: Nov 21, 2014
 *      Author: pavel
 */

#include <iostream>

using namespace std;

/*
 * ITest
 */
template<typename T>
class ITest
{
public:
    ITest()
    {
    }
    virtual ~ITest()
    {
    }

    virtual void test() = 0;

private:
    T* t = nullptr;
};

/*
 * Test
 */
class Test: public ITest<int>
{
public:
    Test()
    {
    }
    virtual ~Test()
    {
    }

    virtual void test()
    {
    }

private:
};

int main(int argc, char **argv)
{
    try
    {

    }
    catch (exception const& e)
    {
        cerr << "exception: " << e.what() << endl;
    }
    return 0;
}

