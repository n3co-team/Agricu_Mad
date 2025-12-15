/**
* @file menu_ui.c
* @brief fichier contient les fonctions de menu
* @author Dominique
*/

#include<stdio.h>
#include<stdlib.h>
#include "voamaina.h"
#ifndef MENU_UI_H
#include"menu_ui.h"
#endif

#ifndef CONVEN_H
#include"conven.h"
#endif

#ifndef NAC_H
#include"nac.h"
#endif

// [Eo am-piandohan'ny menu_ui.c, aorian'ny include hafa]

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h> // <- Tsy maintsy ampidirina ho an'ny fiasa alarm()
#include <signal.h> // <- Tsy maintsy ampidirina ho an'ny signal handling (sigaction)
//#include "voamaina.h"
// ... (include hafa)

// Fiasa hitantana ny SIGALRM (tapitra ny fotoana)
void alarm_handler(int sig) {
    if (sig == SIGALRM) {
        // Mampiasa write() ho an'ny fiarovana amin'ny I/O mandritra ny signal
        write(STDOUT_FILENO, "\n\n\033[31m⛔ Tsy voavaly tao anatin'ny fotoana voafetra (10 segondra)!\033[0m\n", 84);
        write(STDOUT_FILENO, "\033[31mMijanona ny programme.\033[0m\n", 31);
        exit(0); // Mijanona ny programme
    }
}

// Fiasa manao ny fanontaniana sy mametra fetr'ora
void start_quiz() {
    char valiny;
    int fetra_ora = 10; // Fetra: 10 segondra

    // Apetraka ny fiasa hitantana ny SIGALRM amin'ny fampiasana sigaction
    struct sigaction sa;
    sa.sa_handler = alarm_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }
    
    printf("\n**************************************************************************\n");
    printf("\033[33m❓ FANONTANIANA MAIKA:\033[0m Alohan'ny hidiranao, vonona ve ianao. Tena mila an'ilay fampitahana vaovao mikasika ny fambolena tokoa ve ianao? (y(eny)/n(tsy))\n");
    printf("👉 Misy \033[31m%d segondra\033[0m ianao hamaliana. (Valiny: y(eny) na n(tsy))\n==> ", fetra_ora);

    // Manomboka ny fetr'ora
    alarm(fetra_ora); 

    // Miandry ny valin'ny mpampiasa
    if (scanf(" %c", &valiny) != 1) {
        return; // Raha tsy voaray ny input, mamela ny alarm handler hanao ny asany
    }
    
    // Atsahatra ny alarm raha mbola tsy tapitra ny fotoana
    alarm(0); 

    printf("\n**************************************************************************\n");

    // Fanamarinana ny valiny
    if (valiny == 'y' || valiny == 'Y') {
        printf("\033[32m✅ Tsara! Manohy miditra...\033[0m\n");
    } else {
        printf("\033[31m❌ Mbola tsy  vonona ianao. Mijanona ny programme.\033[0m\n");
        exit(0); // Mijanona
    }
}
// ... (Tohizana amin'ny fiasa nett())




/** @fn nettoyer le terminal */
void nett() {
    printf("\033[H\033[J");
}

int me_auto(prod* choix) 
{
	int t=choix->type;
	int m=choix->mois[0];
	int sa=choix->sais[0];
	int so=choix->sol[0];

	if (t+m+so+sa == 0)
		me_pri(choix);
	else if (t != 0 && m+sa+so == 0) {
		me_sty(choix);
		return 1;
	}
	else if (so != 0 && m+sa+t == 0) {
		me_sso(choix);
		return 1;
	}
	else if (t != 0 && so != 0 && sa+m == 0) {
		me_styso(choix);
		return 1;
	}
	else if (m + sa != 0 && t + so == 0) {
		me_ssamo(choix);
		return 1;
	}
	else if (t != 0 && sa + m != 0 && so==0) {
		me_stysamo(choix);
		return 1;
	}
	else if (so != 0 && sa + m != 0 && t==0 ) {
			me_ssosamo(choix);
		return 1;
	}
	else {
		verification_choix(choix);
		return 2;
	}
	return (0);
}

