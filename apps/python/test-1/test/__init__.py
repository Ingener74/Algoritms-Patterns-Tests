#!/usr/bin/env python
# -*- encode=utf-8 -*-

from os.path import join, dirname

from setuptools import setup, find_packages


setup(
    name='test',
    version='0.0.1',
    packages=find_packages(),
    long_description=open(join(dirname(__file__), 'README.md')).read()
)