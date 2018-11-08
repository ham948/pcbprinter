# -*- coding: utf-8 -*-
"""
Created on Fri Nov  2 12:14:03 2018

@author: Daniel
"""

import serial
import time

red= 0
run= 1
s= serial.Serial()
s.baudrate=9600
s.port='COM13'
pxlLine=open("C:\\ardct\\test.txt",'r')
s.open()
while run:
    red=int(s.read(1))
    if red==8:
        pxln=pxlLine.read(11)
        print(pxln)
        if pxln[0]=='4':
            run=0
        else:
                s.write(pxln.encode())
                print(pxln)
    
s.close()
