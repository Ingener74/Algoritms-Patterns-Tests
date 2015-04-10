/*
 * SwigFoo.h
 *
 *  Created on: Apr 10, 2015
 *      Author: pavel
 */

#ifndef APPS_PYTHON_SWIGTEST_SWIGFOO_H_
#define APPS_PYTHON_SWIGTEST_SWIGFOO_H_

class SwigBaz {
public:
    SwigBaz();
    virtual ~SwigBaz();

    void testMe();

private:
};

class SwigBar {
public:
    SwigBar();
    virtual ~SwigBar();
    void printBar() const;

    SwigBaz* getBaz();

private:
    SwigBaz baz;
};

class SwigFoo {
public:
    SwigFoo();
    virtual ~SwigFoo();

    SwigBar* getBar();

private:
    SwigBar bar;
};

#endif /* APPS_PYTHON_SWIGTEST_SWIGFOO_H_ */
