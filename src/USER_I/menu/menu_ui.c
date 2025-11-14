/** 
* @file menu_ui.c 
* @brief fichier contient les fonctions de menu
* @author Windrick
*/

#include<stdio.h>
#include<stdlib.h>

#ifndef MENU_UI_H
#include"menu_ui.h"
#endif

#ifndef ANAL_H
#include"anal.h"
#endif

#ifndef CONVEN_H
#include"conven.h"
#endif

/** @fn menu_list
* @details fonction qui contient les appel de fonction des menu
* @return void
*/

void me_list (int i,prod *p) {
	// init_choix(p);
	switch (i) {
		case 0: me_pri(p); break;
		case 1: me_sty(p); break;
		case 2: me_sso(p); break;
		case 3: me_styso(p); break;	// sans type de produit et sol
		case 4: me_ssamo(p); break; // sans saison et mois
		case 5: me_stysamo(p); break; // sans type de produit, saison et mois
		case 6: me_ssosamo(p); break; // sans sol, saison et mois
		default: fprintf (stderr,"Erreur de menu\n");
			exit (1); break;
	}
}

void init_choix(prod** p) 
{
    *p = malloc(sizeof(prod));
	if (*p == NULL) {
		fprintf(stderr, "Allocation error\n");
		exit(1);
	}
	//iniitiation type
	int i;
	(*p)->type = 0;

	//initiation de sol
	for(i = 0; i < 11; i++) {
		(*p)->sol[i]=0;
	}

	//initiation de saison	
	for(i = 0; i < 4; i++) {
		(*p)->sais[i] = 0;
	}
	//initiation de mois
	for(i = 0; i < 12; i++) {
		(*p)->mois[i] = 0;
	}
	printf("Initialisation  de choix reussie\n");
}
/** @fn me_pri
* @details fonction pour menu principal
* @param struct produit
* @return void
*/
void me_pri(prod* p)
{
	int choix;
	init_choix(&p);

	printf("\nCHOISIR UN OPTION :\n");
	printf("1) Type de produit\n");
	printf("2) Caracteristique du sol\n");
	printf("3) Saison\n");
	printf("4) Mois\n");
	printf("0) à propos\n ");
	
	choix = choix_car(1,5);

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1:lctype(p);
			 me_list(1,p); break;
		case 2: lcsol(p);
			 me_list(2,p); break;
		case 3: lcsaison(p);
			me_list(4,p); break;
		case 4: lcmois(p);
			 me_list(4,p); break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
	} 	
}

/** @fn me_sty
* @details menu sans choix types de produits
* @param struct produit
* @return void
*/
void me_sty (prod* p)
{
	int choix;

	printf("\nCHOISIR UN OPTION :\n");
	printf("1) List de produit\n");
	printf("2) Caracteristique du sol\n");
	printf("3) Saison\n");
	printf("4) Mois\n");
//	printf("5) Je neglige tout les autres choix\n");
	
	choix = choix_car(1,4);

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lcsol(p);
			me_list(3,p); break;
		case 3:lcsaison(p);
			 me_list(5,p); break;
		case 4: lcmois(p);
			 me_list(5,p); break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
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

	printf("\nCHOISIR UN OPTION :\n");
	printf("1) List de produit\n");
	printf("2) Type de produit\n"); 
	printf("3) Saison\n");
	printf("4) Mois\n");
//	printf("5) Je neglise tout les autres choix\n");
	
	choix = choix_car(1,4);

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lctype(p);
			me_list(3,p); break;
		case 3:lcsaison(p);
			 me_list(6,p); break;
		case 4: lcmois(p);
			 me_list(6,p); break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
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

	printf("\nCHOISIR UN OPTION :\n");
	printf("1) List de produit\n");
	printf("2) Type de produit\n"); 
	printf("3) Sol\n");
//	printf("4) Mois\n");
//	printf("5) Je neglise tout les autres choix\n");
	
	choix = choix_car(1,3);

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lctype(p);
			me_list(5,p); break;
		case 3:  lcsol(p);
			me_list(6,p); break;
	//	case 4: lcmois(p);
	//		 me_list(4,p); break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
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

	printf("\nCHOISIR UN OPTION :\n");
	printf("1) List de produit");
	printf("2) Type de produit"); 
	printf("3) Sol");
//	printf("4) Mois");
//	printf("5) Je neglise tout les autres choix");
	
	choix = choix_car(1,3);

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lctype(p);
			me_list(5,p); break;
		case 3: lcsol(p);
			 me_list(6,p); break;
//		case 4: lcmois(p);
//			 me_list(4,p); break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
	}

}

/** @fn me_ssamo
* @details menu sans choix de saison et  mois
* @param struct produit
* @return void
*/
void me_ssamo (prod* p) 
{
	int choix;

	printf("\nCHOISIR UN OPTION :\n");
	printf("1) List de produit\n");
	printf("2) Type de produit\n"); 
	printf("3) Sol\n");
//	printf("4) Je neglise tout les autres choix\n");
	
	choix = choix_car(1,3);	

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lctype(p);
			me_list(5,p); break;
		case 3: lcsol(p);
			 me_list(6,p); break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
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

	printf("\nCHOISIR UN OPTION :\n");
	printf("1) List de produit\n");
	printf("2) Saison\n"); 
	printf("3) Mois\n");
//	printf("4) Je neglise tout les autres choix\n");
	
	choix = choix_car(1,3);	

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lcsaison(p);
			prod_list(p); break;
		case 3: lcmois(p);
			 prod_list(p); break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
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

	printf("\nCHOISIR UN OPTION :\n");
	printf("1) List de produit\n");
	printf("2) Sol\n");
//	printf("3) Je neglise tout les autres choix\n");
	
	choix = choix_car(1,2);	

	switch (choix) {
		case 1: prod_list(p); break;
		case 2:lcsol(p);
			prod_list(p); break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
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

	printf("\nCHOISIR UN OPTION :\n");
	printf("1) List de produit\n");
	printf("2) Type de produit\n");
//	printf("3) Je neglise tout les autres choix\n");
	
	choix = choix_car(1,2);	

	switch (choix) {
		case 1: prod_list(p); break;
		case 2: lctype(p);
			prod_list(p); break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
	}

}

//verification de choix	
void verification_choix(prod* p) {
	char* MOIS=c_mois(p->mois[0]);
	char* SAISON=c_saison(p->sais[0]);
	char* TYPE=c_type_prod(p->type);
	char* SOL=c_sol(p->sol[0]);
	printf("\nVerifier votre choix :\n");
	printf("TYPE=%s\n",TYPE);
	printf("SOL=%s\n",SOL);
	printf("SAISON=%s\n",SAISON);
	printf("MOIS=%s\n",MOIS);

	if (MOIS != NULL)
	free(MOIS);
	if (SAISON != NULL)
	free(SAISON);
	if (TYPE != NULL)
	free(TYPE);
	if (SOL != NULL)
	free(SOL);
	printf("Tout est correct? ('ctrl+c' pour annulé) ");
//	exit (1);
}

//Menu de produit obtenu
void prod_list(prod* p) {
	lprod* lp = NULL;
	lprod* lpt;
	int i=0;
	venull(p,"p","prod_list");
	 verification_choix(p);
	analyse_bd(p,&lp);
//	exit (1);
	lpt = lp;
	printf("\n\n\e[2mLes produits disponible par votre choix :\e[0m\n");
	i=0;
	while(true) {
		i++;
		printf("%d) %s\n",i,lpt->c->nom);
		
		if (lpt->s == NULL) {
			break;
		}

		lpt=lpt->s;
	}
	exit (1);
}


