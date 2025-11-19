#include<stdio.h>
#include<stdlib.h>

#ifndef PROD_H
#include"prod.h"
#endif

#ifndef NAC_H
#include"nac.h"
#endif

int rdata(prod choix, lprod **res)
{
    prod *data;
    lprod *head = res[0];
    lprod *lp = *res;
    analyse_type(&choix, &data);
    venull(data, "data", "rdata");
    cp_list(data, &lp);

    venull(res[0][0].s, "res", "rdata");
    head = *res;
    if (choix.mois[0] != 0) {
	analyse_mois(&choix, res);
	head = *res;
    }

    if (choix.sais[0] != 0) {
	analyse_saison(&choix, res);
	head = *res;
    }

    if (choix.sol[0] != 0) {
	analyse_sol(&choix, res);
    }
    return 1;
}

int analyse_type(prod *p, prod **r)
{
    switch (p->type) {
    case 1:
	printf("céréal : pas disponible\n");
	return 1;
    case 2:
	printf("légumineuse : pas disponible\n");
	return 2;
    case 3:
	printf("fruit\n");
	return 3;
    case 4:
	printf("legume : pas disponible\n");
	return 4;
    case 5:
	*r = tubercule();
	venull(*r, "r tubrercul", "analyse_type");
	return 5;
    case 6:
	*r = racine();
	venull(*r, "r racine", "analyse_type");
	return 6;
    default:
	printf("indefine\n");
	return -1;
    }
}


int cp_list(prod *p, lprod **lp)
{
    int n = p->ntp;
    for (int i = 0; i < n; i++) {
	lp[0][0].c = malloc(sizeof(prod));
	lp[0][0].c[0] = *(p + i);
	lp[0][0].s = malloc(sizeof(lprod));
	lp[0] = lp[0][0].s;
    }
    return 0;
}

int analyse_mois(prod *p, lprod **res)
{
    int n = 12;
    lprod *l = *res;
    lprod *prev;		// pointeur precedent
    lprod *cur;			//pointeur courant

    //analyse tete
    while (1) {
	for (int i = 0; i <= n; i++) {
	    if (l->c->mois[i] == p->mois[0]) {
		*res = l;
		goto quit;
	    }
	}

	if (l->s != NULL && l->s->c != NULL)
	    l = l->s;
	else {
	    fprintf(stderr, "Pas de produit chercher\n");
	    exit(0);
	}
      quit:break;
    }

    prev = *res;
    while (1) {
	if (prev->s != NULL && prev->s->c != NULL)
	    cur = prev->s;
	else
	    return 0;

	for (int i = 0; i < n; i++) {
	    if (cur->c->mois[i] == p->mois[0]) {
		prev = cur;
		continue;
	    }
	}

	if (cur->s == NULL) {
	    prev->s = NULL;
	    return 0;
	} else
	    prev->s = cur->s;

    }
}

int analyse_sol(prod *p, lprod **res)
{
    int n = 11;
    lprod *l = *res;
    lprod *prev;		// pointeur precedent
    lprod *cur;			//pointeur courant

    //analyse tete
    while (1) {
	for (int i = 0; i <= n; i++) {
	    printf("sol=%d", l->c->sol[i]);
	    if (l->c->sol[i] == p->sol[0]) {
		*res = l;
		goto quit;
	    }
	}

	if (l->s != NULL && l->s->c != NULL)
	    l = l->s;
	else {
	    fprintf(stderr, "Pas de produit chercher\n");
	    exit(0);
	}

      quit:break;
    }
    prev = l;
    while (1) {
	if (prev->s != NULL && prev->s->c != NULL)
	    cur = prev->s;
	else
	    return 0;
	for (int i = 0; i < n; i++) {
	    if (cur->c->sol[i] == p->sol[0]) {
		prev = cur;
		continue;
	    }
	}

	if (cur->s == NULL) {
	    prev->s = NULL;
	    return 0;
	} else
	    prev->s = cur->s;
    }

}

int analyse_saison(prod *p, lprod **res)
{
    int n = 5;
    lprod *l = *res;
    lprod *prev;		// pointeur precedent
    lprod *cur;			//pointeur courant

    //analyse tete
    while (1) {
	for (int i = 0; i <= n; i++) {
	    if (l->c->sais[i] == p->sais[0]) {
		*res = l;
		goto quit;
	    }
	}

	if (l->s != NULL && l->s->c != NULL)
	    l = l->s;
	else {
	    fprintf(stderr, "Pas de produit chercher\n");
	    exit(0);
	}
      quit:break;
    }

    prev = *res;
    while (1) {
	if (prev->s != NULL && prev->s->c != NULL)
	    cur = prev->s;
	else
	    return 0;
	for (int i = 0; i < n; i++) {
	    if (cur->c->sais[i] == p->sais[0]) {
		prev = cur;
		continue;
	    }
	}

	if (cur->s == NULL) {
	    prev->s = NULL;
	    return 0;
	} else
	    prev->s = cur->s;
    }

}

void venull(void *p, char pnom[], char fonct[])
{
    if (p == NULL) {
	fprintf(stderr, "%s est encore NULL dans le fonction %s\n", pnom,
		fonct);
	exit(1);
    }
}
