/*
 * Fichier  : erreurs.c
 * Objectif : Démontrer une erreur classique avec sizeof sur un tableau
 *            (sizeof renvoie la taille en octets, pas le nombre d'éléments).
 *            Ce fichier est intentionnellement erroné pour l'exercice GDB.
 * Auteurs  : Bille
 * TP2 - Exercice 2.1
 *
 * ERREUR : sizeof(tableau) = 400 (100 int * 4 octets) et non 100.
 *          Le compteur dépasse donc les bornes du tableau → stack smashing.
 *
 * CORRECTION : utiliser sizeof(tableau) / sizeof(tableau[0])
 *              et déclarer compteur en size_t (type non signé).
 */

#include <stdio.h>

int main(void) {
    int tableau[100];

    /* Erreur intentionnelle : sizeof(tableau) vaut 400 et non 100 */
    for (int compteur = 0; compteur < (int)sizeof(tableau); compteur++) {
        tableau[compteur] = tableau[compteur] * 2;
    }

    return 0;
}
