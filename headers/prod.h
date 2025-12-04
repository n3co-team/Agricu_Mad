/** @file prod.h
 *  @brief fichier qui contient generalement les declarations des fonctions de base de donné des produits
 */

#define PROD_H

/** @struct cette structure qui caracterise le produit et leur environnement favorable
 */
typedef struct produit {
	char nom[20];
	int type;
	int sol[11];
	int sais[5];
	int mois[12];
	/** @var cette variable sert à stock le nombre total de produit disponible 
	 * @brief il situe au premier tableau
	 **/
	int ntp;	//nombre de broduit
} prod;

typedef struct list_produit {
	prod* c;
	struct list_produit* s;
} lprod;

/** @fn cette fonction qui stock le donnée de tubercule
 *  @param void
 *  @return prod*
 */
prod* tubercule();

/** @fn cette fonction qui stock le donnée de racine
 *  @param void
 *  @return prod*
 */
prod* racine(); 

/** @fn cette fonction qui stock le donnée de fruit
 *  @param void
 *  @return prod*
 */
prod* fruit(); 
