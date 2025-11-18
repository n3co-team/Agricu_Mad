#!/bin/bash

export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:../lib/static"
gcc -c main.c
gcc -g main.o -I../headers -L../lib/static  -lmenu -lanal -lconven -lbdprod  
