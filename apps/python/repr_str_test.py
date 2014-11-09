#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Test:
    def __init__(self):
        self._test_str = Test.__class__
        
    def __str__(self):
        return "Test.__str__" + self._test_str

    def __repr__(self):
        return "Test.__repr__", self._test_str

def main():
    t1 = Test()
    
    print "print t1", t1
    
    print "print str(t1)", str(t1)

if __name__ == '__main__':
    main()