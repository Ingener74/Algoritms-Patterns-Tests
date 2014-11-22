#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = 'Pavel'

import sqlite3

def main():

    con1 = sqlite3.connect("test.sqlite3")

    cur1 = con1.cursor()

    # cur1.execute('''create table test_table(
    #     ID      INT  PRIMARY KEY NOT NULL,
    #     NAME    TEXT             NOT NULL,
    #     AGE     INT              NOT NULL,
    #     ADDRESS CHAR
    #     )''')

    # cur1.execute('''create table body_mass(
    #     id   INT PRIMARY KEY NOT NULL,
    #     date TEXT NOT NULL,
    #     mass REAL NOT NULL
    # )''')

    # cur1.execute('''INSERT INTO test_table(ID, NAME, AGE, ADDRESS) VALUES(1, "Pavel", 28, "Proisvodstvennaja")''')
    # cur1.execute('''INSERT INTO body_mass(id, date, mass) VALUES (1, "10.1.1-11.1.2014", 112.3)''')

    # con1.commit()

    cur1.execute('''SELECT * FROM test_table''')

    print ''
    for i in cur1:
        for j in i:
            print j

    cur1.execute('''SELECT * FROM body_mass''')

    print ''
    for i in cur1:
        for j in i:
            print j

    print ''
    print 'close connection'

    cur1.close()

    print "connect successful"

if __name__ == '__main__':
    try:
        main()
    except Exception as e:
        print str(e)
