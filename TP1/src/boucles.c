/*
 * Fichier  : boucles.c
 * Objectif : Afficher un triangle rectangle dont les bords sont en '*'
 *            et l'intérieur en '#'. Deux versions : for et do..while.
 * Auteurs  : Bille
 * TP1 - Exercice 1.6
 */

#include <stdio.h>

int main(void) {
    int taille;

    printf("Entrez la taille (< 10) : ");
    scanf("%d", &taille);

    /* Vérification que la taille est inférieure à 10 */
    if (taille >= 10 || taille < 1) {
        printf("Erreur : la taille doit etre entre 1 et 9.\n");
        return 1;
    }

    /* === Version 1 : avec boucle for === */
    printf("\n--- Version FOR ---\n");
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j <= i; j++) {
            /* Dernière ligne : tout en '*' */
            if (i == taille - 1) {
                printf("* ");
            }
            /* Bord gauche ou bord droit */
            else if (j == 0 || j == i) {
                printf("* ");
            }
            /* Intérieur */
            else {
                printf("# ");
            }
        }
        printf("\n");
    }

    /* === Version 2 : avec boucle do..while === */
    printf("\n--- Version DO..WHILE ---\n");
    int i = 0;
    do {
        int j = 0;
        do {
            /* Dernière ligne : tout en '*' */
            if (i == taille - 1) {
                printf("* ");
            }
            /* Bord gauche ou bord droit */
            else if (j == 0 || j == i) {
                printf("* ");
            }
            /* Intérieur */
            else {
                printf("# ");
            }
            j++;
        } while (j <= i);
        printf("\n");
        i++;
    } while (i < taille);

    return 0;
}
