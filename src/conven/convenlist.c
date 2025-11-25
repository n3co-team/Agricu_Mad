/** @file convenlist.c 
* @brief fichier qui contient les menus principales
* @author Windrick
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef MENU_UI_H
#include"menu_ui.h"
#endif

#ifndef NAC_H
#include"nac.h"
#endif

#ifndef VOAMAINA_H
#include"voamaina.h"
#endif
// #include"prod.h"

int choix_car(int ch_min, int ch_max)
{
    int choix;
    while (1) {
	printf("Entrer votre choix : ");
	scanf("%d", &choix);
	if (choix >= ch_min && choix <= ch_max) {
	    return choix;
	}
	fprintf(stderr, "Votre choix doit entre %d et %d\n", ch_min,ch_max);
	printf("Veuillez reessayer s'il vous plait\n");
    }
    exit(1);

}

void lcmois(prod *p)
{
    printf("  > Choisir le mois:\n");
    printf("	1) Janvier\n");
    printf("	2) Fevrier\n");
    printf("	3) Mars\n");
    printf("	4) Avril\n");
    printf("	5) Mai\n");
    printf("	6) Juin\n");
    printf("	7) Juillet\n");
    printf("	8) Août\n");
    printf("	9) Septembre\n");
    printf("	10) Octobre\n");
    printf("	11) Novembre\n");
    printf("	12) Décembre\n");
    printf("	13) ne pas definie\n");
	
    
    p->mois[0] = choix_car(1, 13);
    if(p->mois[0] == 13)
    	p->mois[0] = 0;
    nett();
    me_auto(p); 
}

void lctype(prod *p)
{
    printf("  > Choisir le type de produit:\n");
    printf("	1) Cereale\n");
    printf("	2) Legumineux\n");
    printf("	3) Fruit\n");
    printf("	4) Legume\n");
    printf("	5) Tubercule\n");
    printf("	6) Racine\n");
    printf("	7) ne pas definie\n");

    p->type = choix_car(1, 7);
    if (p->type == 1 || p->type == 2) {
	afficher_menu_principal();
	cereale();
	exit (0); 
    } 
    if(p->type == 7)
    	p->type = 0;
    nett();
    me_auto(p); 
}

void lcsol(prod *p)
{
    printf("  > Choisir le type de sol:\n");
    printf("	1) Sol sableux,\n");
    printf("	2) Sol argileux,\n");
    printf("	3) Sol limoneux,\n");
    printf("	4) Sol humifère (ou organique),\n");
    printf("	5) humide\n");
    printf("	6) Aquatique\n");
    printf("	7) Meuble\n");
    printf("	8) Riche\n");
    printf("	9) Vaseux\n");
    printf("	10) Léger\n");
    printf("	11) Drainé\n");
    printf("	12) ne pas definie,\n");

    p->sol[0] = choix_car(1, 12);
    if(p->sol[0] == 7)
    	p->sol[0] = 0;
    nett();
    me_auto(p); 
}

void lcsaison(prod* p)
{
    printf("  > Choisir la saison :\n");
    printf("	1) froid\n");
    printf("	2) chaud\n");
    printf("	3) pluie\n");
    printf("	4) sec\n");
    printf("	5) tempéré\n");
    printf("	6) ne pas definie\n");

    p->sais[0] = choix_car(1, 6);
    if(p->sais[0] == 6)
    	p->sais[0] = 0;
    nett();
    me_auto(p); 
}

