/** @file nac.h fichier d'entete des fonction d'analyse de donnee
 */

#define NAC_H

#ifndef PROD_H
#include"prod.h"
#endif

/** @fn rdata recupere le base de donnee convenable au choix de l'utilisateur
 * @return positive si reussit
 */
int rdata(prod choix, lprod** resultat);

/** @fn analyse_type fonction d'analyse le type de produit
 * @brief analyse le type et recupère le base de donne convenable à ce type
 * @return positive si succes
 */
int analyse_type(prod* p,prod** r);

/** @fn cp_list copier les donnees de tableau de struct prod dans struct listproduit
 * @fn copier les données recuperér par analyse_type dans un liste chainé lprod
 * @param choix donne en prod et le list vide lprod*
 * @return positive si succes
 */
int cp_list(prod* p, lprod** lp);

/** @fn analyse_mois analyse le choix du mois d'utilisateur et supprime les unitiles
 * @param choix de l'utilisateur et le base de donnee
 * @return positif si succes
 */
int analyse_mois(prod* p, lprod** res);

/** @fn analyse_sol analyse le choix du sol d'utilisateur et supprime les unitiles
 * @param choix de l'utilisateur et le base de donnee
 * @return positif si succes
 */
int analyse_sol(prod* p, lprod** res);
/** @fn analyse_saison analyse le choix du saison d'utilisateur et supprime les unitiles
 * @param choix de l'utilisateur et le base de donnee
 * @return positif si succes
 */
int analyse_saison(prod* p, lprod** res);

/** @fn venull verifie si un pointeur null ou non
 * @brief arrete le programme si le pointeur est null
 * @param pointeur le nom du pointeur et le fonction qu'il contient
 */
void venull(void* p,char pnom[], char fonct[]);

