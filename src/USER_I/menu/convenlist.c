#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void lcmois (prond* p) 
{
	printf("Choisir le mois:\n");
	printf("Janvier\n");
	printf("Fevrier\n");
	printf("Mars\n");
	printf("Avril\n");
	printf("Mai\n");
	printf("Juin\n");
	printf("Juillet\n");
	printf("Août\n");
	printf("Septembre\n");
	printf("Octobre\n");
	printf("Novembre\n");
	printf("Décembre\n");
}

void lctype ()
{
	printf("Choisir le type de produit:\n");
	printf("Cereale\n" );
        printf("Legumineux\n" );
        printf("Fruit\n" );
        printf("Legume\n" );
        printf("Tubercule\n" );
        printf("Racine\n");
        printf("INDEFINIT\n");
}

void lcsol ()
{
	printf("Choisir le type de sol:\n");
	 printf("Sol sableux,\n");
         printf("Sol argileux,\n");
         printf("Sol limoneux,\n");
         printf("Sol humifère (ou organique),\n");
         printf("humide\n");
         printf("Aquatique\n");
         printf("Meuble\n");
         printf("Riche\n");
         printf("Vaseux\n");
         printf("Léger\n");
         printf("Drainé\n");
         printf("INDEFINIT,\n");
}

void lcsaison () 
{
	printf("Choisir la saison :\n");
 	printf("froid,\n");
        printf("chaud,\n");
        printf("pluie,\n");
        printf("sec,\n");
        printf("tempéré,\n");
        printf( "INDEFINIT,\n");
}

