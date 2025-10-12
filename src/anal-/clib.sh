#!/bin/bash
set -e

PREFIX="analy"
LIB="analyse"
DIR_LIB="../../lib/lib_so/"

#if [[ $? -ne 0 ]]
#then
#	echo "erreur"
#	exit 1
#fi

NBR=$(($# -1)) 	#nombre d'argument

#creatio de fichier objet
gcc -c -fPIC $PREFIX.c

#creatio de bibliotheque dynamique
gcc -shared -o lib$LIB.so *.o

#deplacement
mv *.so $DIR_LIB

#suppression des objets dans le repertoire courant
rm *.o
