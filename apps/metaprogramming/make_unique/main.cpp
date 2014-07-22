/*
 * main.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: pavel
 */

#include <memory>
#include <utility>
#include <iostream>
#include <stdexcept>

using namespace std;

class TestClass
{
public:
    TestClass( int i = 0 ) :
            _i(i)
    {
    }
    virtual ~TestClass()
    {
    }

    friend inline ostream& operator<<( ostream& out, const TestClass& rho );

private:
    int _i = 0;
};

ostream& operator<<( ostream& out, const TestClass& rho )
{
    out << "Test class " << rho._i;
    return out;
}

template <typename T, typename ... Args>
unique_ptr<T> make_unique( Args ... args )
{
    unique_ptr<T> ptr(new T(forward<Args>(args)...));
    return ptr;
}

int main( int argc, char **argv )
{
    try
    {
        auto uptr = make_unique<TestClass>(10);

        cout << *uptr << endl;
    }
    catch ( exception const & e )
    {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

