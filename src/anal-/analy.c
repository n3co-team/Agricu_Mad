#include<stdio.h>
#include<stdlib.h>
#ifndef PROD_H
#include"prod.h"
#endif
#ifndef ANAL_H
#include"anal.h"
#endif
// analyse de saison desiré
int saison_d(prod* p, int i) {
	int j;
	for (j=0; j<5; j++) {
		if (p->sais[j] == i) {
			return 1;
		}
	}
	return -1;
}

// verfication de mois sur un produit
int mois_d(prod* p, int i) {
	int j;
	for (j=0; j<12; j++) {
		if (p->mois[j] == i) {
			return 1;
		}
	}
	return -1;
}

// verfication de type sur un produit
int type_d(prod* p, int i) {
	if (p->type == i) {
		return 1;
	}
	return -1;
}

// verfication de sol favorable sur un produit
int sol_d(prod* p,int i) 
{
	int j;
	for (j=0; j<11; j++) {
		if (p->sol[j] == i) {
			return 1;
		}
	}
	return -1;
}

// copie le contenu du tableau de struct prod dans struct lprod
void tr_lprod(prod* p, lprod** lp) 
{
    if (p == NULL) return;
    if (*lp == NULL) {
        *lp = malloc(sizeof(lprod));
        if (*lp == NULL) {
            fprintf(stderr, "Erreur de l'allocation de memoire\n");
            exit(1);
        }
        (*lp)->c = p;
        (*lp)->s = NULL;
    } else {
        lprod* cur = *lp;
        while (cur->s != NULL) cur = cur->s;
        cur->s = malloc(sizeof(lprod));
        if (cur->s == NULL) {
            fprintf(stderr, "Erreur de l'allocation de memoire\n");
            exit(1);
        }
        cur->s->c = p;
        cur->s->s = NULL;
    }
}

lprod* analyse_type(prod* p, lprod** lp) {
    prod* pt = NULL;	/* pointeur pour recuperer le donner de produit */

    if (p == NULL) return NULL;

    switch (p->type) {
        case 1: printf("céréal : pas disponible\n"); return NULL;
        case 2: printf("légumineuse : pas disponible\n"); return NULL;
        case 3: printf("fruit\n"); return NULL;
        case 4: printf("legume : pas disponible\n"); return NULL;
        case 5:
            pt = tubercule();
            if (pt == NULL) {
                fprintf(stderr, "tubercule() a retourné NULL\n");
                return NULL;
            }
            tr_lprod(pt, lp);
            /* Ne pas free(pt) : la liste stocke le pointeur retourné par tubercule().
               Si vous voulez stocker une copie, écrivez une fonction de copie. */
            return *lp;
        case 6: printf("racine : pas disponible\n"); return NULL;
        default: printf("indefine\n"); return NULL;
    }
}

int supp_lprod_cont(lprod* lp)
{
    if (lp == NULL || lp->s == NULL) return 0; // rien à supprimer
    lprod* lpt = lp->s;	// temporaire à supprimer
    if (lpt->s != NULL) {
        lp->s = lpt->s;
        free(lpt);
        return 1;
    } else {
        lp->s = NULL;
        free(lpt);
        return 2;
    }
}
// analyse de base de donner pour le mois
void analyse_mois(prod *p, lprod** lp)
{
    if (p == NULL || lp == NULL || *lp == NULL) return;

    int mois = p->mois[0];
    if (mois == 0) return;

    lprod* lpt = *lp;
    prod* pt = lpt ? lpt->c : NULL;

    /* Déplacer la tête jusqu'à un produit valide (ou fin) */
    while (lpt != NULL && (pt == NULL || mois_d(pt, mois) != 1)) {
        if (lpt->s != NULL) {
            *lp = lpt->s;
            free(lpt);
            lpt = *lp;
            pt = lpt ? lpt->c : NULL;
        } else {
            fprintf(stderr,"Analyse de mois échouée : pas de produit correspondant\n");
            *lp = NULL;
            return;
        }
    }

    /* Parcourir la liste et supprimer les éléments non valides après la tête */
    while (lpt != NULL) {
        if (pt == NULL || mois_d(pt, mois) != 1) {
            int r = supp_lprod_cont(lpt);
            if (r == 2) break; /* fin de liste */
            /* si r == 1 on a bien supprimé lpt->s, continuer sans avancer lpt */
        } else {
            /* produit valide : avancer */
            lpt = lpt->s;
            if (lpt == NULL) break;
            pt = lpt->c;
        }
    }
}

// analyse de base de donner pour le saison
void analyse_saison(prod *p, lprod** lp)
{
    if (p == NULL || lp == NULL || *lp == NULL) return;

    int saison = p->sais[0];
    if (saison == 0) return;

    lprod* lpt = *lp;
    prod* pt = lpt ? lpt->c : NULL;

    while (lpt != NULL && (pt == NULL || saison_d(pt, saison) != 1)) {
        if (lpt->s != NULL) {
            *lp = lpt->s;
            free(lpt);
            lpt = *lp;
            pt = lpt ? lpt->c : NULL;
        } else {
            fprintf(stderr,"Analyse de saison échouée : pas de produit correspondant\n");
            *lp = NULL;
            return;
        }
    }

    while (lpt != NULL) {
        if (pt == NULL || saison_d(pt, saison) != 1) {
            int r = supp_lprod_cont(lpt);
            if (r == 2) break;
        } else {
            lpt = lpt->s;
            if (lpt == NULL) break;
            pt = lpt->c;
        }
    }
}

// analyse de base de donner pour le sol
void analyse_sol(prod *p, lprod** lp)
{
    if (p == NULL || lp == NULL || *lp == NULL) return;

    int sol = p->sol[0];
    if (sol == 0) return;

    lprod* lpt = *lp;
    prod* pt = lpt ? lpt->c : NULL;

    while (lpt != NULL && (pt == NULL || sol_d(pt, sol) != 1)) {
        if (lpt->s != NULL) {
            *lp = lpt->s;
            free(lpt);
            lpt = *lp;
            pt = lpt ? lpt->c : NULL;
        } else {
            fprintf(stderr,"Analyse de sol échouée : pas de produit correspondant\n");
            *lp = NULL;
            return;
        }
    }

    while (lpt != NULL) {
        if (pt == NULL || sol_d(pt, sol) != 1) {
            int r = supp_lprod_cont(lpt);
            if (r == 2) break;
        } else {
            lpt = lpt->s;
            if (lpt == NULL) break;
            pt = lpt->c;
        }
    }
}

void analyse_bd(prod* p, lprod** lp)
{
    if (p == NULL || lp == NULL) return;
    analyse_type(p, lp);
    venull(*lp,"lp","analyse_bd");
    analyse_mois(p, lp);	
    analyse_saison(p, lp);	
    analyse_sol(p, lp);	
}

void venull(void* p,char pnom[], char fonct[])
{
	if (p==NULL) {
		fprintf(stderr,"%s est encore NULL dans le fonction %s\n",pnom,fonct);
		exit (1);
	}
}
