#!/bin/bash

export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:../lib/lib"
gcc -g main.c -I../headers -L../lib/lib  -lmenu.so -lanal.so -lconven.so -lbdprod.so  
