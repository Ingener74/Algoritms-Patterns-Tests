
/*

gcc -c -fpic main.c test_swig_wrap.c -DHAVE_CONFIG_H -I"/usr/include/python2.7/" -I"/usr/lib/python2.7/config-x86_64-linux-gnu"
gcc -shared main.o test_swig_wrap.o -o _test_swig.so

Python 2.7.6 (default, Mar 22 2014, 22:59:56) 
[GCC 4.8.2] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>> import test_swig
>>> test_swig.test_swig()
I am test swig module
>>> quit()

*/

#include <stdio.h>

void swig_me(){
    printf ("I am swig module\n");
}
