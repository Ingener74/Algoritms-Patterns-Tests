#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys
import json
import subprocess

from string import maketrans

from PySide.QtGui import QApplication, QFileDialog, QSystemTrayIcon, QMenu, QIcon, QPixmap


def getFileNew():
    file_names, file_filters = QFileDialog.getOpenFileNames()

    full_ = ''
    for i in file_names:
        full_ += i if file_names[-1] == i else i + ';'

    global app
    clipboard = app.clipboard()
    clipboard.setText(str(full_).translate(maketrans('\\', '/')))


def getDirectoryNew():
    directory_ = QFileDialog.getExistingDirectory()
    global app
    clipboard = app.clipboard()
    clipboard.setText(str(directory_).translate(maketrans('\\', '/')))


def getToolFileName(tool, comment):
    pyside_rcc, _ = QFileDialog.getOpenFileName(caption=u"Открыть {0}.exe, {1}".format(tool, comment), filter='*.exe')
    return pyside_rcc

def getTool(tool, comment):
    CONFIG_FILE = 'config.json'

    json_ = json.load(open(CONFIG_FILE, mode='r+'))

    toolFileName = json_[tool] if os.path.exists(json_[tool]) else getToolFileName(tool, comment)

    if len(toolFileName) == 0:
        raise SystemExit

    json_[tool] = toolFileName
    with open(CONFIG_FILE, 'w') as json_file:
        json.dump(json_, json_file, sort_keys=True, indent=4, separators=(',', ':'))
    
    return toolFileName

def processQrcFile():
    qrcFileName, _ = QFileDialog.getOpenFileName(caption=u'Выбери qrc файл', filter='*.qrc')
    
    pyFileName, _ = QFileDialog.getSaveFileName(caption=u'Сохрани py файл, незабудь "resources.qrc" -> "resources_rc.qrc"', filter='*.py')
    
    subprocess.Popen([getTool('pyside_rcc', u'он где то тут: Python27/Lib/site-packages/PySide/pyside-rcc.exe'), qrcFileName, '-o', pyFileName])

def processUiFile():
    qrcFileName, _ = QFileDialog.getOpenFileName(caption=u'Выбери UI файл', filter='*.ui')
    
    pyFileName, _ = QFileDialog.getSaveFileName(caption=u'Сохрани py файл', filter='*.py')

    subprocess.Popen([getTool('pyside_uic', u'он где то тут: Python27/Scripts/pyside-uic.exe'), qrcFileName, '-o', pyFileName])


def main():
    global app
    app = QApplication(sys.argv)

    tray_menu = QMenu()

    tray_menu.addAction(QIcon(QPixmap('data/file.png')), u'Получить пути файлов', getFileNew)
    tray_menu.addAction(QIcon(QPixmap('data/directory.png')), u'Получить путь директории', getDirectoryNew)
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

