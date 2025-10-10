#include<stdio.h>
#include<stdlib.h>
#include"prod.h"
#include"anal.h"

// analyse de saison desiré
int saison_d(prod* p, int i) {
	int j;
	for (j=0; j<3; j++) {
		if (p->sais[j] == i) {
			return 1;
		}
	}
	return -1;
}

// verfication de mois sur un produit
int mois_d(prod* p, int i) {
	int j;
	for (j=0; j<12; j++) {
		if (p->mois[j] == i) {
			return 1;
		}
	}
	return -1;
}

// verfication de type sur un produit
int type_d(prod* p, int i) {
	if (p->type == i) {
		return 1;
	}
	return -1;
}

// verfication de sol favorable sur un produit
int sol_d(prod* p,int i) 
{
	int j;
	for (j=0; j<3; j++) {
		if (p->sol[j] == i) {
			return 1;
		}
	}
	return -1;
}

// copie le contenu du tableau de struct prod dans struct lprod
void tr_lprod(prod* p, lprod* lp) 
{
	int i=0;
	prod* pt = p;
	lprod* lpt = lp;
	if (lp == NULL) {
		lp = malloc(sizeof(lp));
		lp->c = p;
	}
	while( pt != NULL) {
		lpt->s = malloc(sizeof(lprod));
		lpt=lpt->s;
		lpt->c=pt;
		pt++;
	}
}

lprod* analyse_type(prod* p)
{
	lprod* lp;	// pointeur pour liste chainer de produit
	lprod* der;	//pointeur pour le dernier liste
	prod* pt;	// pointeur pour recuperé le donner de produit
	switch (p->type) {
                case 1: printf("céréal : pas disponible"); 
			break;
                case 2: printf("légumineuse : pas disponible"); 
			break;
                case 3: printf("fruit"); 
			break;
                case 4: printf("legume : pas disponible"); 
			break;
                case 5: pt = tubercule();
			tr_lprod(pt,lp);
			free(pt);
			return lp; 
			break;
                case 6: printf(":racine : pas disponible"); 
			break;
                default: printf("indefine"); 
			break;
        }
}

int supp_lprod_cont(lprod* lp)
{
	lprod* lpt = lp->s;	//temporaire
	if (lpt->s != NULL) {
		lp->s = lp->s->s;
		free(lpt);
		return 1;
	}
	else {
		free(lpt);
		return 2;
	}
}
// analyse de base de donner pour le mois
void analyse_mois(prod *p, lprod* lp)
{
	int mois = p->mois[0];
	lprod* lpt = lp;
	lprod* lptt;
	prod* pt = lpt->c;
	while (mois_d(pt,mois) != 1) {
		if (lpt->s != NULL) {
			lp=lpt->s;
			free(lpt);
			lpt=lp;
			pt = lpt->c;
		}
		else {
			fprintf(stderr,"Analyse de mois echouéé : donc pas de produit correspondant");
			exit (1);
		}
	}
	
	while (lpt != NULL) {
		if (mois_d(pt,mois) != 1) {
			if(supp_lprod_cont(lpt) == 2) {
				break;
			}
			else {
				continue;
			}
		}
		else {
			break;
		}

		lpt = lpt->s;
		pt = lpt->c;
	}
}

// analyse de base de donner pour le saison
void analyse_saison(prod *p, lprod* lp)
{
	int saison = p->sais[0];
	lprod* lpt = lp;
	lprod* lptt;
	prod* pt = lpt->c;
	while (saison_d(pt,saison) != 1) {
		if (lpt->s != NULL) {
			lp=lpt->s;
			free(lpt);
			lpt=lp;
			pt = lpt->c;
		}
		else {
			fprintf(stderr,"Analyse de mois echouéé : donc pas de produit correspondant");
			exit (1);
		}
	}
	
	while (lpt != NULL) {
		if (saison_d(pt,saison) != 1) {
			if(supp_lprod_cont(lpt) == 2) {
				break;
			}
			else {
				continue;
			}
		}
		else {
			break;
		}

		lpt = lpt->s;
			pt = lpt->c;
	}
}

// analyse de base de donner pour le sol
void analyse_sol(prod *p, lprod* lp)
{
	int sol = p->sol[0];
	lprod* lpt = lp;
	lprod* lptt;
	prod* pt = lpt->c;
	while (sol_d(pt,sol) != 1) {
		if (lpt->s != NULL) {
			lp=lpt->s;
			free(lpt);
			lpt=lp;
			pt = lpt->c;
		}
		else {
			fprintf(stderr,"Analyse de mois echouéé : donc pas de produit correspondant");
			exit (1);
		}
	}
	
	while (lpt != NULL) {
		if (sol_d(pt,sol) != 1) {
			if(supp_lprod_cont(lpt) == 2) {
				break;
			}
			else {
				continue;
			}
		}
		else {
			break;
		}

		lpt = lpt->s;
			pt = lpt->c;
	}
}

void analyse_bd(prod* p, lprod* lp)
{
	lp = analyse_type(p);
	analyse_mois(p,lp);	
	analyse_saison(p,lp);	
	analyse_sol(p,lp);	
}

