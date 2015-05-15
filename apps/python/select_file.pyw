#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import subprocess
from string import maketrans

from PySide.QtGui import QApplication, QFileDialog, QSystemTrayIcon, QMenu, QIcon, QPixmap


def get_file_new():
    file_names, file_filters = QFileDialog.getOpenFileNames()

    full_ = ''
    for i in file_names:
        full_ += i if file_names[-1] == i else i + ';'

    global app
    clipboard = app.clipboard()
    clipboard.setText(str(full_).translate(maketrans('\\', '/')))


def get_directory_new():
    directory_ = QFileDialog.getExistingDirectory()
    global app
    clipboard = app.clipboard()
    clipboard.setText(str(directory_).translate(maketrans('\\', '/')))


def processQrcFile():
    qrcFileName, _ = QFileDialog.getOpenFileName(caption=u'Выбери qrc файл', filter='*.qrc')
    
    pyFileName, _ = QFileDialog.getSaveFileName(caption=u'Сохрани py файл, незабудь "resources.qrc" -> "resources_rc.qrc"', filter='*.py')
    
    pysideRcc, _ = QFileDialog.getOpenFileName(caption=u"Открыть pyside-rcc.exe, он где то тут: Python27/Lib/site-packages/PySide/pyside-rcc.exe", filter='*.exe')
    
    subprocess.Popen([pysideRcc, qrcFileName, '-o', pyFileName])


def processUiFile():
    qrcFileName, _ = QFileDialog.getOpenFileName(caption=u'Выбери UI файл', filter='*.ui')
    
    pyFileName, _ = QFileDialog.getSaveFileName(caption=u'Сохрани py файл', filter='*.py')
    
    pysideUic, _ = QFileDialog.getOpenFileName(caption=u"Открыть pyside-uic.exe, он где то тут: Python27/Scripts/pyside-uic.exe", filter='*.exe')
    
    subprocess.Popen([pysideUic, qrcFileName, '-o', pyFileName])


def main():
    global app
    app = QApplication(sys.argv)

    tray_menu = QMenu()

    tray_menu.addAction(QIcon(QPixmap('data/file.png')), u'Получить пути файлов', get_file_new)
    tray_menu.addAction(QIcon(QPixmap('data/directory.png')), u'Получить путь директории', get_directory_new)
    tray_menu.addSeparator()
    tray_menu.addAction(QIcon(QPixmap('data/qrc.png')), u'Преобразовать .qrc в .py', processQrcFile)
    tray_menu.addAction(QIcon(QPixmap('data/ui.png')), u'Преозразовать .ui в .py', processUiFile)
    tray_menu.addSeparator()
    tray_menu.addAction(QIcon(QPixmap('data/close.png')), u'Выход', app.quit)

    tray = QSystemTrayIcon()
    tray.setIcon(QIcon(QPixmap('data//piggy.png')))
    tray.setContextMenu(tray_menu)
    tray.show()

    return app.exec_()


if __name__ == '__main__':
    main()

