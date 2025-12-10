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
	int i=0; //p miova current
	int choix;
	lprod* p = *donne;  //donne[0]
	
	printf("\n\n\e[1mIreo vokatra mifanaraka amin'ny safidinao :\e[0m\n");
	//i=0;
	lprod* temp = p;
	while(temp != NULL  && temp ->c != NULL) {
		i++;
		printf("%d) %s\n",i,temp ->c->nom);

		temp = temp->s;
	}
	
	printf("\nMisafidiana laharana\n ");
	choix=choix_car(1,i);
	choix = choix - 1;
	temp = *donne;
	i=0;
	while (1) {
		if(choix==i) {
			infprod(p[0].c[0]);
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
	printf("Mombamomban'ny %s :\n\n",p.nom);
	printf("%s dia %s favoly amin'ny tany ",p.nom,c_type_prod(p.type));
	for (i = 0; i < 11; i++) {
		ref=p.sol[i];
		if(i < 0 || i > 11 || ref == 0) {
			break;
		}
		printf("%s", c_sol(ref));
		printf(",");
	}

	printf(" amin'ny toetr'andro ");
	for (i = 0; i < 5; i++) {
		ref=p.sais[i];
		if(ref < 0 || ref > 5 || ref == 0) {
			break;
		}
		printf("%s", c_saison(ref));
				printf(",");
	}

	printf(".\nMatetika ambolena  madritran'ny volana ");
	for (i = 0; i < 12; i++) {
		ref=p.mois[i];
		if(ref < 0 || ref > 12 || ref == 0) {
			break;
		}
		printf("%s", c_mois(ref));
		printf(",");
	}
	printf(" fa miankina amin'ny toetr'andro.\n");

	printf("\n========================================================\n");
}


