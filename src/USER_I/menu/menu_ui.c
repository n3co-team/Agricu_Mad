/** 
* @file menu_ui.c 
* @brief fichier contient les fonctions de menu
* @author Windrick
*/

#include<stdio.h>
#include"menu_ui.h"

/** @fn menu_list
* @details fonction qui contient les appel de fonction des menu
* @return void
*/

void me_list (int i, prod* p) {
	switch (i) {
		case 0: me_pri(p); break;
		case 1: me_sty(p); break;
		case 2: me_sso(p); break;
	//	case 3: me_ssa(p); break;
	//	case 4: me_smo(p); break;
		case 3: me_styso(p); break;
		case 4: me_ssamo(p); break;
		case 5: me_stysamo(p); break;
		case 6: me_ssosamo(p); break;
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

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1:lctype(p);
			 me_list(1,p); break;
		case 2: lcsol(p);
			 me_list(2,p); break;
		case 3: lcsaison(p);
			me_list(3,p); break;
		case 4: lcmois(p);
			 me_list(4,p); break;
	} 	
}

/** @fn me_sty
* @details menu sans choix type de produit
* @param struct produit
* @return void
*/
void me_sty (prod* p)
{
	int choix;

	printf("CHOISIR UN OPTION :\n");
	printf("1) List de produit");
	printf("2) Caracteristique du sol");
	printf("3) Saison");
	printf("4) Mois");
	printf("5) Je neglise tout les autres choix");
	
	while (1)
	{
		printf("Entrer votre choix : ");
		scanf("%d",&choix);
		if (choix >= 1 && choix <= 5) {
			break;
		}
		printf("choix incorrect !!!\n");
		printf("R");
	}

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lcsol(p);
			me_list(2,p); break;
		case 3:lcsaison(p);
			 me_list(3,p); break;
		case 4: lcmois(p);
			 me_list(4,p); break;
		case 5: anadon(p); break;
	}
}

/** @fn me_sso
* @details menu sans choix de sol
* @param struct produit
* @return void
*/
void me_sso (prod* p) 
{
	int choix;

	printf("CHOISIR UN OPTION :\n");
	printf("1) List de produit");
	printf("2) Type de produit"); 
	printf("3) Saison");
	printf("4) Mois");
	printf("5) Je neglise tout les autres choix");
	
	while (1)
	{
		printf("Entrer votre choix : ");
		scanf("%d",&choix);
		if (choix >= 1 && choix <= 5) {
			break;
		}
		printf("choix incorrect !!!\n");
		printf("R");
	}

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lctype(p);
			me_list(1,p); break;
		case 3:lcsaison(p);
			 me_list(3,p); break;
		case 4: lcmois(p);
			 me_list(4,p); break;
		case 5: anadon(p); break;
	}

}

/** @fn me_ssa
* @details menu sans choix de saison
* @param struct produit
* @return void
*/
void me_ssa (prod* p) 
{
	int choix;

	printf("CHOISIR UN OPTION :\n");
	printf("1) List de produit");
	printf("2) Type de produit"); 
	printf("3) Sol");
	printf("4) Mois");
	printf("5) Je neglise tout les autres choix");
	
	while (1)
	{
		printf("Entrer votre choix : ");
		scanf("%d",&choix);
		if (choix >= 1 && choix <= 5) {
			break;
		}
		printf("choix incorrect !!!\n");
		printf("R");
	}

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lctype(p);
			me_list(1,p); break;
		case 3:  lcsol(p);
			me_list(2,p); break;
		case 4: lcmois(p);
			 me_list(4,p); break;
		case 5: anadon(p); break;
	}

}

/** @fn me_smo
* @details menu sans choix de mois
* @param struct produit
* @return void
*/
void me_smo (prod* p) 
{
	int choix;

	printf("CHOISIR UN OPTION :\n");
	printf("1) List de produit");
	printf("2) Type de produit"); 
	printf("3) Sol");
	printf("4) Mois");
	printf("5) Je neglise tout les autres choix");
	
	while (1)
	{
		printf("Entrer votre choix : ");
		scanf("%d",&choix);
		if (choix >= 1 && choix <= 5) {
			break;
		}
		printf("choix incorrect !!!\n");
		printf("R");
	}

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lctype(p);
			me_list(1,p); break;
		case 3: lcsol(p);
			 me_list(2,p); break;
		case 4: lcmois(p);
			 me_list(4,p); break;
		case 5: anadon(p); break;
	}

}

/** @fn me_ssamo
* @details menu sans choix de saison et  mois
* @param struct produit
* @return void
*/
void me_ssamo (prod* p) 
{
	int choix; break;

	printf("CHOISIR UN OPTION :\n");
	printf("1) List de produit");
	printf("2) Type de produit"); 
	printf("3) Sol");
	printf("4) Je neglise tout les autres choix");
	
	while (1)
	{
		printf("Entrer votre choix : ");
		scanf("%d",&choix);
		if (choix >= 1 && choix <= 5) {
			break;
		}
		printf("choix incorrect !!!\n");
		printf("R");
	}

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lctype(p);
			me_list(1,p); break;
		case 3: lcsol(p);
			 me_list(2,p); break;
		case 4: anadon(p); break;
	}

}

/** @fn me_styso
* @details menu sans choix de saison et  mois
* @param struct produit
* @return void
*/
void me_styso (prod* p) 
{
	int choix;

	printf("CHOISIR UN OPTION :\n");
	printf("1) List de produit");
	printf("2) Saison"); 
	printf("3) Mois");
	printf("4) Je neglise tout les autres choix");
	
	while (1)
	{
		printf("Entrer votre choix : ");
		scanf("%d",&choix);
/** @fn me_styso
* @details menu sans choix de saison et  mois
* @param struct produit
* @return void
*/
void me_styso (prod* p)
		if (choix >= 1 && choix <= 5) {
			break;
		}
		printf("choix incorrect !!!\n");
		printf("R");
	}

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: me_list(3,p); break;
		case 3: lcmois(p);
			 me_list(4,p); break;
		case 4: anadon(p); break;
	}

}

/** @fn me_stysamo
* @details menu sans choix de saison et  mois
* @param struct produit
* @return void
*/
void me_stysamo (prod* p) 
{
	int choix;

	printf("CHOISIR UN OPTION :\n");
	printf("1) List de produit");
	printf("2) Sol");
	printf("3) Je neglise tout les autres choix");
	
	while (1)
	{
		printf("Entrer votre choix : ");
		scanf("%d",&choix);
		if (choix >= 1 && choix <= 5) {
			break;
		}
		printf("choix incorrect !!!\n");
		printf("R");
	}

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2:lcsol(p);
			me_list(2,p); break;
		case 3: anadon(p); break;
	}

}

/** @fn me_ssosamo
* @details menu sans choix de saison et  mois
* @param struct produit
* @return void
*/
void me_ssosamo (prod* p) 
{
	int choix;

	printf("CHOISIR UN OPTION :\n");
	printf("1) List de produit");
	printf("2) Type de produit");
	printf("3) Je neglise tout les autres choix");
	
	while (1)
	{
		printf("Entrer votre choix : ");
		scanf("%d",&choix);
		if (choix >= 1 && choix <= 5) {
			break;
		}
		printf("choix incorrect !!!\n");
		printf("R");
	}

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lctype(p);
			me_list(1,p); break;
		case 3: anadon(p); break;
	}

}
