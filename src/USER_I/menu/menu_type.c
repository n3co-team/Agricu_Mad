/** 
* @file menu_ui.c 
* @brief fichier contient les fonctions de menu
* @author Windrick
*/

#include<stdio.h>
#include"conven.h"
#include"menu_ui.h"

void menu_list (int i, prod* p) {
	switch (i) {
		case 0: me_pri(p); break;
		case 1: me_sty(p); break;
		case 2: me_sso(p); break;
		case 3: me_ssa(p); break;
		case 4: me_smo(p); break;
		case 5: me_ styso(p); break;
		case 6: me_ssamoi(p); break;
		case 7: me_ssamoity(p); break;
		case 8: me_ssamoiso(p); break;
	}
}

/** @fn me_pri
* @details fonction pour menu principal
* @param struct produit
* @return void
*/
void me_pri(prod* p)
{
	int choix;

	printf("CHOISIR UN OPTION :\n");
	printf("1) Type de produit");
	printf("2) Caracteristique du sol");
	printf("3) Saison");
	printf("4) Mois");
	printf("0) à propos ");
	
	while (1)
	{
		printf("Entrer votre choix : ");
		scanf("%d",&choix);
		if (choix >= 0 && choix <= 4) {
			break;
		}
		printf("choix incorrect !!!\n");
		printf("R");
	}

	switch choix {
		case 0: prod_apropos(); break;
		case 1: me_list(1,p);
		case 2: me_list(2,p);
		case 3: me_list(3,p);
		case 4: me_list(4,p);
	} 	
}

/** @fn me_sty
* @details menu sans choix type de produit
* @param struct produit
* @return void
*/
void me_sty(prod* p)
{
	int choix;

	printf("CHOISIR UN OPTION :\n");
	printf("1) List de produit");
	printf("2) Caracteristique du sol");
	printf("3) Saison");
	printf("4) Mois");
	
	while (1)
	{
		printf("Entrer votre choix : ");
		scanf("%d",&choix);
		if (choix >= 1 && choix <= 4) {
			break;
		}
		printf("choix incorrect !!!\n");
		printf("R");
	}

	switch choix {
		case 0: prod_apropos(); break;
		case 1: prod_list(p);
		case 2: lcsol(p);
 me_list(2,p);
break;
		case 3: lcsaison(p);
me_list(3,p);
		case 4: lcmois(p);
me_list(4,p);
break;
	} 
}		
