/** @file conven.c
*@brief programme qui contient les definitions des conventions sur les caracteristiques des produits
*@author Windrick
*/

#include<stdio.h>
#include<string.h>
#include"conven.h"

/** @fn cette fonction qui convertie la saison int ent char
 *  @param int
 *  @return char*
 */
char* c_saison(int i)
{
	char s[10];
	switch (i) {
		case 1: strcpy(s,"été"); break;
		case 2: strcpy(s,"hiver"); break;
		case 3: strcpy(s,"autome"); break;
		case 4: strcpy(s,"printemps"); break;
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
		case 3: strcpy(t,"tubercule"); break;
		case 4: strcpy(t,"racine"); break;
		case 5: strcpy(t,"fruit"); break;
		case 6: strcpy(t,"legume"); break;
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
		case 6: strcpy(m,"Juillet"); break;
		case 6: strcpy(m,"Août"); break;
		case 6: strcpy(m,"Septembre"); break;
		case 6: strcpy(m,"Octobre"); break;
		case 6: strcpy(m,"Novembre"); break;
		case 6: strcpy(m,"Decembre"); break;
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
	char s[15];
	switch (i) {
		case 1: strcpy(s,"argileux"); break;
		case 2: strcpy(s,"limoneux"); break;
		case 3: strcpy(s,"himufère"); break;
		default: strcpy(s,"indefine"); break;
	}
	
	char* res = malloc(strlen(s)+1);	//resultat
	strcpy(res,s);	

	return res;
}
