#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from PySide.QtGui import QApplication, QMainWindow, QVBoxLayout, QPushButton, QWidget

class MainWindow(QWidget):
    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)
        
        self.vbox = QVBoxLayout()
        
        self.setLayout(self.vbox)
        
        self.setWindowTitle('PySide and ImageGenerator test')
        self.resize(640, 480)

def main():
    app = QApplication(sys.argv)
    
    mainWindow = MainWindow()
    mainWindow.show()
    
    return sys.exit(app.exec_())

if __name__ == '__main__':
    try:
        main()
    except Exception as e:
        print str(e)