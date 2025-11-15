#include<stdio.h>
#include<stdlib.h>

#ifndef PROD_H
#include"prod.h"
#endif

#ifndef NAC_H
#include"nac.h"
#endif

#ifndef ANAL_H
#include"anal.h"
#endif

int rdata(prod choix, lprod** res) {
	prod* data;
	lprod* head=res[0];
	lprod** lp=res;
	analyse_type(&choix,&data);
	venull(data,"data","rdata");
//	cp_list(data,res);

	int n=data->ntp;
	
		printf("%s\n",data[0].nom);
	int i;
	//lprod *l = lp;
	for(i=0; i < n; i++) {
		lp[0][0].c=malloc(sizeof(prod));
		printf("%s\n",data[i].nom);
		lp[0][0].c[0]=*(data+i);
		lp[0][0].s=malloc(sizeof(lprod));
		lp[0]=lp[0][0].s;
	}
	venull(res[0][0].s,"res","rdata");
	printf("%s\n",res[0][0].c[0].nom);
 	head=*res;
	if (choix.mois[0] != 0) {
		analyse_mois(&choix,res);
		head = *res;
	}

	printf("eto\n");	
	if (choix.sais[0] != 0) {
		analyse_saison(&choix,res);
		head = *res;
	}

	if (choix.sol[0] != 0) {
		analyse_sol(&choix,res);
	}
	return 1;
}

int analyse_type(prod* p,prod** r) 
{
    switch (p->type) {
        case 1: printf("céréal : pas disponible\n"); return 1;
        case 2: printf("légumineuse : pas disponible\n"); return 2;
        case 3: printf("fruit\n"); return 3;
        case 4: printf("legume : pas disponible\n"); return 4;
        case 5: *r = tubercule();
		venull(r,"r tubrercul","analyse_type");
		return 5;
        case 6: printf("racine : pas disponible\n"); return 6;
        default: printf("indefine\n"); return -1;
    }
}


int cp_list(prod* p, lprod** lp) 
{
	int n=p->ntp;
	//lprod *l = lp;
	for(int i=0; i < n; i++) {
		lp[0][0].c=malloc(sizeof(prod));
		lp[0][0].c[0]=*(p+i);
		lp[0][0].s=malloc(sizeof(lprod));
		lp[0]=lp[0][0].s;
	}
}

int analyse_mois(prod* p, lprod** res) {
	int n=12;
	lprod* l=*res;
	lprod* prev;	// pointeur precedent
	lprod* cur;	//pointeur courant

	//analyse tete
	while(true) {
		for(int i=0; i <= n; i++) {
			if(l->c->mois[i] == p->mois[0]) {
				*res=l;
				break;
			}
			if (i+1==n || l->s == NULL) {
				fprintf(stderr,"Pas de produit chercher\n");
				exit (0);
			}
		}
		l=l->s;
	}

	prev=l;
	while(true) {
		if (prev->s != NULL)
			cur=prev->s;
		else
			return 0;

		for( int i = 0; i< n; i++) {
			if(cur->c->mois[i] == p->mois[0]) {
				prev=cur;
				continue;
			}
		}
		
		if(cur->s == NULL) {
			prev->s=NULL;
			return 0;
		}
		else
			prev->s=cur->s;
	}
}

int analyse_sol(prod* p, lprod** res) {
	int n=11;
	lprod* l=*res;
	lprod* prev;	// pointeur precedent
	lprod* cur;	//pointeur courant

	//analyse tete
	while(true) {
		for(int i=0; i <= n; i++) {
			if(l->c->sol[i] == p->sol[0]) {
				*res=l;
				break;
			}

			if (i+1==n || l->s == NULL) {
				fprintf(stderr,"Pas de produit chercher\n");
				exit (0);
			}
		}
		
		l=l->s;
	}
	prev=l;
	while(true) {
		if (prev->s != NULL)
			cur=prev->s;
		else
			return 0;
		for( int i=0; i< n; i++) {
			if(cur->c->sol[i] == p->sol[0]) {
				prev=cur;
				continue;
			}
		}
		
		if(cur->s == NULL) {
			prev->s=NULL;
			return 0;
		}
		else
			prev->s=cur->s;
	}

}

int analyse_saison(prod* p, lprod** res) {
	int n=5;
	lprod* l=*res;
	lprod* prev;	// pointeur precedent
	lprod* cur;	//pointeur courant

	//analyse tete
	while(true) {
		for(int i=0; i <= n; i++) {
			if(l->c->sais[i] == p->sais[0]) {
				*res=l;
				break;
			}
			if (i+1==n || l->s == NULL) {
				fprintf(stderr,"Pas de produit chercher\n");
				exit (0);
			}
		}
		l=l->s;
	}

	prev=l;
	while(true) {
		if (prev->s != NULL)
			cur=prev->s;
		else
			return 0;
		for( int i=0; i< n; i++) {
			if(cur->c->sais[i] == p->sais[0]) {
				prev=cur;
				continue;
			}
		}
		
		if(cur->s == NULL) {
			prev->s=NULL;
			return 0;
		}
		else
			prev->s=cur->s;
	}

}

