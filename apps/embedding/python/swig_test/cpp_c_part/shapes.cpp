/*

 swig2.0 -c++ -python shapes.i
 g++ -std=c++11 -shared -fpic ../cpp_c_part/shapes.cpp shapes_wrap.cxx -I/usr/include/python2.7/ -I/usr/lib/python2.7/config-x86_64-linux-gnu/ -I. -lpython2.7 -o _shapes.so

 */

#include <assert.h>
#include <iostream>
#include <cmath>
#include <stdexcept>

#include "shapes.h"

using namespace std;

Shape::Shape()
{
}

//shared_ptr<Shape> Shape::createShape(Form form)
//{
//    if (CIRCLE == form)
//        return make_shared<Circle>(1.0);
//    else
//        if (RECTANGLE == form)
//            return make_shared<Rectangle>(1.0, 1.0);
//        else
//            throw runtime_error("invalid shape");
//}

Shape::~Shape()
{
}

Rectangle::Rectangle(double w, double h) :
        _w(w), _h(h)
{
}

Rectangle::~Rectangle()
{
    cout << __PRETTY_FUNCTION__ << " " << _w << " x " << _h << endl;
}

double Rectangle::area()
{
    return _w * _h;
}

Circle::Circle(double R) :
        _R(R)
{
}

Circle::~Circle()
{
    cout << __PRETTY_FUNCTION__ << " " << _R << endl;
}

double Circle::area()
{
    return M_PI * (_R * _R);
}
