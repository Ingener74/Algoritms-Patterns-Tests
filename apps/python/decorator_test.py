#!/usr/bin/env python

def my_decorator(func):
    
    def wrapped():
        return "dec " + func() + " after dec"
    
    return wrapped

@my_decorator
def func():
    return "func"

def main():
    
    print 'main'
    
    print func()

if __name__ == '__main__':
    main()