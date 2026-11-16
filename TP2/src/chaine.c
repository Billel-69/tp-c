/*
 * Fichier  : chaine.c
 * Objectif : Manipulation de chaînes de caractères en C
 *            (longueur, copie, concaténation) sans utiliser strlen/strcpy/strcat
 * Auteurs  : Bille
 * TP2 - Exercice 2.4
 */

#include <stdio.h>

/* Calcule la longueur d'une chaîne (sans compter le '\0') */
int ma_longueur(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

/* Copie la chaîne src dans dest (dest doit être assez grand) */
void ma_copie(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  /* Terminateur nul */
}

/* Concatène src à la fin de dest (dest doit avoir la place suffisante) */
void ma_concatenation(char *dest, const char *src) {
    int i = 0;
    int j = 0;

    /* Aller à la fin de dest */
    while (dest[i] != '\0') {
        i++;
    }

    /* Copier src à partir de la fin de dest */
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';  /* Terminateur nul */
}

int main(void) {
    char chaine1[256];
    char chaine2[256];
    char copie[256];
    char concat[512];

    /* Saisie des deux chaînes */
    printf("Entrez la première chaîne : ");
    fgets(chaine1, sizeof(chaine1), stdin);

    /* Supprimer le '\n' laissé par fgets */
    int i = 0;
    while (chaine1[i] != '\0') {
        if (chaine1[i] == '\n') {
            chaine1[i] = '\0';
            break;
        }
        i++;
    }

    printf("Entrez la deuxième chaîne : ");
    fgets(chaine2, sizeof(chaine2), stdin);

    /* Supprimer le '\n' laissé par fgets */
    i = 0;
    while (chaine2[i] != '\0') {
        if (chaine2[i] == '\n') {
            chaine2[i] = '\0';
            break;
        }
        i++;
    }

    /* 1. Longueur des chaînes */
    printf("\n--- Longueur ---\n");
    printf("Longueur de \"%s\" : %d\n", chaine1, ma_longueur(chaine1));
    printf("Longueur de \"%s\" : %d\n", chaine2, ma_longueur(chaine2));

    /* 2. Copie de chaine1 dans copie */
    printf("\n--- Copie ---\n");
    ma_copie(copie, chaine1);
    printf("Copie de \"%s\" : \"%s\"\n", chaine1, copie);

    /* 3. Concaténation de chaine1 et chaine2 */
    printf("\n--- Concaténation ---\n");
    ma_copie(concat, chaine1);   /* concat = chaine1 */
    ma_concatenation(concat, " "); /* séparateur espace */
    ma_concatenation(concat, chaine2);
    printf("Concaténation : \"%s\"\n", concat);

    return 0;
}
