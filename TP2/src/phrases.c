/*
 * Fichier  : phrases.c
 * Objectif : Rechercher une phrase dans un fichier texte et compter
 *            le nombre d'occurrences par ligne.
 * Auteurs  : Bille
 * TP2 - Exercice 2.6
 */

#include <stdio.h>
#include <string.h>

#define TAILLE_LIGNE   1024
#define TAILLE_PHRASE  512

/*
 * Compte le nombre d'occurrences de 'motif' dans 'texte'.
 * Utilise strstr pour la recherche.
 */
static int compter_occurrences(const char *texte, const char *motif) {
    int count = 0;
    const char *pos = texte;
    size_t len_motif = strlen(motif);

    if (len_motif == 0) return 0;

    while ((pos = strstr(pos, motif)) != NULL) {
        count++;
        pos += len_motif;  /* Avancer après l'occurrence trouvée */
    }
    return count;
}

int main(void) {
    char nom_fichier[TAILLE_PHRASE];
    char phrase[TAILLE_PHRASE];
    char ligne[TAILLE_LIGNE];
    FILE *fichier;
    int num_ligne = 0;
    int total = 0;

    /* Saisie du nom du fichier */
    printf("Entrez le nom du fichier : ");
    fgets(nom_fichier, sizeof(nom_fichier), stdin);
    /* Supprimer '\n' */
    int i = 0;
    while (nom_fichier[i] != '\0') {
        if (nom_fichier[i] == '\n') { nom_fichier[i] = '\0'; break; }
        i++;
    }

    /* Saisie de la phrase à rechercher */
    printf("Entrez la phrase à rechercher : ");
    fgets(phrase, sizeof(phrase), stdin);
    /* Supprimer '\n' */
    i = 0;
    while (phrase[i] != '\0') {
        if (phrase[i] == '\n') { phrase[i] = '\0'; break; }
        i++;
    }

    /* Ouverture du fichier */
    fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier \"%s\".\n", nom_fichier);
        return 1;
    }

    printf("\n=== Résultats de la recherche ===\n");
    printf("Fichier : %s\n", nom_fichier);
    printf("Phrase  : \"%s\"\n\n", phrase);

    /* Lecture ligne par ligne */
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        num_ligne++;
        int occ = compter_occurrences(ligne, phrase);
        if (occ > 0) {
            printf("Ligne %4d : %d occurrence(s) -> %s", num_ligne, occ, ligne);
            /* Ajouter saut de ligne si absent */
            if (ligne[strlen(ligne) - 1] != '\n') printf("\n");
            total += occ;
        }
    }

    fclose(fichier);

    if (total == 0) {
        printf("Aucune occurrence de \"%s\" trouvée dans le fichier.\n", phrase);
    } else {
        printf("\nTotal : %d occurrence(s) de \"%s\" dans %d ligne(s).\n",
               total, phrase, num_ligne);
    }

    return 0;
}
