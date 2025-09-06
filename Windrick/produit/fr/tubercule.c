#include"prod.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/** @fn cette fonction qui stock le donnée de tubercule
 * @param void
 * @return prod*
 */
prod* tubercule() 
{
	int n = 4;
	prod* tub = malloc(n*sizeof(prod));

	strcpy(tub[0]->nom,"Pomme de terre");
	tub[0]->type = 6;
	tub[0]->sol[0] = 0;
	tub[0]->mois[3] = 1;
	tub[0]->mois[0] = 2;
	tub[0]->mois[1] = 3;
	tub[0]->mois[1] = 4;
	tub[0]->mois[1] = 5;
	tub[0]->mois[1] = 10;
	tub[0]->mois[1] = 11;
	tub[0]->mois[2] = 12;
	tub[0]->sais[0] = 1;
	tub[0]->sais[0] = 2;
}
