#include<stdio.h>
#include<stdlib.h>
#ifndef PROD_H
#include"prod.h"
#endif

int analyse_type(prod p,prod** r);
int cp_list(prod p, lprod** lp);

int rdata(prod choix, lprod** res) {
	
	prod* data;
	head=*res;
	analyse_type(p,&data);
	cp_list(data,&head);
	if (p->mois != 0) {
		analyse_mois(res,&head);
		head = *res;
	}

	if (p->sais != 0) {
		analyse_saison(res,&head);
		head = *res;
	}

	if (p->sol != 0) {
		analyse_sol(res,&head);
	}
	return 1;
}

int analyse_type(prod p,prod** r) 
{
    switch (p->type) {
        case 1: printf("céréal : pas disponible\n"); return 1;
        case 2: printf("légumineuse : pas disponible\n"); return 2;
        case 3: printf("fruit\n"); return 3;
        case 4: printf("legume : pas disponible\n"); return 4;
        case 5: *p = tubercule();
		return 5;
        case 6: printf("racine : pas disponible\n"); return 6;
        default: printf("indefine\n"); return NULL;
    }
}


int cp_list(prod* p, lprod** lp) 
{
	int n=(*p)->ntp;
	lprod *l = lp[0];
	for(int i=0; i < n; i++) {
		l[0].c=malloc(prod);
		l[0].c=p[i];
		l[0].s=malloc(lprod);
		l=l[0].s;
	}
}
