/*

swig2.0 -c++ -python shapes.i
g++ -std=c++11 -shared -fpic ../cpp_c_part/shapes.cpp shapes_wrap.cxx -I/usr/include/python2.7/ -I/usr/lib/python2.7/config-x86_64-linux-gnu/ -I. -lpython2.7 -o _shapes.so

 */

#include "shapes.h"

#include <iostream>
#include <cmath>

using namespace std;

Shape::Shape()
{
}

Shape::~Shape()
{
}

Rectangle::Rectangle( double w, double h ) :
        _w(w), _h(h)
{
}

Rectangle::~Rectangle()
{
    cout << __PRETTY_FUNCTION__ << endl;
}

double Rectangle::area()
{
    return _w * _h;
}

Circle::Circle( double R ) :
        _R(R)
{
}

Circle::~Circle()
{
    cout << __PRETTY_FUNCTION__ << endl;
}

double Circle::area()
{
    return M_PI * (_R * _R);
}
