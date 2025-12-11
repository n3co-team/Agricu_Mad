/**  @file dom.c
  *  @bref fichier qui contient les listes pour les cereales
  *  @author Dominique
*/

#include "voamaina.h"
#include"menu_ui.h"

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
    strcpy(regions[0].nom, "\033[1m Alaotra Mangoro \033[0m");
    strcpy(regions[0].caracteristiques,"-Faritra fambolem-bary,mafana no sady be rotsakorana.\n -Tena ilaina amin'ny fampitomboana ny vary izany");

    // Région 2: Analamanga
    regions[1].id = 2;
    strcpy(regions[1].nom, "\033[1m Analamanga \033[0m");
    strcpy(regions[1].caracteristiques, "-Toetr'andro tsy mafana loatra nefa tsy mangatsika ihany koa, \nmisy fiovana tsara eo amin'ny fiovan'ny taona(afovoan-tany)");

    // Région 3: Vakinankaratra
    regions[2].id = 3;
    strcpy(regions[2].nom, "\033[1m Vakinankaratra \033[0m");
    strcpy(regions[2].caracteristiques, "-Toetr'andro mangatsika sy tany avy nisy volkano fa kosa mety amin'ny fambolena satria lemaka");

    // Région 4: Atsinanana
    regions[3].id = 4;
    strcpy(regions[3].nom, "\033[1m Atsinanana \033[0m");
    strcpy(regions[3].caracteristiques, "-Toetr'andro manana mari-pana ambony ary be hamandona (Morotsiraka-Atsinanana)");

    // Région 5: Menabe
    regions[4].id = 5;
    strcpy(regions[4].nom, "\033[1m Menabe \033[0m");
    strcpy(regions[4].caracteristiques, "-Toetr'andro izay tsy dia misy orana firy nefa matetika mafana (Morotsiraka-Andrefana )");

    // Région 6: Boeny
    regions[5].id = 6;
    strcpy(regions[5].nom, "\033[1m Boeny \033[0m");
    strcpy(regions[5].caracteristiques, "-Toetr'andro izay matetika mafana mandritra ny taona (Avaratra-Andrefana)");

    // Région 7: Anosy
    regions[6].id = 7;
    strcpy(regions[6].nom, "\033[1m Anosy \033[0m");
    strcpy(regions[6].caracteristiques, "-Toetr'andro miovaova(atsimo-atsinanana)");

    // Région 8: Diana
    regions[7].id = 8;
    strcpy(regions[7].nom, "\033[1m Diana \033[0m");
    strcpy(regions[7].caracteristiques, "-Manana mari-pana ambony indrindra mandritra ny taona (Tendrony avaratra)");

    nombre_regions = 8;
}

