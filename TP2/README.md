# Auto-évaluation (TP2)

| Exercice | État                   | Remarques                                             |
|----------|------------------------|-------------------------------------------------------|
| 2.1      | Réalisé                | Analyse de erreurs.c avec GDB ; réponse à la question `-Wall -Wextra` |
| 2.2      | Réalisé                | aire.c compilé étape par étape (E/S/c/lien)           |
| 2.3      | Réalisé                | Programme sphere multi-fichiers (main, surface, volume)|
| 2.4      | Réalisé                | chaine.c : longueur, copie, concaténation             |
| 2.5      | Réalisé                | bd_ecole.c : structure Etudiant, saisie + affichage   |
| 2.6      | Réalisé                | phrases.c : recherche phrase dans fichier, occurrences|
| 2.7      | Réalisé                | couleurs.c : structure Couleur RGBA, couleurs distinctes|
| 2.8      | Réalisé                | chercher.c : recherche sans bibliothèque standard     |
| 2.9      | Réalisé                | programmation_C.md : rapport de synthèse              |

# Bibliothèques
* `<stdio.h>` – entrées/sorties standard (`printf`, `scanf`, `fgets`, `fopen`, `fclose`)
* `<string.h>` – manipulation de chaînes (`strcpy`, `strlen`, `strstr`, `strcmp`)
* `<math.h>` – fonctions mathématiques (`M_PI`, `pow`) – lier avec `-lm`
* `<stdlib.h>` – utilitaires généraux (`rand`, `srand`)
* `<time.h>` – gestion du temps (`time`) pour l'initialisation de `srand`

# Références
* [Documentation GDB officielle](https://www.gnu.org/software/gdb/documentation/)
* [Manuel GCC](https://gcc.gnu.org/onlinedocs/)
* [cppreference.com – string.h](https://en.cppreference.com/w/c/string/byte)
* [The C Programming Language – Kernighan & Ritchie](https://fr.wikipedia.org/wiki/The_C_Programming_Language)

# Difficulté
* Exercice 2.8 : implémenter `strcmp` manuellement et comprendre la comparaison caractère par caractère.
* Exercice 2.7 : algorithme de comptage des couleurs distinctes sans doublons.
* Exercice 2.6 : gestion des cas limites (fichier inexistant, phrases sans `\n` final).

# Commentaires
* La compilation multi-fichiers (Ex. 2.3) illustre bien pourquoi les Makefiles sont utiles en pratique.
* GDB est un outil puissant mais nécessite `-ggdb3` pour avoir des informations de débogage riches.
* L'utilisation de `fgets` au lieu de `scanf` pour lire des chaînes évite les débordements de buffer.
