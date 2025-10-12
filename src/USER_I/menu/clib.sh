#!/bin/bash
set -e
# creation de fichier objet
gcc -c -fPIC menu_ui.c
gcc -c -fPIC aide.c
gcc -c -fPIC convenlist.c

# creation de bibliotheque statique

gcc -shared -o libmenuui.so menu_ui.o aide.o convenlist.o

mv *.so ../../../lib/lib_so

rm *.o
