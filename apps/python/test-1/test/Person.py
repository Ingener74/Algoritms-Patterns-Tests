#!/usr/bin/env python
# -*- coding=utf-8 -*-

__version__ = '0.0.1'


class Animal(object):
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return 'name: ' + str(self.name)


class Dog(Animal):
    def __init__(self, name):
        super(Dog, self).__init__(name)


class Person(object):
    def __init__(self, name, last_name, age, work, pets):
        self.name = name
        self.last_name = last_name
        self.age = age
        self.work = work
        self.pets = pets

    def __str__(self):
        return u'Имя: {0}, Фамилия: {1}, age: {2}, work: {3}' % (self.name, self.last_name, str(self.age), self.work)
        # + ('' if len(self.pets) != 0 else (u', животные: ' + [str(x) for i in self.pets]))


