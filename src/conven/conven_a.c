/** @file conven.c
*@brief programme qui contient les definitions des conventions sur les caracteristiques des produits & conversion
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"conven.h"

/** @fn cette fonction qui convertie la saison int ent char
 *  @param int
 *  @return char*
 */
char* c_saison(int i) {
    char s[50];
    switch (i) {
        case 1: strcpy(s,"Froid"); break;
        case 2: strcpy(s,"Chaud"); break;
        case 3: strcpy(s,"Pluie"); break;
        case 4: strcpy(s,"sec"); break;
        case 5: strcpy(s,"tempéré"); break;
        default: strcpy(s,"non définie"); break;
    }

    char* res = malloc(strlen(s) + 1); // result en chaine
    if (res == NULL) {
        fprintf(stderr, "Erreur de l'allocation de memoire\n");
        exit(1); // Handle error appropriately
    }
    strcpy(res, s);
    return res;
}


/** @fn cette fonction qui convertie le type de produit int ent char
 *  @param int
 *  @return char*
 */
char* c_type_prod(int i)
{
	char t[15];
	switch (i) {
		case 1: strcpy(t,"céréal"); break;
		case 2: strcpy(t,"légumineuse"); break;
		case 3: strcpy(t,"fruit"); break;
		case 4: strcpy(t,"legume"); break;
		case 5: strcpy(t,"tubercule"); break;
		case 6: strcpy(t,"racine"); break;
		default: strcpy(t,"indefine"); break;
	}
	
	char* res = malloc(strlen(t)+1);	//resultat
	strcpy(res,t);	

	return res;
}

/** @fn cette fonction qui convertie le mois int ent char
 *  @param int
 *  @return char*
 */
char* c_mois(int i)
{
	char m[15];
	switch (i) {
		case 1: strcpy(m,"Janvier"); break;
		case 2: strcpy(m,"Fevrier"); break;
		case 3: strcpy(m,"Mars"); break;
		case 4: strcpy(m,"Avril"); break;
		case 5: strcpy(m,"Mai"); break;
		case 6: strcpy(m,"Juin"); break;
		case 7: strcpy(m,"Juillet"); break;
		case 8: strcpy(m,"Août"); break;
		case 9: strcpy(m,"Septembre"); break;
		case 10: strcpy(m,"Octobre"); break;
		case 11: strcpy(m,"Novembre"); break;
		case 12: strcpy(m,"Decembre"); break;
		default: strcpy(m,"pas definie"); break;
	}
	
	char* res = malloc(strlen(m)+1);	//resultat
	strcpy(res,m);	

	return res;
}

/** @fn cette fonction qui convertie le type de sol int ent char
 *  @param int
 *  @return char*
 */
char* c_sol(int i)
{
	char s[50];
	switch (i) {
		case 1: strcpy(s,"Sableux"); break;
		case 2: strcpy(s,"Argileux"); break;
		case 3: strcpy(s,"Limoneux"); break;
		case 4: strcpy(s,"Humifere"); break;
		case 5: strcpy(s,"Humide"); break;
		case 6: strcpy(s,"Aquatique"); break;
		case 7: strcpy(s,"Meuble"); break;
		case 8: strcpy(s,"Riche"); break;
		case 9: strcpy(s,"Vaseux"); break;
		case 10: strcpy(s,"Léger"); break;
		case 11: strcpy(s,"Drainé"); break;
		default: strcpy(s,"pas definie"); break;
	}
	
	char* res = malloc(strlen(s)+1);	//resultat
	strcpy(res,s);	

	return res;
}
