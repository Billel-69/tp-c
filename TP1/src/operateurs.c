/*
 * Fichier  : operateurs.c
 * Objectif : Utiliser les opérateurs arithmétiques et logiques en C
 *            (addition, soustraction, multiplication, division, modulo,
 *             comparaisons : égalité et supérieur).
 * Auteurs  : Bille
 * TP1 - Exercice 1.5
 */

#include <stdio.h>

int main(void) {
    int a = 16;
    int b = 3;

    /* Opérations arithmétiques */
    printf("addition       : %d + %d = %d\n", a, b, a + b);
    printf("soustraction   : %d - %d = %d\n", a, b, a - b);
    printf("multiplication : %d * %d = %d\n", a, b, a * b);
    printf("division       : %d / %d = %d\n", a, b, a / b);
    printf("modulo         : %d %% %d = %d\n", a, b, a % b);

    /* Comparaisons */
    printf("egalite (==)   : %d == %d -> %d\n", a, b, a == b);
    printf("superieur (>)  : %d > %d  -> %d\n", a, b, a > b);

    return 0;
}
