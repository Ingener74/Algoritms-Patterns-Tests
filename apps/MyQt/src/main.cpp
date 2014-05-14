/*
 * main.cpp
 *
 *  Created on: May 14, 2014
 *      Author: pavel
 */

#include <QtGui/qapplication.h>

#include "MyQtMainWindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MyQtMainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}

