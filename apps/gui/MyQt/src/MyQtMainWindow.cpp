/*
 * MyQtMainWindow.cpp
 *
 *  Created on: May 14, 2014
 *      Author: pavel
 */

#include "MyQtMainWindow.h"

MyQtMainWindow::MyQtMainWindow(QWidget* parent) :
        QMainWindow(parent), ui(new Ui_MainWindow)
{
    ui->setupUi(this);
}

MyQtMainWindow::~MyQtMainWindow()
{
}

