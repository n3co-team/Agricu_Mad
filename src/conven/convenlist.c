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
    fprintf(stderr, "\033[1m \n Nandiso safidy %d (intelo) ianao. Azafady mijanona ny fandaharana, veloma \033[0m \n", tentative);
    exit(1);

}

void lcmois(prod *p)
{
    printf(" \033[34m --> Safidio ny volana:\033[0m\n");
    printf("\033[37m 1) Janoary \033[0m\n");
    printf("\033[37m 2) Febroary \033[0m\n");
    printf("\033[37m 3) Martsa \033[0m\n");
    printf("\033[37m 4) Aprily \033[0m\n");
    printf("\033[37m 5) Mey \033[0m\n");
    printf("\033[37m 6) Jona \033[0m\n");
    printf("\033[37m 7) Jolay \033[0m\n");
    printf("\033[37m 8) Aogositra \033[0m\n");
    printf("\033[37m 9) Septambra \033[0m\n");
    printf("\033[37m 10) Oktobra \033[0m\n");
    printf("\033[37m 11) Novambra \033[0m\n");
    printf("\033[37m 12) Desambra \033[0m\n");
    printf("\033[37m 13) Tsy asiana \033[0m\n");
    initialiser_cultures();
    p->mois[0] = choix_car(1, 13);
    if(p->mois[0] == 13)
    	p->mois[0] = 0;
    nett();
    me_auto(p); 
}

void lctype(prod *p)
{
    printf("\033[34m --> Safidio ny karazan'ny vokatra:\033[0m\n");
    //printf("	1) Vary\n");
    printf("\033[37m 1) Voamaina \033[0m\n");
    printf("\033[37m 2) Voankazo \033[0m\n");
    printf("\033[37m 3) Legioma \033[0m\n");
    printf("\033[37m 4) Vokatr'antany \033[0m\n");
    printf("\033[37m 5) Vahitra \033[0m\n");
    printf("\033[37m 6) Tsy asiana \033[0m\n");

    p->type = choix_car(1, 6) ;
    if (p->type == 1) {
	cereale();
	initialiser_cultures();
	return;
    }

    if(p->type == 6)
    	p->type = 0;
   p->type=p->type+1;
    nett();
    me_auto(p); 
}

void lcsol(prod *p)
{
    printf("\033[34m  --> Safidio ny toetany: \033[0m\n");
    printf("\033[34m 1) Tora-pasika, \033[0m\n");
    printf("\033[34m 2) Fotaka, \033[0m\n");
    printf("\033[34m 3) tany limo(misy nofotany na fotaka), \033[0m\n");
    printf("\033[34m 4) tany Mainty (ou organique), \033[0m\n");
    printf("\033[34m 5) Mando, \033[0m\n");
    printf("\033[34m 6) Tany misy rano foana,\033[0m\n");
    printf("\033[34m 7) tany malemy,  \033[0m\n");
    printf("\033[34m 8) Tany lonaka na be otrikaina, \033[0m\n");
    printf("\033[34m 9) tany be fotaka, \033[0m\n");
    printf("\033[34m 10) tany malefaka, \033[0m\n");
    printf("\033[34m 11) Tany mandeha rano tsara, \033[0m\n");
    printf("\033[34m 12) Tsy asiana, \033[0m\n");

    p->sol[0] = choix_car(1, 12);
      initialiser_cultures();
    if(p->sol[0] == 12)
    	p->sol[0] = 0;
    nett();
    me_auto(p); 
}

void lcsaison(prod* p)
{
    printf("\033[34m-->Safidio ny toetr'andro : \033[0m\n");
    printf("\033[34m 	1) Mangatsika \033[0m\n");
    printf("\033[34m	2) Mafana \033[0m\n");
    printf("\033[34m	3) Be orana \033[0m\n");
    printf("\033[34m	4) Maina \033[0m\n");
    printf("\033[34m	5) Antonony \033[0m\n");
    printf("\033[34m	6) Tsy asiana \033[0m\n");

    p->sais[0] = choix_car(1, 6);
     initialiser_cultures();
   if(p->sais[0] == 6)
    	p->sais[0] = 0;
    nett();
    me_auto(p);
}

