#!/usr/bin/env python
# encoding=utf-8

from test.Person import Person, Dog

d1 = Dog(u'Тузик')
p1 = Person(u'Павел', u'Шнайдер', 28, u'Программист', [d1])
print p1
