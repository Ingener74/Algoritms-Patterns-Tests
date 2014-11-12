#!/usr/bin/env python
# -*- coding: utf-8 -*-

from PySide.QtGui import QApplication
from PySide.QtWebKit import QWebView

def main():
    import sys
    app = QApplication(sys.argv)
    
    web = QWebView()
    web.load('http://www.google.ru')
    web.show()
    
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()