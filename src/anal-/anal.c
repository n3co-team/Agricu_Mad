#include<stdio.h>
#include"prod.h"
#include<stdlib.h>

lprod* ana_type(prod* p)
{	
	lprod* res; 
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
		case 5: //res.c = malloc(sizeof(prod*));
			res.c=tubercule();
			return res;
			break;
		case 6: printf("racine n'est pas disponible");
			exit (1); break;
		defaut: printf("pas de type choisix"); break;
	}
}

prod** ana_mois(prod* p, lprod* d) 
{
	int mois = p->mois[0];
	prod* nd;	//nouveau donné
	while (ptr=NULL) {
		
	
	
}
