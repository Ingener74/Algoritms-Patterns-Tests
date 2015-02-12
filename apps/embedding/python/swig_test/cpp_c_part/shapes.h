/*
 * swig_test.h
 *
 *  Created on: Dec 12, 2014
 *      Author: pavel
 */

#ifndef SHAPES_H_
#define SHAPES_H_

//#include <memory>

class Shape
{
public:

//    typedef enum _Form{
//        RECTANGLE,
//        CIRCLE,
//    } Form;

//    static std::shared_ptr<Shape> createShape(Form);

    Shape();
    virtual ~Shape();

    virtual double area() = 0;
};

class Rectangle: public Shape
{
public:
    Rectangle(double w = 0, double h = 0);
    virtual ~Rectangle();

    virtual double area();

protected:
    double _w = 0.0, _h = 0.0;
};

class Circle: public Shape
{
public:
    Circle(double R = 0);
    virtual ~Circle();

    virtual double area();

protected:
    double _R = 0.0;
};

#endif /* SWIG_TEST_H_ */
