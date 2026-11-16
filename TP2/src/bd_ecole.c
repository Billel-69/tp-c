/*
 * Fichier  : bd_ecole.c
 * Objectif : Gestion des données de 5 étudiant.e.s via une structure en C
 *            (saisie, stockage, affichage)
 * Auteurs  : Bille
 * TP2 - Exercice 2.5
 */

#include <stdio.h>
#include <string.h>

#define NB_ETUDIANTS  5
#define NB_NOTES      4
#define TAILLE_CHAINE 100

/* Structure représentant un.e étudiant.e */
typedef struct {
    char nom[TAILLE_CHAINE];
    char prenom[TAILLE_CHAINE];
    char adresse[TAILLE_CHAINE];
    float notes[NB_NOTES];
} Etudiant;

/* Supprime le '\n' final d'une chaîne lue avec fgets */
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

/* Calcule la moyenne des notes d'un.e étudiant.e */
static float calculer_moyenne(const float *notes, int nb) {
    float somme = 0.0f;
    for (int i = 0; i < nb; i++) {
        somme += notes[i];
    }
    return somme / nb;
}

/* Saisit les informations d'un.e étudiant.e */
static void saisir_etudiant(Etudiant *e, int numero) {
    printf("\n=== Étudiant.e %d ===\n", numero);

    printf("  Nom       : ");
    fgets(e->nom, TAILLE_CHAINE, stdin);
    supprimer_newline(e->nom);

    printf("  Prénom    : ");
    fgets(e->prenom, TAILLE_CHAINE, stdin);
    supprimer_newline(e->prenom);

    printf("  Adresse   : ");
    fgets(e->adresse, TAILLE_CHAINE, stdin);
    supprimer_newline(e->adresse);

    printf("  Notes (%d au total) :\n", NB_NOTES);
    for (int i = 0; i < NB_NOTES; i++) {
        printf("    Note %d : ", i + 1);
        scanf("%f", &e->notes[i]);
    }
    /* Vider le buffer après scanf */
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Affiche les informations d'un.e étudiant.e */
static void afficher_etudiant(const Etudiant *e, int numero) {
    printf("\n--- Étudiant.e %d ---\n", numero);
    printf("  Nom       : %s\n", e->nom);
    printf("  Prénom    : %s\n", e->prenom);
    printf("  Adresse   : %s\n", e->adresse);
    printf("  Notes     : ");
    for (int i = 0; i < NB_NOTES; i++) {
        printf("%.2f  ", e->notes[i]);
    }
    printf("\n  Moyenne   : %.2f\n", calculer_moyenne(e->notes, NB_NOTES));
}

int main(void) {
    Etudiant etudiants[NB_ETUDIANTS];

    printf("=== Saisie des données des étudiant.e.s ===\n");

    /* Saisie des données */
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        saisir_etudiant(&etudiants[i], i + 1);
    }

    /* Affichage des données */
    printf("\n\n=== Récapitulatif des étudiant.e.s ===");
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        afficher_etudiant(&etudiants[i], i + 1);
    }

    printf("\n");
    return 0;
}
