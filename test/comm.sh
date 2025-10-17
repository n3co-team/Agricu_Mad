#!/bin/bash

if [[ -z $LD_LIBRARY_PATH ]]
then
	export LD_LIBRARY_PATH=../lib/lib_so:$LD_LIBRARY_PATH
	if [[ $? -eq 0 ]]
	then
		echo "ajout fait"
	else 
		echo "error"
	fi
fi

gcc testmenu.c -I../headers -L../lib/lib_so -lmenuui -lanalyse -lconven -lbdproduit
