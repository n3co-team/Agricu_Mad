#define ANAL_H
#ifndef PROD_H
#include"prod.h"
#endif
/** @fn verifie l'existance de l'id de mois dans un donnée de produit
* @return entier
*/
int mois_d(prod* p, int mois);

/** @fn verifie l'existance de l'id de type dans un donnée de produit
* @return entier
*/
int type_d(prod* p, int type);

/** @fn verifie l'existance de l'id de saison dans un donnée de produit
* @return entier
*/
int saison_d(prod* p, int saison);

/** @fn verifie l'existance de l'id de sol dans un donnée de produit
* @return entier
*/
int sol_d(prod* p,int sol);

/** @fn analyse le base de donnne 
* @param le choix de menu et le liste de resultat obtenu
* @return vide
*/
void analyse_bd(prod* choix, lprod* result);

void venull(void *pointer, char pointer_nameu[], char fonction_name[]);
