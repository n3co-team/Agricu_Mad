#include"prod.h"

/** @fn menu_list
* @details fonction qui contient les appel de fonction des menu
* @return void
*/

void me_list (int i, prod* p);

/** @fn me_pri
* @details fonction pour menu principal
* @param struct produit
* @return void
*/
void me_pri(prod* p);

/** @fn me_sty
* @details menu sans choix type de produit
* @param struct produit
* @return void
*/
void me_sty (prod* p);

/** @fn me_sso
* @details menu sans choix de sol
* @param struct produit
* @return void
*/
void me_sso (prod* p);

/** @fn me_ssa
* @details menu sans choix de saison
* @param struct produit
* @return void
*/
void me_ssa (prod* p);

/** @fn me_smo
* @details menu sans choix de mois
* @param struct produit
* @return void
*/
void me_smo (prod* p);

/** @fn me_ssamo
* @details menu sans choix de saison et  mois
* @param struct produit
* @return void
*/
void me_ssamo (prod* p);

/** @fn me_styso
* @details menu sans choix de saison et  mois
* @param struct produit
* @return void
*/
void me_styso (prod* p);

/** @fn me_styso
* @details menu sans choix de saison et  mois
* @param struct produit
* @return void
*/
void me_styso (prod* p);

/** @fn me_stysamo
* @details menu sans choix de saison et  mois
* @param struct produit
* @return void
*/
void me_stysamo (prod* p);

/** @fn me_ssosamo
* @details menu sans choix de saison et  mois
* @param struct produit
* @return void
*/
void me_ssosamo (prod* p);

/** @fn choix_car gère le choix
* @param int, ,int
* @return int
*/
int choix_car(int ch_min, int ch_max);

/** @fn lcmois menu mois
* @param prod*
* @return void
*/
void lcmois(prod *p);

/** @fn lctype menu type de produit
* @param prod*
* @return void
*/
void lctype(prod *p);

/** @fn lcsol menu sol
* @param prod*
* @return void
*/
void lcsol(prod *p);

/** @fn lcsaison menu mois
* @param prod*
* @return void
*/
void lcsaison(prod* p); 
