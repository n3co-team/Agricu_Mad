#define NAC_H

/** @fn rdata
 * @return nombre de produit recuperre
 */
int rdata(prod choix, lprod** resultat);
int analyse_type(prod* p,prod** r);
int cp_list(prod* p, lprod** lp);
int analyse_mois(prod* p, lprod** res);
int analyse_sol(prod* p, lprod** res);
int analyse_saison(prod* p, lprod** res);
void venull(void* p,char pnom[], char fonct[]);

