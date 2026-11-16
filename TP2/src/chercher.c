/*
 * Fichier  : chercher.c
 * Objectif : Rechercher une phrase dans un tableau de 10 phrases
 *            SANS utiliser les fonctions de bibliothèques standards (strcmp, etc.)
 * Auteurs  : Bille
 * TP2 - Exercice 2.8
 */

#include <stdio.h>

#define NB_PHRASES    10
#define TAILLE_MAX   256

/* ------------------------------------------------------------------ */
/* Fonctions de manipulation de chaînes SANS bibliothèque standard     */
/* ------------------------------------------------------------------ */

/*
 * Compare deux chaînes caractère par caractère.
 * Retourne 0 si elles sont identiques, une valeur non nulle sinon.
 */
static int ma_strcmp(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];  /* Différence des codes ASCII */
        }
        i++;
    }
    /* Vérifier la fin de chaîne */
    return s1[i] - s2[i];
}

/*
 * Supprime le '\n' final d'une chaîne lue avec fgets.
 */
static void supprimer_newline(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '\n') {
            s[i] = '\0';
            return;
        }
        i++;
    }
}

/* ------------------------------------------------------------------ */
/* Programme principal                                                  */
/* ------------------------------------------------------------------ */

int main(void) {

    /* Tableau de 10 phrases */
    const char *phrases[NB_PHRASES] = {
        "Bonjour, comment ca va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journee.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent etre deroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est interessante.",
        "Les structures de donnees sont importantes.",
        "Programmer en C, c'est genial."
    };

    char recherche[TAILLE_MAX];

    printf("=== Recherche dans un tableau de phrases ===\n\n");

    /* Afficher les phrases disponibles */
    printf("Phrases disponibles :\n");
    for (int i = 0; i < NB_PHRASES; i++) {
        printf("  %2d. %s\n", i + 1, phrases[i]);
    }

    /* Saisie de la phrase à rechercher */
    printf("\nEntrez la phrase à rechercher : ");
    fgets(recherche, sizeof(recherche), stdin);
    supprimer_newline(recherche);

    /* Recherche dans le tableau */
    int trouve = 0;
    for (int i = 0; i < NB_PHRASES; i++) {
        if (ma_strcmp(phrases[i], recherche) == 0) {
            trouve = 1;
            printf("\nPhrase trouvée (position %d).\n", i + 1);
            break;
        }
    }

    if (!trouve) {
        printf("\nPhrase non trouvée.\n");
    }

    return 0;
}
