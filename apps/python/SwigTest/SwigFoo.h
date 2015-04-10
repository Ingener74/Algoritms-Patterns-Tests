/*
 * SwigFoo.h
 *
 *  Created on: Apr 10, 2015
 *      Author: pavel
 */

#ifndef APPS_PYTHON_SWIGTEST_SWIGFOO_H_
#define APPS_PYTHON_SWIGTEST_SWIGFOO_H_

class SwigBar {
public:
    SwigBar();
    virtual ~SwigBar();
    void print() const;
};

class SwigFoo {
public:
    SwigFoo();
    virtual ~SwigFoo();

//#ifdef SWIG
//    %extend {
//        SwigBar& get(){
//            return (*$self)getBar();
//        }
//    }
//#else
    const SwigBar& getBar() const;
//#endif

private:
    SwigBar bar;
};

#endif /* APPS_PYTHON_SWIGTEST_SWIGFOO_H_ */
