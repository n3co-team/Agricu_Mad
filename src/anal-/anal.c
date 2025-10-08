#include<stdio.h>
#include"prod.h"
#include<stdlib.h>
#include"anal.h"

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

// analyse de donnée saison
lprod* ana_saison(prod* p, lprod* d) {
	int saison=p->sais;
	lprod* tete = d;
	lprod* tmp = ;
	if (saison == 0) {
		return d
	}
	else {
		if (d->c->mois)
		while(d->s != NULL) {
			if (saison_d(d->c, saison) != 1) {
				d=d->s;
			}
			else {
				tmp=d;
				d=d->s;
				free(tmp);
				
			}
		}	
	}
}

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

int mois_d(prod* p, int i) {
	int j;
	for (j=0; j<12; j++) {
		if (p->mois[j] == i) {
			return 1;
		}
	}
	return -1;
}

int type_d(prod* p, int i) {
	if (p->type == i) {
		return 1;
	}
	return -1;
}

int sol_d(prod* p,int i) {
	for (j=0, j<3; j++) {
		if (p->sol[j] == i) {
			return 1;
		}
	}
	return -1;
}