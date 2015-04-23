#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys, os
from PySide.QtGui import *
from PySide.QtCore import *
from IPython.lib.inputhook import ctypes

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build-linux/apps/python/image_generator')))
from imagegen import ImageGenerator, Image

class MainWindow(QWidget):
    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)
        
#         imgen = ImageGenerator()
        
        im1 = Image(Image.RGB, 100, 100)
        
        self.vbox = QVBoxLayout()
        
        self.image = QLabel("Image should here")
        self.vbox.addWidget(self.image)
        
        buffer_1 = buffer(im1.getData(), 0, im1.getHeight() * im1.getWidth() * im1.getType())

        image = QImage(buffer_1, im1.getWidth(), im1.getHeight(), QImage.Format_RGB888)
        
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
