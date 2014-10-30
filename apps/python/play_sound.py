#!/usr/bin/env python
# -*- coding: utf-8 -*-

import winsound, sys
import pygame

def win():
    winsound.PlaySound("data/bell.wav", winsound.SND_FILENAME)

def pygame_sound():
    pygame.init()
    pygame.mixer.Sound("data/bell.wav").play()

def main():
    win()
#     pygame_sound()

if __name__ == '__main__':
    main()