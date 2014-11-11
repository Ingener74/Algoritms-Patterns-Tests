#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from PySide.QtGui import QApplication, QMainWindow, QVBoxLayout, QPushButton, QWidget

import matplotlib
matplotlib.rcParams['backend.qt4']='PySide'
from matplotlib.backends.backend_qt4agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure

import numpy as np

class MainWindow(QWidget):
    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)
        
        self.vbox = QVBoxLayout()
        
        self.figure = Figure()
        self.figureCanvas = FigureCanvas(self.figure)
        self.axes = self.figure.add_subplot(111)
        
        x = np.linspace(-np.pi, np.pi, 100)
        y = np.sin(x)
        self.axes.plot(x, y)
        
        self.vbox.addWidget(self.figureCanvas)
        
        self.setLayout(self.vbox)
        
        self.setWindowTitle('PySide and MatPlotLib test')
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