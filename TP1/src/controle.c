/*
 * Fichier  : controle.c
 * Objectif : Parcourir les nombres de 1 à 1000 et appliquer des conditions
 *            de divisibilité avec différentes boucles et structures de contrôle.
 * Auteurs  : Bille
 * TP1 - Exercice 1.7
 */

#include <stdio.h>

int main(void) {

    /* --- Condition 1 (boucle for) : divisible par 4 mais pas par 6 --- */
    printf("=== Divisible par 4 mais pas par 6 ===\n");
    for (int i = 1; i <= 1000; i++) {
        if (i % 4 == 0 && i % 6 != 0) {
            printf("%d\n", i);
        }
    }

    /* --- Condition 2 (boucle while) : nombre pair et divisible par 8 --- */
    printf("\n=== Pair et divisible par 8 ===\n");
    int i = 1;
    while (i <= 1000) {
        if (i % 2 == 0 && i % 8 == 0) {
            printf("%d\n", i);
        }
        i++;
    }

    /* --- Condition 3 (boucle do..while) : divisible par 5 ou 7 mais pas par 10 --- */
    printf("\n=== Divisible par 5 ou 7 mais pas par 10 ===\n");
    int j = 1;
    do {
        /* Parenthèses nécessaires : || a une priorité plus basse que && */
        if ((j % 5 == 0 || j % 7 == 0) && j % 10 != 0) {
            printf("%d\n", j);
        }
        j++;
    } while (j <= 1000);

    return 0;
}
