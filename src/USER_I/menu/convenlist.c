#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int choix_car(int ch_min, int ch_max)
{
	int choix;
	while (1) {
		printf("Entrer votre choix : ");
		scanf("%d",choix);
		if (choix >= ch_min && choix <= ch_max) {
			return choix;
		}
		fprintf(stderr,"Votre choix doit entre %d et %d\n",ch_min,ch_max);
		printf("Veuillez reessayer s'il vous plait\n");
	}
		
}
void lcmois (prond* p) 
{
	printf("Choisir le mois:\n");
	printf("1) Janvier\n");
	printf("2) Fevrier\n");
	printf("3) Mars\n");
	printf("4) Avril\n");
	printf("5) Mai\n");
	printf("6) Juin\n");
	printf("7) Juillet\n");
	printf("8) Août\n");
	printf("9) Septembre\n");
	printf("10) Octobre\n");
	printf("11) Novembre\n");
	printf("12) Décembre\n");

	p->mois[0]=choix(1,12);
}

void lctype ()
{
	printf("Choisir le type de produit:\n");
	printf("1) Cereale\n" );
        printf("2) Legumineux\n" );
        printf("3) Fruit\n" );
        printf("4) Legume\n" );
        printf("5) Tubercule\n" );
        printf("6) Racine\n");
        printf("7) INDEFINIT\n");
}

void lcsol ()
{
	printf("Choisir le type de sol:\n");
	 printf("1) Sol sableux,\n");
         printf("2) Sol argileux,\n");
         printf("3) Sol limoneux,\n");
         printf("4) Sol humifère (ou organique),\n");
         printf("5) humide\n");
         printf("6) Aquatique\n");
         printf("7) Meuble\n");
         printf("8) Riche\n");
         printf("9) Vaseux\n");
         printf("10) Léger\n");
         printf("11) Drainé\n");
         printf("12) INDEFINIT,\n");
}

void lcsaison () 
{
	printf("Choisir la saison :\n");
 	printf("1) froid,\n");
        printf("2) chaud,\n");
        printf("3) pluie,\n");
        printf("4) sec,\n");
        printf("5) tempéré,\n");
        printf( "6) INDEFINIT,\n");
}




