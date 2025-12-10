#ifndef VOAMAINA_H
#define VOAMAINA_H
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CULTURES 10
#define MAX_REGIONS 8
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 200

typedef struct {
    int id;
    char nom[MAX_NAME_LEN];
    char saison_plantation[MAX_NAME_LEN];
    char duree_croissance[MAX_NAME_LEN];
    char informations[MAX_DESC_LEN];
    char code[10];
    int regions_compatibles[10];
    int nb_regions;
} Culture;

typedef struct {
    int id;
    char nom[MAX_NAME_LEN];
    char caracteristiques[MAX_DESC_LEN];
} Region;

//Déclaration des variables globales
extern Culture cultures[MAX_CULTURES];
extern Region regions[MAX_REGIONS];
extern int nombre_cultures;
extern int nombre_regions;

// Déclaration des fonctions
void initialiser_regions();
void initialiser_cultures();
void afficher_menu_principal();
void afficher_menu_regions();
int est_region_compatible(int culture_id, int region_id);
void afficher_informations_cultures(int culture_choix, int region_choix);
void afficher_menu_cultures();
void cereale(prod *p);
//void afficher_informations_cultures(int choix_culture, int choix_region);
//void fruit();
