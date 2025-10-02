#!/bin/bash
if [[ ! -e ppush.sh ]] || [[ "$0" != "ppush.sh" ]]
then
	cat $0>ppush.sh
fi

VERT="\e[42m"
ROUGE="\e[41m"
DEFAUT="\e[0m"
UNDERLINE="\e[4m"
CURRENT_BRANCH=$(git branch | grep "^\*" | cut -d" " -f2)

function verfication ()
{
	if [[ $? -eq 0 ]]
	then 
		echo -e "$VERT avec succes$DEFAUT\n"
	else
		echo -e "$ROUGE echoué $DEFAUT\n"
		echo "L'execution interrompu"
		exit
	fi
}

if [[ $# -gt 2 ]]
then
	echo "trop d'argument"
	echo "lancer $0 --help pour aide"
	exit 1
fi

#page d'aide
aide () {
	echo "Cette script fait trois tâche :"
	echo "> ajout tous les fichiers dans le dossier courant au depôt de git, branche courant"
	echo "> fait commité ce nouveau depôt"
	echo "> enfin , les poussé vers depôt github"
	echo -e "\n${UNDERLINE}Syntaxe$DEFAUT: $0 [option]|[argument]"
	echo -e "${UNDERLINE}option$DEFAUT :\n--help , -h	page d'aide"
	echo -e "${UNDERLINE}argument$DEFAUT :\nmessage au commit"

	exit 0
}

if [[ $1 == "--help" ]] || [[ $1 == "-h" ]]
then
	aide
fi

echo "=================================================================================================="
echo -e "\e[1mSTATUS ACTUEL :$DEFAUT"
git status
echo -e "==================================================================================================\n"

echo "Addition des dossier fichier dans dossier courant dans depot git ,branche $CURRENT_BRANCH ..."
git add .
git rm --cached $0
verfication

echo "Ajout de commit ..."
if [[ -z $1 ]]
then
	git commit -m "$(date +%D)"
else 
	git commit -m "$1"
fi
verfication

echo "Pousser vers github ..."
git push origin $CURRENT_BRANCH 
verfication

echo "mise a jour"
git pull
verfication
