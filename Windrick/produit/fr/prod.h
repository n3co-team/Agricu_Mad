/** @file prod.h
* @brief fichier qui contient les declarations des fonctions nessesaires pour la base de donnée des produits
*@author Windrick
*/

/** @struct cette structure qui caracterise le produit et leur environnement favorable
 */
typedef struct produit {
	char nom[20];
	int type;
	int soli[4];
	int sais[4];
	int mois[12];
} prod;

/** @fn cette fonction qui stock le donnée de tubercule
 * @param void
 * @return prod*
 */
prod* tubercule();
 
