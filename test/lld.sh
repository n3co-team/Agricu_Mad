#!/bin/bash
export LD_LIBRARY_PATH=../lib/lib_so:$LD_LIBRARY_PATH
if [[ $? -ne "0" ]]
then 
	echo "erreur"
	exit 1
fi
