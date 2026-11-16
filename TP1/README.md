# Auto-évaluation (TP1)
| Exercice | État       | Remarques                                          |
|----------|------------|----------------------------------------------------|
| 1.1      | réalisé    | Affichage de "Bonjour le Monde!"                   |
| 1.2      | réalisé    | Aire et périmètre d'un cercle                      |
| 1.3      | réalisé    | Tailles de tous les types de base avec sizeof       |
| 1.4      | réalisé    | Variables signées et non signées, affichage complet |
| 1.5      | réalisé    | Opérateurs arithmétiques et comparaisons            |
| 1.6      | réalisé    | Triangle rectangle (versions for et do..while)      |
| 1.7      | réalisé    | Conditions de divisibilité (for, while, do..while)  |
| 1.8      | réalisé    | Calculatrice avec switch (+, -, *, /, %, &, |, ~)  |
| 1.9      | réalisé    | Conversion en binaire, test avec plusieurs valeurs  |

# Bibliothèques
* `<stdio.h>` – entrées/sorties standard (`printf`, `scanf`)
* `<math.h>` – bibliothèque mathématique (utilisée pour la compilation avec `-lm`)

# Références
* [The C Programming Language – Kernighan & Ritchie](https://fr.wikipedia.org/wiki/The_C_Programming_Language)
* [cppreference.com](https://en.cppreference.com/w/c)

# Difficulté
* Exercice 1.6 : gestion des bords et de l'intérieur du triangle avec deux versions de boucles.
* Exercice 1.7 : attention à la priorité des opérateurs logiques (`&&` avant `||`).
* Exercice 1.9 : afficher les bits dans le bon ordre (du poids fort au poids faible).

# Commentaires
* Les opérateurs bit à bit (Ex. 1.8) permettent de mieux comprendre la représentation interne des entiers.
* La conversion en binaire (Ex. 1.9) illustre le fonctionnement de la division euclidienne successive.
