/*
 * Fichier  : calculs.c
 * Objectif : Opérations arithmétiques et bit à bit avec un switch.
 *            Opérations supportées : +, -, *, /, %, &, |, ~
 * Auteurs  : Bille
 * TP1 - Exercice 1.8
 */

#include <stdio.h>

int main(void) {
    int num1, num2;
    char op;

    printf("Entrez deux nombres : ");
    scanf("%d%d", &num1, &num2);
    printf("Entrez l'operation (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op);

    switch (op) {
        case '+':
            printf("%d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Erreur : division par zero !\n");
            } else {
                printf("%d / %d = %d\n", num1, num2, num1 / num2);
            }
            break;
        case '%':
            if (num2 == 0) {
                printf("Erreur : modulo par zero !\n");
            } else {
                printf("%d %% %d = %d\n", num1, num2, num1 % num2);
            }
            break;
        case '&':
            printf("%d & %d = %d\n", num1, num2, num1 & num2);
            break;
        case '|':
            printf("%d | %d = %d\n", num1, num2, num1 | num2);
            break;
        case '~':
            /* NON bit à bit : opération unaire, appliquée sur num1 uniquement */
            printf("~%d = %d\n", num1, ~num1);
            break;
        default:
            printf("Operateur '%c' non reconnu.\n", op);
            break;
    }

    return 0;
}
