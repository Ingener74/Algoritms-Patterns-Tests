#!/usr/bin/env python
# -*- coding: utf-8 -*-

import winsound, sys
from Tkinter import *

root = Tk()

def play_sound():
    winsound.PlaySound("data/bell.wav", winsound.SND_FILENAME)

button1 = Button(text=u'Click me!!!', command=play_sound)
button1.pack()

root.mainloop()