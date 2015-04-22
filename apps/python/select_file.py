#!/usr/bin/env python
#coding=utf-8

import sys
from PySide.QtGui import QApplication, QFileDialog


def getFile(file_):
    print file_
    raise SystemExit


def main():

    app = QApplication(sys.argv)

    fileSelect = QFileDialog()
    
    fileSelect.fileSelected.connect(getFile)
    
    fileSelect.show()
    
    return app.exec_()

if __name__ == '__main__':
    main()

