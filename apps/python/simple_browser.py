#!/usr/bin/env python
# -*- coding: utf-8 -*-


'''
Usage: python browser.py http://sourceforge.net/projects/boost/files/boost/1.58.0/
'''

import sys
from PySide.QtGui import QApplication
from PySide.QtWebKit import QWebView


class MyWebView(QWebView):
    def __init__(self):
        super(MyWebView, self).__init__()

        self.load(sys.argv[1])

        self.page().setForwardUnsupportedContent(True)
        self.page().unsupportedContent.connect(self.content)

    def content(self, reply):
        print reply.request().url().toString()
        raise SystemExit


def main():
    app = QApplication(sys.argv)

    web = MyWebView()
    web.show()

    sys.exit(app.exec_())


if __name__ == '__main__':
    main()