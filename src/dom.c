/**  @file dom.c
  *  @bref fichier qui contient les listes pour les cereales
  *  @author Dominique
*/

#include "voamaina.h"

// Définition des variables globales
Culture cultures[MAX_CULTURES];
Region regions[MAX_REGIONS];
int nombre_cultures = 0;
int nombre_regions = 0;
int choix_cultures;
// apina
extern int choix_cultures;
void initialiser_regions()
{
    // Région 1: Alaotra Mangoro
    regions[0].id = 1;
    strcpy(regions[0].nom, "Alaotra Mangoro");
    strcpy(regions[0].caracteristiques,"Region de riziculture, climat tropical humide");

    // Région 2: Analamanga
    regions[1].id = 2;
    strcpy(regions[1].nom, "Analamanga");
    strcpy(regions[1].caracteristiques, "Hauts plateaux, climat tempere");

    // Région 3: Vakinankaratra
    regions[2].id = 3;
    strcpy(regions[2].nom, "Vakinankaratra");
    strcpy(regions[2].caracteristiques, "Region froide, sols volcaniques");

    // Région 4: Atsinanana
    regions[3].id = 4;
    strcpy(regions[3].nom, "Atsinanana");
    strcpy(regions[3].caracteristiques, "Cote est, climat chaud et humide");

    // Région 5: Menabe
    regions[4].id = 5;
    strcpy(regions[4].nom, "Menabe");
    strcpy(regions[4].caracteristiques, "Cote ouest, climat sec");

    // Région 6: Boeny
    regions[5].id = 6;
    strcpy(regions[5].nom, "Boeny");
    strcpy(regions[5].caracteristiques, "Nord-ouest, climat tropical");

    // Région 7: Anosy
    regions[6].id = 7;
    strcpy(regions[6].nom, "Anosy");
    strcpy(regions[6].caracteristiques, "Sud-est, climat varie");

    // Région 8: Diana
    regions[7].id = 8;
    strcpy(regions[7].nom, "Diana");
    strcpy(regions[7].caracteristiques, "Extreme nord, climat chaud");

    nombre_regions = 8;
}

