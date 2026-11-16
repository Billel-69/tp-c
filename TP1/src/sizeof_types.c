/*
 * Fichier  : sizeof_types.c
 * Objectif : Afficher la taille en octets de tous les types de base en C
 *            à l'aide de l'opérateur sizeof().
 * Auteurs  : Bille
 * TP1 - Exercice 1.3
 */

#include <stdio.h>

int main(void) {
    /* Types caractères */
    printf("sizeof(char)          = %zu octet(s)\n", sizeof(char));
    printf("sizeof(signed char)   = %zu octet(s)\n", sizeof(signed char));
    printf("sizeof(unsigned char) = %zu octet(s)\n", sizeof(unsigned char));

    /* Types entiers courts */
    printf("sizeof(short)          = %zu octet(s)\n", sizeof(short));
    printf("sizeof(unsigned short) = %zu octet(s)\n", sizeof(unsigned short));

    /* Types entiers standards et longs */
    printf("sizeof(int)            = %zu octet(s)\n", sizeof(int));
    printf("sizeof(unsigned int)   = %zu octet(s)\n", sizeof(unsigned int));
    printf("sizeof(long)           = %zu octet(s)\n", sizeof(long));
    printf("sizeof(unsigned long)  = %zu octet(s)\n", sizeof(unsigned long));
    printf("sizeof(long long)      = %zu octet(s)\n", sizeof(long long));

    /* Types à virgule flottante */
    printf("sizeof(float)          = %zu octet(s)\n", sizeof(float));
    printf("sizeof(double)         = %zu octet(s)\n", sizeof(double));
    printf("sizeof(long double)    = %zu octet(s)\n", sizeof(long double));

    return 0;
}
