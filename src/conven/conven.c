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
char* c_saison(int i)
{
	char s[50];
	switch (i) {
		case 1: strcpy(s,"pluie"); break;
		case 2: strcpy(s,"sans pluie"); break;
		case 3: strcpy(s,"equilibré (ni trop de pluie ni trop ensoleilé)"); break;
		default: strcpy(s,"indefinie"); break;
	}

	char* res = malloc(strlen(s)+1);	//resultat
	strcpy(res,s);	

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
		default: strcpy(m,"indefine"); break;
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
		case 1: strcpy(s,"gorgé d'eau"); break;
		case 2: strcpy(s,"assez d'eau"); break;
		case 3: strcpy(s,"normal(ni assez ni trop d'eau)"); break;
		default: strcpy(s,"indefine"); break;
	}
	
	char* res = malloc(strlen(s)+1);	//resultat
	strcpy(res,s);	

	return res;
}
