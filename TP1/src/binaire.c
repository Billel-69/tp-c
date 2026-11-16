/*
 * Fichier  : binaire.c
 * Objectif : Convertir un nombre entier en représentation binaire
 *            en utilisant la division par 2 et le reste.
 * Auteurs  : Bille
 * TP1 - Exercice 1.9
 */

#include <stdio.h>

/* Affiche la représentation binaire d'un entier positif ou nul */
void afficherBinaire(int n) {
    if (n == 0) {
        printf("0\n");
        return;
    }

    int binaire[32]; /* 32 bits max pour un int */
    int i = 0;

    while (n > 0) {
        binaire[i] = n % 2;  /* Le reste donne le bit courant */
        n = n / 2;
        i++;
    }

    /* Affichage dans l'ordre correct (du bit de poids fort au bit de poids faible) */
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaire[j]);
    }
    printf("\n");
}

int main(void) {
    /* Test avec les valeurs demandées dans l'énoncé */
    int valeurs[] = {0, 4096, 65536, 65535, 1024};
    int nb = sizeof(valeurs) / sizeof(valeurs[0]);

    for (int k = 0; k < nb; k++) {
        printf("Binaire de %5d : ", valeurs[k]);
        afficherBinaire(valeurs[k]);
    }

    return 0;
}
