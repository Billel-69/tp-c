/*
 * Fichier  : variables.c
 * Objectif : Déclarer, affecter et afficher des variables de tous les types
 *            de base en C (signés et non signés), avec des valeurs représentatives.
 * Auteurs  : Bille
 * TP1 - Exercice 1.4
 */

#include <stdio.h>

int main(void) {
    /* --- Caractères --- */
    char c = 'A';
    signed char sc = -42;
    unsigned char uc = 200;

    /* --- Entiers courts --- */
    short s = -15000;
    unsigned short us = 50000;

    /* --- Entiers standards --- */
    int i = -123456;
    unsigned int ui = 4000000000U;

    /* --- Entiers longs --- */
    long li = -2000000000L;
    unsigned long uli = 4000000000UL;

    /* --- Entiers très longs --- */
    long long lli = -9000000000000000000LL;
    unsigned long long ulli = 18000000000000000000ULL;

    /* --- Nombres à virgule flottante --- */
    float f = 3.14159f;
    double d = -2.71828182846;
    long double ld = 1.234567890123456789L;

    /* Affichage de toutes les variables */
    printf("--- Caracteres ---\n");
    printf("char : c = %c\n", c);
    printf("signed char : sc = %d\n", sc);
    printf("unsigned char : uc = %u\n", uc);

    printf("\n--- Entiers courts ---\n");
    printf("short : s = %d\n", s);
    printf("unsigned short : us = %u\n", us);

    printf("\n--- Entiers standards ---\n");
    printf("int : i = %d\n", i);
    printf("unsigned int : ui = %u\n", ui);

    printf("\n--- Entiers longs ---\n");
    printf("long int : li = %ld\n", li);
    printf("unsigned long int : uli = %lu\n", uli);

    printf("\n--- Entiers tres longs ---\n");
    printf("long long int : lli = %lld\n", lli);
    printf("unsigned long long int : ulli = %llu\n", ulli);

    printf("\n--- Nombres a virgule flottante ---\n");
    printf("float : f = %.5f\n", f);
    printf("double : d = %.11lf\n", d);
    printf("long double : ld = %.18Lf\n", ld);

    return 0;
}
