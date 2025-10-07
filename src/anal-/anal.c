#include<stdio.h>
#include"prod.h"
#include<stdlib.h>

lprod* ana_type(prod* p)
{	
	lprod* res= malloc(sizeof(lprod));	// list chainée pour produit trouver 
	res = malloc (6*sizeof(prod*));
	switch (p->type) {
		case 1: printf("cereale n'est pas disponible");
			exit (1); break;
		case 2: printf("legumineuse n'est pas disponible");
			exit (1); break;
		case 3: printf("fruit n'est pas disponible");
			exit (1); break;
		case 4:	printf("legume n'est pas disponible");
			exit (1); break;
		case 5: //res->c = malloc(sizeof(prod*));
			res->c=tubercule();
			return res;
			break;
		case 6: printf("racine n'est pas disponible");
			exit (1); break;
		defaut: printf("pas de type choisix"); break;
	}
}

lprod* ana_mois(prod* p, lprod* d) 
{
	int i = 0; 
	int mois = p->mois[0];
	lprod* tmp = d;
	lprod* res = malloc (sizeof(lprod));
	lprod* tete = res;
	prod* ptmp;

	if ( mois == 0 ) {
		while (tmp != NULL) {
			ptmp = tmp->c;
			while (ptmp != NULL) {
				res->c = malloc(sizeof(prod));
				res->c = ptmp;
				res->s = malloc(sizeof(lprod));
				ptmp++;
				res=res->s;
			}
		tmp = tmp->s;
		}
	}
	else {
		while (tmp != NULL) {
			ptmp = tmp->c;
			while (ptmp != NULL) {
				while ( ptmp->mois[i] <= 12 || ptmp->mois[i] != 0 ) {
					if ( ptmp->mois[i] == mois ) {
						res->c = ptmp;
						res->s = malloc(sizeof(lprod));
						res = res->s;
					}
				}
				ptmp++;
			}
			tmp=tmp->s;
		}
	}
	return tete;
		
}

lprod* ana_saison(prod* p, lprod* d) {
	int saison=p->sais;
	lprod* tete = d;
	lprod* tmp = ;
	if (saison == 0) {
		return d
	}
	else {
		while(d->s != NULL) {
		if (d->c->sais != saison) {
				
		}	
	}
	