void initialiser_cultures()
{
    // Culture 1: Tsaramaso
    cultures[0].id = 1;
    strcpy(cultures[0].nom, "Tsaramaso");
    strcpy(cultures[0].saison_plantation, "Aprily - Mey");
    strcpy(cultures[0].duree_croissance, "3-4 volana");
    strcpy(cultures[0].informations,"Planter en sol bien draine. Besoin de soleil modere.");
    strcpy(cultures[0].code, "TS01");
    int regions_tsaramaso[] = { 1, 2, 3, 4 };
    cultures[0].nb_regions = 4;
    memcpy(cultures[0].regions_compatibles, regions_tsaramaso,
	   sizeof(regions_tsaramaso));

    // Culture 2: Vary
    cultures[1].id = 2;
    strcpy(cultures[1].nom, "Vary");
    strcpy(cultures[1].saison_plantation, "Oktobra - Desembra");
    strcpy(cultures[1].duree_croissance, "5-6 volana");
    strcpy(cultures[1].informations,
	   "Necessite beaucoup d'eau. Planter en riziere.");
    strcpy(cultures[1].code, "VR02");
    int regions_vary[] = { 1, 4, 6, 8 };
    cultures[1].nb_regions = 4;
    memcpy(cultures[1].regions_compatibles, regions_vary,
	   sizeof(regions_vary));

    // Culture 3: Mangahazo
    cultures[2].id = 3;
    strcpy(cultures[2].nom, "Mangahazo");
    strcpy(cultures[2].saison_plantation, "Aogositra - Septambra");
    strcpy(cultures[2].duree_croissance, "8-12 volana");
    strcpy(cultures[2].informations,
	   "Pousse bien en sol leger. Resistance a la secheresse.");
    strcpy(cultures[2].code, "MG03");
    int regions_mangahazo[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    cultures[2].nb_regions = 8;
    memcpy(cultures[2].regions_compatibles, regions_mangahazo,
	   sizeof(regions_mangahazo));

    // Culture 4: Voanjo
    cultures[3].id = 4;
    strcpy(cultures[3].nom, "Voanjo");
    strcpy(cultures[3].saison_plantation, "Novambra - Janoary");
    strcpy(cultures[3].duree_croissance, "4-5 volana");
    strcpy(cultures[3].informations,
	   "Planter en sol sableux. Besoin de beaucoup de soleil.");
    strcpy(cultures[3].code, "VJ04");
    int regions_voanjo[] = { 4, 5, 6, 7, 8 };
    cultures[3].nb_regions = 5;
    memcpy(cultures[3].regions_compatibles, regions_voanjo,
	   sizeof(regions_voanjo));

    // Culture 5: Ognon
    cultures[4].id = 5;
    strcpy(cultures[4].nom, "Tongolo");
    strcpy(cultures[4].saison_plantation, "Martsa - Mey");
    strcpy(cultures[4].duree_croissance, "4-5 volana");
    strcpy(cultures[4].informations,
	   "Sol riche en matiere organique. Arrosage regulier.");
    strcpy(cultures[4].code, "OG05");
    int regions_ognon[] = { 1, 2, 3 };
    cultures[4].nb_regions = 3;
    memcpy(cultures[4].regions_compatibles, regions_ognon,
	   sizeof(regions_ognon));

    // Culture 6: Karoty
    cultures[5].id = 6;
    strcpy(cultures[5].nom, "Karoty");
    strcpy(cultures[5].saison_plantation, "Febroary - Aprily");
    strcpy(cultures[5].duree_croissance, "3-4 volana");
    strcpy(cultures[5].informations,
	   "Sol meuble et sableux. Eviter les sols lourds.");
    strcpy(cultures[5].code, "KR06");
    int regions_karoty[] = { 2, 3, 6, 7 };
    cultures[5].nb_regions = 4;
    memcpy(cultures[5].regions_compatibles, regions_karoty,
	   sizeof(regions_karoty));

    // Culture 7: Tomates
    cultures[6].id = 7;
    strcpy(cultures[6].nom, "Voatabia");
    strcpy(cultures[6].saison_plantation, "Aogositra - Oktobra");
    strcpy(cultures[6].duree_croissance, "3-4 volana");
    strcpy(cultures[6].informations,
	   "Beaucoup de soleil. Tuteurage necessaire.");
    strcpy(cultures[6].code, "TM07");
    int regions_tomates[] = { 1, 2, 3, 4, 6, 8 };
    cultures[6].nb_regions = 6;
    memcpy(cultures[6].regions_compatibles, regions_tomates,
	   sizeof(regions_tomates));

    // Culture 8: Brèdes
    cultures[7].id = 8;
    strcpy(cultures[7].nom, "Bredes");
    strcpy(cultures[7].saison_plantation, "Isan-taona");
    strcpy(cultures[7].duree_croissance, "1-2 volana");
    strcpy(cultures[7].informations,
	   "Croissance rapide. Arrosage frequent.");
    strcpy(cultures[7].code, "BR08");
    int regions_bredes[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    cultures[7].nb_regions = 8;
    memcpy(cultures[7].regions_compatibles, regions_bredes,
	   sizeof(regions_bredes));

    // Culture 9: Ails
    cultures[8].id = 9;
    strcpy(cultures[8].nom, "Ails");
    strcpy(cultures[8].saison_plantation, "Mey - Jona");
    strcpy(cultures[8].duree_croissance, "5-6 volana");
    strcpy(cultures[8].informations, "Sol bien draine. Peu d'arrosage.");
    strcpy(cultures[8].code, "AL09");
    int regions_ails[] = { 2, 3, 7 };
    cultures[8].nb_regions = 3;
    memcpy(cultures[8].regions_compatibles, regions_ails,
	   sizeof(regions_ails));

    // Culture 10: Ananas
    cultures[9].id = 10;
    strcpy(cultures[9].nom, "Mananasy");
    strcpy(cultures[9].saison_plantation, "Desembra - Febroary");
    strcpy(cultures[9].duree_croissance, "18-24 volana");
    strcpy(cultures[9].informations,
	   "Climat tropical. Sol acide et bien draine.");
    strcpy(cultures[9].code, "AN10");
    int regions_ananas[] = { 4, 5, 6, 8 };
    cultures[9].nb_regions = 4;
    memcpy(cultures[9].regions_compatibles, regions_ananas,
	   sizeof(regions_ananas));

    nombre_cultures = 10;
}

void afficher_menu_principal()
{
    printf("\n=== MENU PRINCIPAL ===\n\n");//nombre_cultures);
    printf("Lisitr'ireo fambolena misy :\n");
    printf("--------------------------------\n");

    for (int i = 0; i < nombre_cultures; i++) {
	printf("%2d. %s\n", cultures[i].id, cultures[i].nom);
    }

    //printf("\n0. Quitter le programme\n");
    printf("\nFidio ireo fambolena mety (1-%d) na 0 raha hiala: ",
	   nombre_cultures);
    //
    int choix_locale;
    if (scanf("%d", &choix_locale) == 1) {
	if (choix_locale > 0 && choix_locale <= nombre_cultures) {
	    /*afficher_menu_regions();
	       afficher_menu_cultures(); */
	    choix_cultures = choix_locale;
	    int choix_region;
	    afficher_menu_regions();
	    scanf("%d", &choix_region);
	    afficher_informations_cultures(choix_cultures, choix_region);
//         initialiser_cultures();
	} else if (choix_locale == 0) {
	    return;
	}

    }
}


void afficher_menu_cultures()
{
    printf("\n=== VOLY VOAFIDY ===\n\n");
    printf("Liitr'ireo fambolena misy : \n");
    printf("-----------------------------\n");

    for (int i = 0; i <= nombre_cultures; i++) {
	printf("%d. %s\n", cultures[i].id, cultures[i].nom);

    }
    printf("\n Fidio ireo fambolena mety (1-%d): ", nombre_cultures);
}


void afficher_menu_regions()
{
   
    int culture_index = int culture_choix - 1;
//    int region_index = region_choix - 1;
    //printf("\n=== SAFIDY FARITRA ===\n\n");
    printf("Lisitr'ireo faritra misy ho an'ny voly %s:",cultures[culture_index].nom);
    printf("-----------------------------\n");

    for (int i = 0; i < nombre_regions; i++) {
	printf("%d. %s\n", regions[i].id, regions[i].nom);
    }

    printf("\nSafidio ny faritra mety (1-%d): ", nombre_regions);
}

int est_region_compatible(int culture_id, int region_id)
{
    for (int i = 0; i < cultures[culture_id - 1].nb_regions; i++) {
	if (cultures[culture_id - 1].regions_compatibles[i] == region_id) {
	    return 1;
	}
    }
    return 0;
}

void afficher_informations_cultures(int culture_choix, int region_choix)
{
    if (culture_choix < 1 || culture_choix > nombre_cultures) {
	printf("Tsy nety ny safidy voly!\n");
	return;
    }

    if (region_choix < 1 || region_choix > nombre_regions) {
	printf("Tsy nety ny safidy faritra!\n");
	return;
    }

    int culture_index = culture_choix - 1;
    int region_index = region_choix - 1;

    printf("\n=== MOMBAMOMBAN'NY %s ===\n", cultures[culture_index].nom);
    printf("=== FARITRA: %s ===\n\n", regions[region_index].nom);

    printf("Code: %s\n", cultures[culture_index].code);
    printf("Fotoana fambolena: %s\n",
	   cultures[culture_index].saison_plantation);
    printf("Faharetan'ny voly: %s\n",
	   cultures[culture_index].duree_croissance);

    // Vérifier la compatibilité région/culture
    if (est_region_compatible(culture_choix, region_choix)) {
	printf
	    ("\n MITOVY AMINY: Cette culture est ADAPTEE a la region %s\n",
	     regions[region_index].nom);
    } else {
	printf
	    ("\n MITOVY AMINY: Cette culture est PEU ADAPTEE a la region %s\n",
	     regions[region_index].nom);
    }

    printf("\nToetran'ny faritra:\n");
    printf("%s\n", regions[region_index].caracteristiques);

    printf("\nMombamomba sy teknika fambolena :\n");
    printf("%s\n", cultures[culture_index].informations);

    // Afficher autres régions compatibles
    printf("\nFaritra afa mety aminy: ");
    for (int i = 0; i < cultures[culture_index].nb_regions; i++) {
	int region_id = cultures[culture_index].regions_compatibles[i];
	printf("%s", regions[region_id - 1].nom);
	if (i < cultures[culture_index].nb_regions - 1) {
	    printf(", ");
	}
    }
    printf("\n");
}


// Fonction vao hahazoana ny valeur an'ilay choix globale
int get_choix_cultures()
{
    return choix_cultures;
}

/*

void cereale() {
    int choix_culture, choix_region, sous_choix;
    int en_cours = 1;

    initialiser_regions();
    initialiser_cultures();

    printf("========================================\n");
    printf("    SYSTEME D'INFORMATION AGRICOLE\n");
    printf("========================================\n");

    while(en_cours) {
        afficher_menu_principal();
	// nampiana if dia alana aveo
//        if(scanf("%d", &choix_culture)){
	   printf("Saisie invalide. Veuillez entrer un nombre.\n");
	   while (getchar() != '\n'); // vider le buffer
	   continue;
	}

        if(choix_culture == 0) {
            printf("Au revoir!\n");
            break;
        }
	

        if(choix_culture >= 1 && choix_culture <= nombre_cultures) {
            // Afficher le menu des régions
            afficher_menu_regions();
            if (scanf("%d", &choix_region) != 1 ){
	        printf("Saisie invalide. Veuillez entrer un nombre.\n");
		while (getchar() != '\n' )
	        continue;
	    }

            if(choix_region >= 1 && choix_region <= nombre_regions) {
                // Afficher les informations avec la région sélectionnée
                afficher_informations_culture(choix_culture, choix_region);
//
	if (choix_cultures > 0 ){
                // Menu secondaire
                printf("\n--- MENU SECONDARIE ---\n");
                printf("1. Voir une autre culture\n");
                printf("2. Changer de region pour cette culture\n");
                printf("3. Retour au menu principal\n");
                printf("4. Quitter\n");
                printf("\nVotre choix: ");
                if (scanf("%d", &sous_choix) != 1){
			printf("Saisie invalide. Retour au menu principale.\n");
			while (getchar() != '\n');
			continue;
		}

                switch(sous_choix) {
                    case 1:
                        // Voir une autre culture
                        break;
                    case 2:
                        // Changer de région pour la même culture
                        afficher_menu_regions();
                        if (scanf("%d", &choix_region) != 1){
				printf("Saisie invalide. Retour au menu principale.\n");
				while (getchar () != '\n');
				break;
			}
			if (choix_region >= 1 && choix_region <= nombre_regions){
				 afficher_informations_culture(choix_cultures, choix_region);
			}
                       // afficher_informations_culture(choix_culture, choix_region);
                        else {
				printf("Choix de region invalide.\n");
			}
			break;
                    case 3:
                        // Retour au menu principal
                        continue;
                    case 4:
                        en_cours = 0;
                        printf("Au revoir!\n");
                         break;
                    default:
                        printf("Choix invalide, retour au menu principal.\n");
                }
            } else {
                printf("Region invalide! Retour au menu principal.\n");
            }
        } else {
            printf("Choix invalide! Veuillez choisir entre 0 et %d.\n", nombre_cultures);
        }
      }
    }
// teste pour les iformations de la cultures 
//	void afficher_informations_cultures();
}

//
void fruit (){
    int choix_culture, choix_region, sous_choix;
    int en_cours = 1;

    while (en_cours){
        afficher_menu_principal ();
        scanf("%d", &choix_culture);
        
        if (choix_culture == 0){
            printf("Au revoir !\n");
            break;
        }
        if (choix_culture >= 1 && choix_culture <= nombre_cultures){
            scanf("%d", &choix_region);
            if (choix_region >= 1 && choix_region <= nombre_regions){
                afficher_informations_culture(choix_culture,choix_region);

                //menu secondaire----
                printf("\n--- MENU SECONDAIRE ---\n");
                printf("1. Voir une autre culture\n");
                printf("2. Changer de region pour cette culture \n");
                printf("3. Retour au menu principale \n");
                printf("4. Quitter\n");
                printf("\n Entrer votre choix: ");
                scanf("%d", &sous_choix);

                switch (sous_choix) {
                    case 1: 
                        break;
                    case 2: 
                        afficher_menu_regions();
                        scanf("%d", &choix_region);
                        afficher_informations_culture(choix_culture, choix_region);
                        break;
                    case 3: 
                        continue;
                    case 4: 
                        en_cours = 0;
                        printf("Au revoir! \n");
                        break;
                    default:
                        printf("Choix invalide, retour au menu principale. \n");
                }
            } 
            else {
                printf("Region invalide! Retour au menu principal. \n");
            } 
        } 
        else {
            printf("Choix invalide! Veuillez choisir entre 0 et %d. \n ",nombre_cultures);
        }
    }
// Teste pour les informations des cultures
	void afficher_informations_cultures();
}
*/


void cereale()
{
    int choix_culture, choix_region, sous_choix;
    int en_cours = 1;

    initialiser_regions();
    initialiser_cultures();

    printf("======================================\n");
    printf("||  SYSTEME D'INFORMATION AGRICOLE   ||\n");
    printf("======================================\n");

    while (en_cours) {
	// Menu voalohany
	afficher_menu_principal();

	// Takiana manao scanf miverina
	printf("\nSafidio ny voly mety (1-%d) na 0 raha hiala: ",
	       nombre_cultures);
	if (scanf("%d", &choix_culture) != 1) {
	    printf("Fampidirana diso!\n");
	    while (getchar() != '\n');
	    continue;
	}

	if (choix_culture == 0) {
	    printf("Veloma ô!\n");
	    break;
	}

	if (choix_culture >= 1 && choix_culture <= nombre_cultures) {
	    // Menu region
	    afficher_menu_regions();
	    printf("\nSafidio ny faritra mety  (1-%d): ", nombre_regions);

	    if (scanf("%d", &choix_region) != 1) {
		printf("Fampidirana tsy mety!\n");
		while (getchar() != '\n');
		continue;
	    }

	    if (choix_region >= 1 && choix_region <= nombre_regions) {
		afficher_informations_cultures(choix_culture, choix_region);

		// Menu faharoa
		printf("\n--- MENU SECONDARIE ---\n");
		printf("1. Jereo ny fambolena hafa\n");
		printf("2. Hanova faritra ho an'ny voly\n");
		printf("3. Miala\n");
		printf("\nAlefaso ny safidy: ");

		if (scanf("%d", &sous_choix) != 1) {
		    printf("Fampidirana diso!\n");
		    while (getchar() != '\n');
		    continue;
		}

		switch (sous_choix) {
		case 1:
		    // Hijerena culture hafa
		    break;
		case 2:
		    // Hijerena region hafa amin'io culture io
		    break;
		case 3:
		    en_cours = 0;
		    printf("Veloma ary ô!\n");
		    break;
		default:
		    printf("Safidy diso!\n");
		}
	    } else {
		printf("Faritra diso!\n");
	    }
	} else {
	    printf("Fambolena diso!\n");
	}
    }
}
