/*
 * swig_test.h
 *
 *  Created on: Dec 12, 2014
 *      Author: pavel
 */

#ifndef SWIG_TEST_H_
#define SWIG_TEST_H_

void swig_me();

class SwigTest
{
public:
    SwigTest();
    virtual ~SwigTest();

    void setTest(int test);
    int getTest();

private:
    int test;
};

#endif /* SWIG_TEST_H_ */
