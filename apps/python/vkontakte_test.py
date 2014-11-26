#!/usr/bin/env python
# -*- coding: utf-8 -*-

from vk import *

class Test:
    def __init__(self, A):
        self._a = A

    @property
    def a(self):
        return self._a

    @a.setter
    def a(self, value):
        self._a = value

def main():
    vk = API()



if __name__ == '__main__':
    main()