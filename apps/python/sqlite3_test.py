#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = 'Pavel'

import sqlite3

def main():

    db_connection = sqlite3.connect("test.sqlite3")

    db_cursor = db_connection.cursor()

    db_cursor.execute('''SELECT * FROM peoples''')

    print ''
    for i in db_cursor:
        for j in i:
            print j

    db_cursor.execute('''SELECT * FROM body_mass''')

    print ''
    for i in db_cursor:
        for j in i:
            print j

    print ''
    print 'close connection'

    db_cursor.close()

    print "connect successful"

if __name__ == '__main__':
    try:
        main()
    except Exception as e:
        print str(e)
