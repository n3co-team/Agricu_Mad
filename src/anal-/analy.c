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
	int j;
	for (j=0, j<3, j++) {
		if (p->sol[j] == i) {
			return 1;
		}
	}
	return -1;
}

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


