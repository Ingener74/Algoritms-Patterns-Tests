#!/usr/bin/env python
# coding=utf-8

import sys
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


def main():
    global app
    app = QApplication(sys.argv)

    tray_menu = QMenu()

    tray_menu.addAction(QIcon(QPixmap('data/file.png')), u'Получить путь файлов', get_file_new)
    tray_menu.addAction(QIcon(QPixmap('data/directory.png')), u'Получить путь директории', get_directory_new)
    tray_menu.addSeparator()
    tray_menu.addAction(QIcon(QPixmap('data/close.png')), u'Выход', app.quit)

    tray = QSystemTrayIcon()
    tray.setIcon(QIcon(QPixmap('data//piggy.png')))
    tray.setContextMenu(tray_menu)
    tray.show()

    return app.exec_()


if __name__ == '__main__':
    main()

