/** @file prod.h
*  @brief fichier qui contient generalement les declarations des fonctions de base de donné des produits
*/

/** @struct cette structure qui caracterise le produit et leur environnement favorable
 */
typedef struct produit {
	char nom[20];
	int type;
	int sol[3];
	int sais[3];
	int mois[12];
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
 