void init_choix(prod** p) 
{
	//alloé un espase pour mettre les choix de l'utilisateur
    *p = malloc(sizeof(prod));
	if (*p == NULL) {
		fprintf(stderr, "Allocation error\n");
		exit(1);
	}

	//iniitiation type
	int i;
	(*p)->type = 0;

	//initiation de sol
	for(i = 0; i < 11; i++) {
		(*p)->sol[i]=0;
	}

	//initiation de saison	
	for(i = 0; i < 4; i++) {
		(*p)->sais[i] = 0;
	}
	//initiation de mois
	for(i = 0; i < 12; i++) {
		(*p)->mois[i] = 0;
	}
	//initialiser de  produi
//	for (i = 0; i)
	printf("\n**************************************************************************\n");
	int result = system("\tfiglet -f standard tongasoa   ianao\n");
	printf("\n**************************************************************************\n");
}

/** @fn me_pri
* @details fonction pour menu principal
* @param struct produit
* @return void
*/
void me_pri(prod* p)
{
	static int quiz_done = 0;
	static int chargement_fait = 0;
	if (!quiz_done){
	  start_quiz();
	  if(p == NULL){
		init_choix(&p);
	  }
	   quiz_done = 1;
        }
	if (!chargement_fait){
	     initialiser_cultures();
	     chargement_fait = 1;
	}
	nett();
	int choix;
	init_choix(&p);
	printf("Fototra \n");
//	printf("\n--------------------------------\n");
	printf("\033[34m ==> Ataovy ny safidy :\033[0m \n");
	printf("\t\033[36m 1)Karazan'ny vokatra\033[0m\n");
	printf("\t\033[36m 2)Toe-tany\033[0m\n");
	printf("\t\033[36m 3)Toetr'andro\033[0m\n");
	printf("\t\033[36m 4)Volana\033[0m\n");
	printf("\t\033[36m 5)Mombamomba\033[0m\n ");
	printf("\t\033[36m 6)Manampy voly\033[0m");
	printf("\n----------------------------------\n");
	initialiser_cultures();
	
	choix = choix_car(1,6);

	switch (choix) {
		case 0: prod_apropos(); 
			break;
		case 1:lctype(p);	//affiche le menu type
			 break;
		case 2: lcsol(p);	// affiche le menu du sol
			 break;
		case 3: lcsaison(p);	// affiche le menu du saison
			break;
		case 4: lcmois(p);	// affiche le menu du mois
			 break;
		case 6: //manamp
			//printf("Ampidiro ny fanampin'ny voly tinao ampiana: ");
			lcman(p);
			break;
		default: //fprintf(stderr,"Erreur\n");
			me_auto(p);
			exit (1); break;
	} 	
}

/** @fn menu sans choix types de produits */
void me_sty (prod* p)
{
	int choix;
	afchoix(p);

	printf("\n\033[34m ==> Ataovy ny safidy :\033[0m\n");
//	printf("\n------------------------------------------\n");
	printf("\t\033[1m1) Lisitrin'ny vokatra \033[0m\n");
	printf("\t\033[1m2) Toe-tany\033[0m\n");
	printf("\t\033[1m3) Toetr'andro\033[0m\n");
	printf("\t\033[1m4) Volana\033[0m\n");
//        printf("\t\033[1m5) manampy\033[0m\n");
	printf("\t\033[1m6) Hanova safidy\033[0m\n");
	initialiser_cultures();
	choix = choix_car(1,5);

	switch (choix) {
		case 0: prod_apropos(); 
			break;
		case 1: prod_list(p); 
			break;
		case 2: lcsol(p);
			break;
		case 3:lcsaison(p);
			 break;
		case 4: lcmois(p);
			 break;
/*		case 5: lcman(p);
			break;*/
		case 6: cchange(p);
			break;
		default: fprintf(stderr,"Erreur");
			exit (1); 
			break;
	}
}

/** @fn menu sans choix de sol */
void me_sso (prod* p) 
{
	int choix;
	afchoix(p);

	printf("\n\033[34m --> Ataovy ny safidy : \033[0m\n");
//	printf("\n-------------------------------------\n");
	printf("\t\033[37m 1) Lisitrin'ny vokatra \033[0m\n");
	printf("\t\033[37m 2) Karazan'ny vokatra \033[0m\n");
	printf("\t\033[37m 3) Toetr'andro \033[0m\n");
	printf("\t\033[37m 4) Volana \033[0m\n");
	printf("\t\033[37m 5) Hanova safidy \033[0m\n");
	initialiser_cultures();
	choix = choix_car(1,5);

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lctype(p);
			break;
		case 3:lcsaison(p);
			 break;
		case 4: lcmois(p);
			 break;
		case 5: cchange(p);
			break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
	}

}

