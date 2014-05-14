/*
 * MyQtMainWindow.h
 *
 *  Created on: May 14, 2014
 *      Author: pavel
 */

#ifndef MYQTMAINWINDOW_H_
#define MYQTMAINWINDOW_H_

#include <boost/smart_ptr.hpp>

#include <QtGui/qmainwindow.h>
#include "ui_myqt.h"

class MyQtMainWindow: public QMainWindow
{
    Q_OBJECT
public:
    explicit MyQtMainWindow(QWidget* parent = nullptr);
    virtual ~MyQtMainWindow();

private:
    boost::shared_ptr<Ui_MainWindow> ui;
};

#endif /* MYQTMAINWINDOW_H_ */
