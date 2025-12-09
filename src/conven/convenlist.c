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
    int tentative = 0;
    const int MAX_TENTATIVE = 3;
 /*   while (1) */
      while (tentative <  MAX_TENTATIVE ) {
	printf("Ampidiro ny safidinao : ");
	if(scanf("%d", &choix) != 1){
	   while (getchar() != '\n');
	   fprintf(stderr, "Ny fampidirana tsy maintsy isa. Avereno azafady.\n");
	   tentative++;
	   continue;
        }
	if (choix >= ch_min && choix <= ch_max) {
	    return choix;
	}
	fprintf(stderr, "Safidinao dia tsy maintsy  anelanelan'ny %d sy %d\n", ch_min,ch_max);
	//printf("Avereno azafady\n");
	printf("Mbola manana %d safidy ianao.\n", MAX_TENTATIVE - 1 - tentative );
        tentative ++;
	printf("Avereno azafady.\n");
    }
    fprintf(stderr, "\n Nandiso safidy %d intelo ianao. Azafady mijanona ny fandaharana, veloma \n", tentative);
    exit(1);

}

void lcmois(prod *p)
{
    printf("  > Safidio ny volana:\n");
    printf("	1) Janoary\n");
    printf("	2) Febroary\n");
    printf("	3) Martsa\n");
    printf("	4) Aprily\n");
    printf("	5) Mey\n");
    printf("	6) Jona\n");
    printf("	7) Jolay\n");
    printf("	8) Aogositra\n");
    printf("	9) Septambra\n");
    printf("	10) Oktobra\n");
    printf("	11) Novambra\n");
    printf("	12) Desambra\n");
    printf("	13) Tsy asiana\n");
	
    
    p->mois[0] = choix_car(1, 13);
    if(p->mois[0] == 13)
    	p->mois[0] = 0;
    nett();
    me_auto(p); 
}

void lctype(prod *p)
{
    printf("  > Safidio ny karazan'ny vokatra:\n");
    //printf("	1) Vary\n");
    printf("	1) Voamaina\n");
    printf("	2) Voankazo\n");
    printf("	3) Legioma\n");
    printf("	4) Vokatr'antany\n");
    printf("	5) Vahitra\n");
    printf("	6) Tsy asiana\n");

    p->type = choix_car(1, 6);
    if (p->type == 1 || p->type == 2) {
//	afficher_menu_principal();
	cereale();
	initialiser_cultures();
//	fruit ();
	//exit (0);
	return;
    } 
    if(p->type == 6)
    	p->type = 0;
    nett();
    me_auto(p); 
}

void lcsol(prod *p)
{
    printf("  > Safidio ny toetany:\n");
    printf("	1) Tora-pasika,\n");
    printf("	2) Fotaka,\n");
    printf("	3) Sol limoneux,\n");
    printf("	4) tany Mainty (ou organique),\n");
    printf("	5) Mando\n");
    printf("	6) Aquatique\n");
    printf("	7) Meuble\n");
    printf("	8) Riche\n");
    printf("	9) Vaseux\n");
    printf("	10) Léger\n");
    printf("	11) Drainé\n");
    printf("	12) Tsy asiana,\n");

    p->sol[0] = choix_car(1, 12);
    if(p->sol[0] == 12)
    	p->sol[0] = 0;
    nett();
    me_auto(p); 
}

void lcsaison(prod* p)
{
    printf("  > Safidio ny toetr'andro :\n");
    printf("	1) Mangatsika\n");
    printf("	2) Mafana\n");
    printf("	3) Be orana\n");
    printf("	4) Maina\n");
    printf("	5) Antonony\n");
    printf("	6) Tsy asiana\n");

    p->sais[0] = choix_car(1, 6);
    if(p->sais[0] == 6)
    	p->sais[0] = 0;
    nett();
    me_auto(p); 
}