/** @fn menu sans choix de saison */
void me_ssa(prod* p)
{
	int choix;
	afchoix(p);

	printf("\n\033[34m--> Ataovy ny safidy : \033[0m\n");
	printf("\033[37m 1) Lisitrin'ny vokatra \033[0m\n");
	printf("\033[37m 2) Karazan'ny vokatra \033[0m\n"); 
	printf("\033[37m 3) Toe-tany \033[0m\n");
	printf("\033[37m 4) Hanova safidy \033[0m\n");
	initialiser_cultures();
	choix = choix_car(1,4);

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lctype(p);
			break;
		case 3:  lcsol(p);
			break;
		case 4: cchange(p);
			break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
	}

}

/** @fn menu sans choix de mois */
void me_smo (prod* p) 
{
	int choix;
	afchoix(p);

	printf("\n\033[34m-->Ataovy ny safidy : \033[0m\n");
	printf("\033[37m 1) Lisitrin'ny vokatra \033[0m\n");
	printf("\033[37m 2) Karazan'ny vokatra \033[0m\n"); 
	printf("\033[37m 3) Toe-tany \033[0m\n");
	printf("\033[37m 4) Hanova safidy \033[0m\n");
	initialiser_cultures();
	choix = choix_car(1,3);

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
//		case 2: lctype(p);
			break;
		case 3: lcsol(p);
			 break;
		case 4: cchange(p);
			break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
	}

}

/** @fn menu sans choix de saison et  mois */
void me_ssamo (prod* p) 
{
	int choix;
	afchoix(p);
	printf("\n\033[34m-->Ataovy ny safidy : \033[0m\n");
	printf("\033[37m 1) Lisitrin'ny vokatra \033[0m\n");
	printf("\033[37m 2) Karazan'ny vokatra \033[0m\n"); 
	printf("\033[37m 3) Toe-tany \033[0m\n");
	printf("\033[37m 4) Hanova safidy \033[0m\n");
	initialiser_cultures();
	choix = choix_car(1,4);	

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lctype(p);
			break;
		case 3: lcsol(p);
			 break;
		case 4: cchange(p);
			break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
	}

}

/** @fn menu sans choix de saison et  mois */
void me_styso (prod* p) 
{
	int choix;
	afchoix(p);
	printf("\n--------------------------------\n");
	printf("\n\033[34m-->Ataovy ny safidy : \033[0m\n");
	printf("\t\033[37m 1) Lisitrin'ny vokatra \033[0m\n");
	printf("\t\033[37m 2) Toetr'andro \033[0m\n"); 
	printf("\t\033[37m 3) Volana \033[0m\n");
	printf("\t\033[37m 4) Hanova safidy \033[0m\n");
	initialiser_cultures();
	choix = choix_car(1,4);	

	switch (choix) {
		case 0: prod_apropos(); break;
		case 1: prod_list(p); break;
		case 2: lcsaison(p);
			prod_list(p); break;
		case 3: lcmois(p);
			 prod_list(p); break;
		case 4: cchange(p);
			break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
	}

}

/** @details menu sans choix de saison et  mois */
void me_stysamo (prod* p) 
{
	int choix;
	afchoix(p);

	printf("\n\033[34m-->Ataovy ny safidy : \033[0m\n");
	printf("\033[37m    1) Lisitrin'ny vokatra \033[0m\n");
	printf("\033[37m    2) Toe-tany \033[0m\n");
	printf("\033[37m    3) Hanova safidy \033[0m\n");
	initialiser_cultures();
	choix = choix_car(1,3);	

	switch (choix) {
		case 1: prod_list(p); break;
		case 2:lcsol(p);
			prod_list(p); break;
		case 3: cchange(p);
			break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
	}

}

/** @details menu sans choix de saison et  mois */
void me_ssosamo (prod* p) 
{
	int choix;
	afchoix(p);

	printf("\n\033[34m==> Ataovy ny safidy : \033[0m\n");
	printf("\033[37m 1) Lisitrin'ny vokatra \033[0m\n");
	printf("\033[37m 2) Karazan'ny vokatra \033[0m\n");
	printf("\033[37m 3) Hanova safidy \033[0m\n");
	initialiser_cultures();
	choix = choix_car(1,3);	

	switch (choix) {
		case 1: prod_list(p); break;
		case 2: lctype(p);
			prod_list(p); break;
		case 3: cchange(p);
			break;
		default: fprintf(stderr,"Erreur");
			exit (1); break;
	}

}

