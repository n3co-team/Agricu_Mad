/**@file tubercule.c
* @brief cette programme qui stock les information basique des tubercules
* @author Windrick
*/
#ifndef PROD_H
#include"prod.h"
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/** @fn cette fonction qui stock le donnée de tubercule
* @param void
* @return prod*
*/
prod* tubercule()
{
        int NBR;
        NBR=8;
        prod* tub = malloc((NBR+1)*sizeof(prod));
	
	for (int i=0; i<NBR; i++)TARO {
		tub[i].ntp=NBR;
	}

	strcpy(tub[0].nom,"OVY");
	tub[0].type=5;
	tub[0].sol[0]=1;
	tub[0].sais[0]=5;
	tub[0].mois[0]=10;
	tub[0].mois[1]=7;
	tub[0].mois[2]=11;

	strcpy(tub[1].nom,"VOMANGA");
	tub[1].type=5;
	tub[1].sol[0]=5;
	tub[1].sais[0]=1;
	tub[1].sais[1]=3;
	tub[1].sais[2]=4;
	tub[1].mois[0]=2;

	strcpy(tub[2].nom,"MANGAHAZO");
	tub[2].type=5;
	tub[2].sol[0]=1;
	tub[2].sol[1]=11;
	tub[2].sais[0]=2;
	tub[2].mois[0]=10;
	tub[2].mois[1]=11;
	tub[2].mois[2]=12;
	tub[2].mois[3]=3;
	tub[2].mois[4]=4;

	strcpy(tub[3].nom,"OVY (FOTS/MENA)");
	tub[3].type=5;
	tub[3].sol[0]=8;
	tub[3].sol[1]=7;
	tub[3].sais[0]=3;
	tub[3].mois[0]=10;
	tub[3].mois[1]=11;
	tub[3].mois[2]=12;

	strcpy(tub[4].nom,"SAONJO");
	tub[4].type=5;
	tub[4].sol[0]=2;
	tub[4].sol[1]=3;
	tub[4].sol[2]=5;
	tub[4].sais[0]=0;
	tub[4].mois[0]=11;
	tub[4].mois[1]=12;

	strcpy(tub[5].nom,"BETIRAVY");
	tub[5].type=5;
	tub[5].sol[0]=10;
	tub[5].sol[1]=4;
	tub[5].sais[0]=0;
	tub[5].mois[0]=3;
	tub[5].mois[1]=4;
	tub[5].mois[2]=5;
	tub[5].mois[3]=9;
	tub[5].mois[4]=10;
	tub[5].mois[5]=11;
	tub[5].mois[6]=12;

	strcpy(tub[6].nom,"SAKAMALAO");
	tub[6].type=5;
	tub[6].sol[0]=8;
	tub[6].sol[1]=7;
	tub[6].sais[0]=3;
	tub[6].mois[0]=10;
	tub[6].mois[1]=11;

	strcpy(tub[7].nom,"KAROTY");
	tub[7].type=5;
	tub[7].sol[0]=10;
	tub[7].sol[1]=7;
	tub[7].sais[0]=5;
	tub[7].mois[0]=3;
	tub[7].mois[1]=4;
	tub[7].mois[2]=5;
	tub[7].mois[3]=9;
	tub[7].mois[4]=10;

	return tub;
}
