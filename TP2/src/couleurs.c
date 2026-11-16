/*
 * Fichier  : couleurs.c
 * Objectif : Stocker 100 couleurs (R, G, B, A), compter les couleurs distinctes
 *            et afficher chacune avec son nombre d'occurrences.
 * Auteurs  : Bille
 * TP2 - Exercice 2.7
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_COULEURS 100

/* Structure représentant une couleur RGBA */
typedef struct {
    unsigned char r;  /* Rouge   0-255 */
    unsigned char g;  /* Vert    0-255 */
    unsigned char b;  /* Bleu    0-255 */
    unsigned char a;  /* Alpha   0-255 */
} Couleur;

/* Retourne 1 si deux couleurs sont identiques, 0 sinon */
static int couleurs_egales(Couleur c1, Couleur c2) {
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a);
}

int main(void) {
    Couleur tableau[NB_COULEURS];

    /* --- Génération de 100 couleurs aléatoires (avec répétitions volontaires) --- */
    srand((unsigned int)time(NULL));

    /*
     * Pour garantir des doublons, on tire parmi seulement 20 couleurs possibles
     * puis on remplit les 100 cases.
     */
    Couleur palette[20];
    for (int i = 0; i < 20; i++) {
        palette[i].r = (unsigned char)(rand() % 256);
        palette[i].g = (unsigned char)(rand() % 256);
        palette[i].b = (unsigned char)(rand() % 256);
        palette[i].a = (unsigned char)(rand() % 256);
    }

    for (int i = 0; i < NB_COULEURS; i++) {
        tableau[i] = palette[rand() % 20];
    }

    /* --- Comptage des couleurs distinctes --- */
    /*
     * Algorithme : pour chaque couleur, on vérifie si elle a déjà été vue.
     * On utilise un tableau 'vu' pour éviter de la recompter.
     */
    int vu[NB_COULEURS];
    for (int i = 0; i < NB_COULEURS; i++) vu[i] = 0;

    int nb_distincts = 0;

    printf("=== Couleurs distinctes et leurs occurrences ===\n\n");
    printf(" N°  |  R   |  G   |  B   |  A   | Occurrences\n");
    printf("-----|------|------|------|------|------------\n");

    for (int i = 0; i < NB_COULEURS; i++) {
        if (vu[i]) continue;  /* Déjà traitée */

        int count = 1;
        vu[i] = 1;

        /* Chercher les doublons à partir de i+1 */
        for (int j = i + 1; j < NB_COULEURS; j++) {
            if (!vu[j] && couleurs_egales(tableau[i], tableau[j])) {
                count++;
                vu[j] = 1;
            }
        }

        nb_distincts++;
        printf(" %3d | %3u  | %3u  | %3u  | %3u  | %d\n",
               nb_distincts,
               tableau[i].r, tableau[i].g, tableau[i].b, tableau[i].a,
               count);
    }

    printf("\nNombre total de couleurs : %d\n", NB_COULEURS);
    printf("Couleurs distinctes      : %d\n", nb_distincts);

    return 0;
}
