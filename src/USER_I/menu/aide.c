#include<stdio.h>
#include<stdlib.h>

#ifndef MENU_UI_H
#include"menu_ui.h"
#endif

int aide() {
	printf("Ne pas disponible\n");
	exit (0);
}

void prod_apropos() {
	printf("Pas disponible\n");
//	exit (1);
}

void info_cchange()
{
	nett();
	printf("\nInfo change:\n");
	printf("-Si vous changez le parametre n'a pas encore mis alors les parametres mis auparavant est invarible\n");
	printf("-Vous ne pouvez pas choisir le mois et saison en meme temps. Si vous tentez de changer l'un entre eux (mois/saison) l'autre s'initialise.\n");
	printf("______________________________________________________________________________________________________________________________________________\n");
}
