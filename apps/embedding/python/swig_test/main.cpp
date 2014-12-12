/*

$ rm -rf swig_me.py swig_me.pyc _swig_me.so test_swig_wrap.cxx && ls
main.cpp  swig_test.h  test_swig.i
$ swig -c++ -python test_swig.i
$ g++ -shared -fpic main.cpp test_swig_wrap.cxx -I/usr/include/python2.7/ -I/usr/lib/python2.7/config-x86_64-linux-gnu/ -I. -lpython2.7 -o _swig_me.so
$ python

Python 2.7.6 (default, Mar 22 2014, 22:59:56)
[GCC 4.8.2] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>> import swig_me
>>> s = swig_me.SwigTest()
SwigTest::SwigTest()
>>> s.setTest(123)
void SwigTest::setTest(int) 123
>>> s.getTest()
int SwigTest::getTest() 123
123
>>>
virtual SwigTest::~SwigTest()
pavel@pavel-sgh:~/prj/Algoritms-Patterns-Tests/apps/embedding/python/swig_test$

 */

#include <iostream>

#include <swig_test.h>

using namespace std;

SwigTest::SwigTest(): test(0)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

SwigTest::~SwigTest()
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void SwigTest::setTest(int test)
{
    cout << __PRETTY_FUNCTION__ << " " << test << endl;
    SwigTest::test = test;
}

int SwigTest::getTest()
{
    cout << __PRETTY_FUNCTION__ << " " << test << endl;
    return SwigTest::test;
}

void swig_me()
{
    cout << "I am swig module\n" << endl;
}
