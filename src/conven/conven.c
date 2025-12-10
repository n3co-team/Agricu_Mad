/** @file conven.c
*@brief programme qui contient les definitions des conventions sur les caracteristiques des produits & conversion
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#ifndef CONVEN_H
#include"conven.h"
#endif

/** @fn cette fonction qui convertie la saison int ent char
 *  @param int
 *  @return char*
 */
char* c_saison(int i) {
    char s[50];
    switch (i) {
        case 1: strcpy(s,"Hatsiaka"); break;
        case 2: strcpy(s,"Mafana"); break;
        case 3: strcpy(s,"Orana"); break;
        case 4: strcpy(s,"Maina"); break;
        case 5: strcpy(s,"Antonontonony"); break;
        default: strcpy(s,"Tsy voafaritra"); break;
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
    char t[34];
    switch (i) {
        case 1: strcpy(t," vary"); break;
        case 2: strcpy(t,"Voamaina"); break;
        case 3: strcpy(t,"Voankazo"); break;
        case 4: strcpy(t,"Anana"); break;
        case 5: strcpy(t,"Vokatr'antany"); break;
        case 6: strcpy(t,"Vahitra"); break;
        default: strcpy(t,"Tsy voafaritra"); break;
    }
    
    char* res = malloc(strlen(t)+1);    //resultat
    if (res == NULL) {
        fprintf(stderr, "Erreur d'allocation memoire\n");
        return NULL;
    }
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
        case 1: strcpy(m,"Janoary"); break;
        case 2: strcpy(m,"Febroary"); break;
        case 3: strcpy(m,"Martsa"); break;
        case 4: strcpy(m,"Aprily"); break;
        case 5: strcpy(m,"Mey"); break;
        case 6: strcpy(m,"Jona"); break;
        case 7: strcpy(m,"Jolay"); break;
        case 8: strcpy(m,"Aogositra"); break;
        case 9: strcpy(m,"Septambra"); break;
        case 10: strcpy(m,"Oktobra"); break;
        case 11: strcpy(m,"Novambra"); break;
        case 12: strcpy(m,"Desambra"); break;
        default: strcpy(m,"Tsy voafaritra"); break;
    }
    
    char* res = malloc(strlen(m)+1);    //resultat
    if (res == NULL) {
        fprintf(stderr, "Erreur d'allocation memoire\n");
        return NULL;
    }
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
        case 1: strcpy(s,"Fasika"); break;
        case 2: strcpy(s,"Tanimbary"); break;
        case 3: strcpy(s,"Tanindrano"); break;
        case 4: strcpy(s,"matavy"); break;
        case 5: strcpy(s,"mando"); break;
        case 6: strcpy(s,"anaty rano"); break;
        case 7: strcpy(s,"malemy"); break;
        case 8: strcpy(s,"mahavokatra"); break;
        case 9: strcpy(s,"feno fotaka"); break;
        case 10: strcpy(s,"maivana"); break;
        case 11: strcpy(s,"tsy mando"); break;
        default: strcpy(s,"Tsy voafaritra"); break;
    }
    
    char* res = malloc(strlen(s)+1);    //resultat
    if (res == NULL) {
        fprintf(stderr, "Erreur d'allocation memoire\n");
        return NULL;
    }
    strcpy(res,s);    

    return res;
}
