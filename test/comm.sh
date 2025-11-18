#!/bin/bash

export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:../lib"
gcc -g main.c -I../headers -L../lib  -lmenu -lanal -lconven -lbdprod  
