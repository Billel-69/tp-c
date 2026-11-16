/*
 * Fichier  : cercle.c
 * Objectif : Calculer et afficher l'aire et le périmètre d'un cercle
 *            à partir du rayon saisi par l'utilisateur.
 * Auteurs  : Bille
 * TP1 - Exercice 1.2
 */

#include <stdio.h>

#define PI 3.14159  /* Valeur approchée de pi */

int main(void) {
    float rayon;

    printf("Entrez le rayon : ");
    scanf("%f", &rayon);

    /* Calcul de l'aire : pi * r² */
    float aire = PI * rayon * rayon;

    /* Calcul du périmètre : 2 * pi * r */
    float perimetre = 2 * PI * rayon;

    printf("Aire      : %.2f\n", aire);
    printf("Perimetre : %.2f\n", perimetre);

    return 0;
}