void initialiser_cultures()
{
    // Culture 1: Tsaramaso
    cultures[0].id = 1;
    strcpy(cultures[0].nom, "\033[35m \tTsaramaso \033[0m");
    strcpy(cultures[0].saison_plantation, "Aprily - Mey");
    strcpy(cultures[0].duree_croissance, "3-4 volana");
    strcpy(cultures[0].informations,"-Tany tsy mila rano be loatra fa manjary lo ny fakany. \n-Tsy mila masoandro be loatra, toerana tsy mamay be fa manjary may ny raviny nefa kosa misy azavana tsara ampy itomboany");
    strcpy(cultures[0].code, "TS01");
    int regions_tsaramaso[] = { 1, 2, 3, 4 };
    cultures[0].nb_regions = 4;
    memcpy(cultures[0].regions_compatibles, regions_tsaramaso,
	   sizeof(regions_tsaramaso));

    // Culture 2: Vary
    cultures[1].id = 2;
    strcpy(cultures[1].nom, "\033[35m \tVary \033[0m");
    strcpy(cultures[1].saison_plantation, "Oktobra - Desembra");
    strcpy(cultures[1].duree_croissance, "5-6 volana");
    strcpy(cultures[1].informations,"-Mila rano betsaka sy tsy tapaka fa iny no sakafo ho azy. \n-Tsy azo atao ny manao ny tany tsy misy rano");
    strcpy(cultures[1].code, "VR02");
    int regions_vary[] = { 1, 4, 6, 8 };
    cultures[1].nb_regions = 4;
    memcpy(cultures[1].regions_compatibles, regions_vary,
	   sizeof(regions_vary));

    // Culture 3: Mangahazo
    cultures[2].id = 3;
    strcpy(cultures[2].nom, "\033[35m \tMangahazo \033[0m");
    strcpy(cultures[2].saison_plantation, "Aogositra - Septambra");
    strcpy(cultures[2].duree_croissance, "8-12 volana");
    strcpy(cultures[2].informations,"-Tsy mila rano betsaka, tsy azo asina rano mijanona fa manjary lo ny any ambany.\n -Afaka miaina zany na dia tsy misy rano mandalo aza .");
    strcpy(cultures[2].code, "MG03");
    int regions_mangahazo[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    cultures[2].nb_regions = 8;
    memcpy(cultures[2].regions_compatibles, regions_mangahazo,
	   sizeof(regions_mangahazo));

    // Culture 4: Voanjo
    cultures[3].id = 4;
    strcpy(cultures[3].nom, "\033[35m \tVoanjo \033[0m");
    strcpy(cultures[3].saison_plantation, "Novambra - Janoary");
    strcpy(cultures[3].duree_croissance, "4-5 volana");
    strcpy(cultures[3].informations,"-Mila azavana sy afanana avy amin'ny masoandro, \ntsy maninona zany na tsy misy rano mandalo aza.");
    strcpy(cultures[3].code, "VJ04");
    int regions_voanjo[] = { 4, 5, 6, 7, 8 };
    cultures[3].nb_regions = 5;
    memcpy(cultures[3].regions_compatibles, regions_voanjo,
	   sizeof(regions_voanjo));

    // Culture 5: Ognon
    cultures[4].id = 5;
    strcpy(cultures[4].nom, "\033[35m \tTongolo \033[0m");
    strcpy(cultures[4].saison_plantation, "Martsa - Mey");
    strcpy(cultures[4].duree_croissance, "4-5 volana");
    strcpy(cultures[4].informations,"-Mila zava-maniry na ravin-kazo efa lo mba hivadika zezika ho azy ka hanome otikaina maromaro ho azy.\n-->Noho izany mila tany mando tsara zany ka manondraka azy amin'ny fotoana voafaritra tsara(ohatra: indroa isan'andro).");
    strcpy(cultures[4].code, "OG05");
    int regions_ognon[] = { 1, 2, 3 };
    cultures[4].nb_regions = 3;
    memcpy(cultures[4].regions_compatibles, regions_ognon,
	   sizeof(regions_ognon));

    // Culture 6: Karoty
    cultures[5].id = 6;
    strcpy(cultures[5].nom, "\033[35m \tKaroty \033[0m");
    strcpy(cultures[5].saison_plantation, "Febroary - Aprily");
    strcpy(cultures[5].duree_croissance, "3-4 volana");
    strcpy(cultures[5].informations,"-Mila tany mora volena(malemy),misy rano manodidina ary mety ho an'ny fakan-javamaniry.");
    strcpy(cultures[5].code, "KR06");
    int regions_karoty[] = { 2, 3, 6, 7 };
    cultures[5].nb_regions = 4;
    memcpy(cultures[5].regions_compatibles, regions_karoty,
	   sizeof(regions_karoty));

    // Culture 7: Tomates
    cultures[6].id = 7;
    strcpy(cultures[6].nom, "\033[35m \tVoatabia \033[0m");
    strcpy(cultures[6].saison_plantation, "Aogositra - Oktobra");
    strcpy(cultures[6].duree_croissance, "3-4 volana");
    strcpy(cultures[6].informations,"-Mila azavana sy afanana avy amin'ny masoandro mandritra nny fotoana maharitra mba hitomboany sy afahany mamoha.\n -Mila asiana hazo na tsatoka eo akaikiny mba hijoroany tsara rehefa mamoha ka tsy lavon'ny rivotra");
    strcpy(cultures[6].code, "TM07");
    int regions_tomates[] = { 1, 2, 3, 4, 6, 8 };
    cultures[6].nb_regions = 6;
    memcpy(cultures[6].regions_compatibles, regions_tomates,
	   sizeof(regions_tomates));

    // Culture 8: Brèdes
    cultures[7].id = 8;
    strcpy(cultures[7].nom, "\033[35m \tAnana \033[0m");
    strcpy(cultures[7].saison_plantation, "Isan-taona");
    strcpy(cultures[7].duree_croissance, "1-2 volana");
    strcpy(cultures[7].informations, "-Mila rano ilay izy. Zany hoe mila manondraka azy matetika fa tsy avela maina be \n#ohatra: isan'andro na isaka roa andro fa tsy isak'erinandro .");
    strcpy(cultures[7].code, "BR08");
    int regions_bredes[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    cultures[7].nb_regions = 8;
    memcpy(cultures[7].regions_compatibles, regions_bredes,
	   sizeof(regions_bredes));

    // Culture 9: Ails
    cultures[8].id = 9;
    strcpy(cultures[8].nom, "\033[35m \tTongolo gasy \033[0m");
    strcpy(cultures[8].saison_plantation, "Mey - Jona");
    strcpy(cultures[8].duree_croissance, "5-6 volana");
    strcpy(cultures[8].informations, "-Tsy mila rano betsaka, mety foana na dia amina tany maina aza.");
    strcpy(cultures[8].code, "AL09");
    int regions_ails[] = { 2, 3, 7 };
    cultures[8].nb_regions = 3;
    memcpy(cultures[8].regions_compatibles, regions_ails,
	   sizeof(regions_ails));

    // Culture 10: Ananas
    cultures[9].id = 10;
    strcpy(cultures[9].nom, "\033[35m \tMananasy \033[0m");
    strcpy(cultures[9].saison_plantation, "Desembra - Febroary");
    strcpy(cultures[9].duree_croissance, "18-24 volana");
    strcpy(cultures[9].informations,"-Tany tsy mitazona rano besaka fa madeha tsara.");
    strcpy(cultures[9].code, "AN10");
    int regions_ananas[] = { 4, 5, 6, 8 };
    cultures[9].nb_regions = 4;
    memcpy(cultures[9].regions_compatibles, regions_ananas,
	   sizeof(regions_ananas));

    nombre_cultures = 10;
}

void afficher_menu_principal()
{
    printf("\033[34m -->Lisitr'ireo fambolena misy :\033[0m\n");
    printf("\n--------------------------------\n");

    for (int i = 0; i < nombre_cultures; i++) {
	printf("%2d. %s\n", cultures[i].id, cultures[i].nom);
    }

    //printf("\n0. Quitter le programme\n");
    printf("\n\033[34m -->Fidio ireo fambolena mety (1-%d) na 0 raha hiala: \033[0m",
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
    printf("\n \033[34m === VOLY VOAFIDY ===\033[0m \n\n");
    printf("\033[32m ==> Lisitr'ireo fambolena misy : \033[0m\n");
    printf("\n-----------------------------\n");

    for (int i = 0; i <= nombre_cultures; i++) {
	printf("%d. %s\n", cultures[i].id, cultures[i].nom);

    }
    printf("\n\033[34m ==> Fidio ireo fambolena mety (1-%d): \033[0m ", nombre_cultures);
}


void afficher_menu_regions()
{
    int culture_choix;
    int culture_index = culture_choix - 1;
//    int region_index = region_choix - 1;
    //printf("\n=== SAFIDY FARITRA ===\n\n");
//37
    printf("==> Lisitr'ireo faritra misy ho an'ny voly %s: ",cultures[culture_index].nom);
    printf("\n-----------------------------\n");

    for (int i = 0; i < nombre_regions; i++) {
	printf("%d. %s\n", regions[i].id, regions[i].nom);
    }

    printf("\n\033[34==> Safidio ny faritra mety (1-%d): \033[0m", nombre_regions);
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
    printf("\n¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n");
    printf("\t\n\t\033[34m ===>MOMBAMOMBAN'NY\033[0m%s \n", cultures[culture_index].nom);
    printf("\t\033[34m ===>FARITRA\033[0m: %s\n\n", regions[region_index].nom);
    
    //printf("Code: %s\n", cultures[culture_index].code);
    printf("\t\033[34m ===>Fotoana fambolena\033[0m: %s\n",
	   cultures[culture_index].saison_plantation);
    printf("\t \033[34m===>Faharetan'ny voly\033[0m: %s\n",
	   cultures[culture_index].duree_croissance);

    // Vérifier la compatibilité région/culture
    if (est_region_compatible(culture_choix, region_choix)) {
	printf
	    ("\t\n\t\033[34m ===>METY AMINY\033[0m : Voarindra tsara amin'ny toetran'ny faritra %s io voly ilay voly. Araho tsara foana ny toromarika\n",
	     regions[region_index].nom);
    } else {
	printf
	    ("\t\n\t\033[34m===>TSY METY AMINY \033[0m : Tsy dia mety tsara amin'io faritra %s io voly ilay voly nofidinao. Tsaratsara kokoa raha mijery faritra hafa\n",
	     regions[region_index].nom);
    }
    printf("\n¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");
    printf("\n-------------------------------------------------------\n");
    printf("\n\033[34mToetran'ny faritra\033[0m:                    \n");
    printf("%s\n", regions[region_index].caracteristiques);
    printf("\n-------------------------------------------------------\n");
    printf("\n\033[34mMombamomba sy teknika fambolena \033[0m:\n");
    printf("%s\n", cultures[culture_index].informations);
    printf("\n-------------------------------------------------------\n");
    // Afficher autres régions compatibles
    printf("\n\033[34m Faritra afa mety aminy \033[0m: ");
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

void cereale()
{
    int choix_culture, choix_region, sous_choix;
    int en_cours = 1;

    initialiser_regions();
    initialiser_cultures();
    while (en_cours) {
	// Menu voalohany
	afficher_menu_principal();

	// Takiana manao scanf miverina
	printf("\n==> Safidio ny voly mety (1-%d) na 0 raha hiala: ",
	       nombre_cultures);
	if (scanf("%d", &choix_culture) != 1) {
	    printf("Fampidirana diso!\n");
	    while (getchar() != '\n');
	    continue;
	}

	if (choix_culture == 0) {
	    printf("Misaotra betsaka anao nampiasa ny angom-baovavao mikasika ny ny fambolena. Makasitraka tompoko dia Veloma ô!\n");
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
//		printf("\n--- MENU SECONDARIE ---\n");
		printf("\t1. Jereo ny fambolena hafa\n");
		printf("\t2. Hanova faritra ho an'ny voly\n");
		printf("\t3. Hiverina any amin'ny menu fandraisana\n");
		printf("\t4. Miala\n");
		printf("\n==> Alefaso ny safidy: ");
//teste
		initialiser_cultures();
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
		    //printf("Veloma ary ô!\n");
//		    me_auto();
		    break;
		case 4:
		    en_cours = 0;
		    printf("Veloma!\n");
		    exit(0);
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
