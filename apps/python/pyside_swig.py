#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys, os
from PySide.QtGui import QApplication, QMainWindow, QVBoxLayout, QPushButton, QWidget, QGraphicsView, QLabel, QImage,\
    QPixmap
from PySide import QtCore

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/apps/python/image_generator')))
from imagegen import ImageGenerator, Image

class MainWindow(QWidget):
    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)
        
        imgen = ImageGenerator()
        
        im1 = imgen.create()
        
        self.vbox = QVBoxLayout()
        
        self.image = QLabel("Image should here")
        self.vbox.addWidget(self.image)
        
        image = QImage(im1.getData(), im1.getWidth(), im1.getHeight(), QImage.Format_RGB888)
        image.save("test.bmp")
        
        self.image.setPixmap(QPixmap.fromImage(image))
        
        self.setLayout(self.vbox)
        
        self.setWindowTitle('PySide and ImageGenerator test')
#         self.resize(640, 480)

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