void afchoix(prod *p) {
	char* MOIS=c_mois(p->mois[0]);
	char* SAISON=c_saison(p->sais[0]);
	char* TYPE=c_type_prod(p->type);
	char* SOL=c_sol(p->sol[0]);
	printf("\n.__________________________");
	printf("\n\033[36m | Safidy efa azo : \033[0m\n");
	
	if(p->type != 0)
		printf("\033[36m | KARAZANY:%s \033[0m\n",TYPE);
	if(p->sol[0] != 0)
		printf("\033[36m | TANY:%s \033[0m\n",SOL);
	if(p->sais[0] != 0)
		printf("\033[36m | TOETR'ANDRO:%s \033[0m\n",SAISON);
	if(p->mois[0] != 0)
		printf("\033[36m | VOLANA:%s \033[0m\n",MOIS);
	printf("|__________________________");

	if (MOIS != NULL)
	free(MOIS);
	if (SAISON != NULL)
	free(SAISON);
	if (TYPE != NULL)
	free(TYPE);
	if (SOL != NULL)
	free(SOL);
}

/** @fn verification de choix */	
void verification_choix(prod* p) {
	afchoix(p);;
	printf("\n\033[1m Marina daholo ve (\"y\" ho an'ny eny) \033[0m");
	printf("\n\033[1m c : Fanovana safidy\np: Fanovana sy fiverenana any amin'ny menio lehibe\n==> \033[0m");

	char a='a';
	while (a != 'y') {
		scanf(" %c",&a);
		if(a == 'c') {
			cchange(p);
			verification_choix(p);
		}
		else if ( a == 'p')
			me_pri(p);
		else if (a == 'y') 
			break;
		fprintf(stderr,"Valio amin'ny 'y' raha eny na 'n' raha tsia!\n==>");
	}
    prod_list(p);
}

/** @fn changer un choix */
int cchange(prod *p) 
{
	int choix;

	printf("\n-> Inona no tianao hovaina ?:\n");
	printf("\t\033[32m 1) Karazan'ny vokatra \033[0m\n");
	printf("\t\033[32m 2) Toe-tany \033[0m\n");
	printf("\t\033[32m 3) Toetr'andro \033[0m\n");
	printf("\t\033[32m 4) Volana \033[0m\n");
	printf("\t\033[32m 5) Aide \033[0m\n");
	printf("\t\033[32m 6) Aseho izay efa nofidina \033[0m\n");
        initialiser_cultures();
	choix=choix_car(1,6);
	switch (choix) {
		case 1:lctype(p); break;	//affiche le menu type
		case 2: lcsol(p); break;	// affiche le menu du sol
		case 3: p->mois[0] = 0;
			lcsaison(p); break;	// affiche le menu du saison
		case 4: p->sais[0] = 0;
			lcmois(p); break;	// affiche le menu du mois
		case 5: info_cchange();
			cchange(p);
			break;
		case 6: nett();
			afchoix(p);
			cchange(p); break;
		default: //fprintf(stderr,"Erreur\n");
			exit (1); break;
	}
	return 1;
}

/** @fn Menu de produit obtenu */
void prod_list(prod* p) {
	char i;		//index
			//
	// allocation de memoire pour les données qu'on va recuperer
	lprod* lp = malloc(sizeof(lprod));
	venull(lp,"lp","prod_list");

	lprod* lpt;	// pointeur pour permuter les position de list chainé lp
	 
	//verification du choix d'utilisateur
//	verification_choix(p);

	rdata(p,&lp); //recupere les données convenable au choix de l'utilisateur
	resultf(&lp);	// affichage des resultat

	//Libere les memoire alloué
	while (lp != NULL) {
		lpt=lp->s;
		if(lp->c != NULL)
			free(lp->c);
		free(lp);
		if(lpt == NULL)
			break;
		lp=lpt;
	}
	

	printf("\nq : Hiala \np : Hiverina amin'ny voalohany\n==> ");
	scanf(" %c",&i);
	switch (i) {
		case 'q' : exit(0);
		case 'p':me_pri(p); break;
		default: fprintf(stderr,"Safidy tsy izy");
			 exit (1);
	}
	exit (0);
}
