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


// gdb flags for debug
//
//set stop-on-solib-events 1
//set breakpoint pending on

#ifdef SWIG
    %feature("director") A;
    %feature("director") B;
    %feature("director") C;
    %feature("director") D;
#endif

class A {
public:
    virtual ~A() = default;
    virtual void testA();
};

class B: virtual public A {
public:
    virtual ~B() = default;
    virtual void testB();
};

class C: virtual public A {
public:
    virtual ~C() = default;
    virtual void testC();
};

class D: virtual public A {
public:
    virtual ~D() = default;
    virtual void testD();
};

class E {
public:
    virtual ~E() = default;
    virtual void testE(B*);
};

class F {
public:
    virtual ~F() = default;
    virtual void testF(C*);
};

class T {
public:
    virtual ~T() = default;
    virtual void testT(D*);
};


#endif /* APPS_PYTHON_SWIGTEST_SWIGFOO_H_ */
