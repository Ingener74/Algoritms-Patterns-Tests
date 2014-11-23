#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = 'Pavel'

import sqlite3

from sqlalchemy import *
from sqlalchemy.orm import *
from sqlalchemy.ext.declarative import *

Base = declarative_base()

class Department(Base):
    __tablename__ = 'department'
    id = Column(Integer, primary_key=True)
    name  = Column(String)

class Employee(Base):
    __tablename__ = 'employee'
    id = Column(Integer, primary_key=True)
    name = Column(String)

    hired_on = Column(DateTime, default=func.now())
    department_id = Column(Integer, ForeignKey('department.id'))

    department = relationship(Department, backref('employees', uselist=True, cascade='delete,all'))

from sqlalchemy import create_engine
engine = create_engine('sqlite:///orm_in_detail.sqlite3')

from sqlalchemy.orm import sessionmaker

session = sessionmaker()

session.configure(bind=engine)

Base.metadata.create_all(engine)

# def main():
#
#     db_connection = sqlite3.connect("test.sqlite3")
#
#     db_cursor = db_connection.cursor()
#
#     db_cursor.execute('''SELECT * FROM peoples''')
#
#     print ''
#     for i in db_cursor:
#         for j in i:
#             print j
#
#     db_cursor.execute('''SELECT * FROM body_mass''')
#
#     print ''
#     for i in db_cursor:
#         for j in i:
#             print j
#
#     print ''
#     print 'close connection'
#
#     db_cursor.close()
#
#     print "connect successful"
#
# def main():
#
#
# if __name__ == '__main__':
#     try:
#         main()
#     except Exception as e:
#         print str(e)
