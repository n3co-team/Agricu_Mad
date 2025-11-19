#include<stdio.h>
#include<stdlib.h>

#ifndef PROD_H
#include"prod.h"
#endif

#ifndef MENU_UI_H
#include"menu_ui.h"
#endif

#ifndef CONVEN_H
#include"conven.h"
#endif

#ifndef NAC_H
#include"nac.h"
#endif

void resultf(lprod** donne) {
	int i=1;
	int choix;
	lprod* p=donne[0];
	
	printf("\n\n\e[1mLes produits disponible par votre choix :\e[0m\n");
	i=0;
	while(1) {
		i++;
		printf("%d) %s\n",i,p->c->nom);
		
		if (p->s == NULL || p->s->c == NULL ) {
			break;
		}

		p=p->s;
	}
	
	printf("\nEntrer le numero de resultat: ");
	choix=choix_car(1,i);
	choix = choix - 1;
	p=donne[0];
	i=0;
	while (1) {
		if(choix==i) {
			venull(p->s[0].c,"p->s[0].c","resultf");
			infprod(p->s[0].c[0]);
			break;
		}
		if(p->s == NULL || p->s->c == NULL) {
			fprintf(stderr,"Erreur de generation de text\n");
			exit (1);
		}
		p=p->s;
		i++;
	}
}
			
void infprod(prod p)
{
	int i;
	int ref;
	
	printf("\n========================================================\n");
	printf("Information sur %s :\n\n",p.nom);
	printf("%s est un %s cultuve dans sol ",p.nom,c_type_prod(p.type));
	for (i = 0; i < 11; i++) {
		ref=p.sol[i];
		if(i < 0 || i > 11 || ref == 0) {
			break;
		}
		printf("%s", c_sol(ref));
		printf(",");
	}

	printf(" pendant saison ");
	for (i = 0; i < 5; i++) {
		ref=p.sais[i];
		if(ref < 0 || ref > 5 || ref == 0) {
			break;
		}
		printf("%s", c_saison(ref));
				printf(",");
	}

	printf(".\nPlus souvent on le cultive au mois du ");
	for (i = 0; i < 12; i++) {
		ref=p.mois[i];
		if(ref < 0 || ref > 12 || ref == 0) {
			break;
		}
		printf("%s", c_mois(ref));
		printf(",");
	}
	printf(" mais depend du saison.\n");

	printf("\n========================================================\n");
}

