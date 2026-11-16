# Synthèse – Programmation en C

## Auteurs
- Bille

---

## 1. Débogage avec GDB

GDB (GNU Debugger) est un outil essentiel pour identifier et corriger les erreurs dans un programme C.

### Workflow typique

```bash
# Compiler avec les symboles de débogage
gcc -ggdb3 -Wall -Wextra mon_programme.c -o mon_programme

# Lancer GDB
gdb mon_programme
```

### Commandes GDB essentielles

| Commande | Description |
|----------|-------------|
| `r` | Exécuter (run) le programme |
| `bt` | Afficher la pile d'appels (backtrace) |
| `break fichier.c:7` | Poser un point d'arrêt à la ligne 7 |
| `p variable` | Afficher la valeur d'une variable |
| `p tableau[0]@5` | Afficher 5 éléments du tableau depuis l'indice 0 |
| `n` | Avancer d'une instruction (next) |
| `s` | Entrer dans une fonction (step) |
| `continue` | Continuer jusqu'au prochain point d'arrêt |
| `quit` | Quitter GDB |

### Erreur classique : `sizeof` vs longueur logique

```c
int tableau[100];
// sizeof(tableau) = 400 (100 * 4 octets) et NON 100
// Il faut utiliser : sizeof(tableau) / sizeof(tableau[0])
for (size_t i = 0; i < sizeof(tableau) / sizeof(tableau[0]); i++) { ... }
```

> **Astuce :** Compiler avec `-Wall -Wextra` permet de détecter de nombreuses erreurs
> avant même de lancer le programme.

---

## 2. Chaîne de compilation en C avec `gcc`

La compilation d'un programme C passe par **5 étapes** :

```
Source (.c)
    ↓  Préprocesseur  → .i  (résolution des #include, macros)
    ↓  Compilateur    → .s  (code assembleur)
    ↓  Assembleur     → .o  (code objet binaire)
    ↓  Éditeur liens  → exécutable (résolution des symboles)
    ↓  Exécution
```

### Commandes détaillées

```bash
gcc -E  source.c  -o source.i   # Préprocesseur uniquement
gcc -S  source.i  -o source.s   # Compilation → assembleur
gcc -c  source.s  -o source.o   # Assemblage → code objet
gcc     source.o  -lm -o prog   # Édition de liens → exécutable
./prog                           # Exécution
```

### Compilation multi-fichiers

Lorsqu'un programme est réparti sur plusieurs fichiers (ex. : `sphere`), chaque
fichier source peut être compilé indépendamment en `.o`, puis liés ensemble :

```bash
gcc -O3 -c main.i    -o main.o
gcc -O3 -c volume.i  -o volume.o
gcc -O3 -c surface.i -o surface.o
gcc main.o volume.o surface.o -lm -o sphere
```

**Avantage :** si on modifie uniquement `volume.c`, seuls `volume.i`, `volume.s`
et `volume.o` doivent être régénérés ; les autres `.o` restent valides.

---

## 3. Manipulation de chaînes en C

En C, une chaîne de caractères est un tableau de `char` terminé par `'\0'`.

### Fonctions standard (`<string.h>`)

| Fonction | Rôle |
|----------|------|
| `strlen(s)` | Longueur de `s` (sans le `'\0'`) |
| `strcpy(dest, src)` | Copier `src` dans `dest` |
| `strcat(dest, src)` | Concaténer `src` à la fin de `dest` |
| `strcmp(s1, s2)` | Comparer `s1` et `s2` (0 = égaux) |
| `strstr(hay, needle)` | Chercher `needle` dans `hay` |

### Implémentation manuelle (sans bibliothèque)

```c
/* Longueur */
int ma_longueur(const char *s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

/* Comparaison */
int ma_strcmp(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}
```

> **Attention :** toujours s'assurer que les buffers de destination sont
> assez grands pour éviter les débordements (buffer overflow).

---

## 4. Gestion des structures et recherche dans les fichiers

### Structures (`struct`)

Les structures permettent de regrouper des données hétérogènes :

```c
typedef struct {
    char   nom[100];
    char   prenom[100];
    char   adresse[100];
    float  notes[4];
} Etudiant;
```

On accède aux champs avec `.` (valeur) ou `->` (pointeur) :

```c
Etudiant e;
strcpy(e.nom, "Dupont");
e.notes[0] = 15.5f;
```

### Lecture de fichiers ligne par ligne

```c
FILE *f = fopen("fichier.txt", "r");
if (f == NULL) { /* gérer l'erreur */ }

char ligne[1024];
while (fgets(ligne, sizeof(ligne), f) != NULL) {
    // traiter ligne
}
fclose(f);
```

**Fonctions clés :**

| Fonction | Description |
|----------|-------------|
| `fopen(nom, mode)` | Ouvrir un fichier (`"r"` lecture, `"w"` écriture) |
| `fgets(buf, n, f)` | Lire au plus `n-1` caractères depuis `f` |
| `fclose(f)` | Fermer le fichier |
| `strstr(ligne, motif)` | Chercher `motif` dans `ligne` |

---

## Conclusion

Ce TP a permis de couvrir les aspects fondamentaux de la programmation en C :
- Le **débogage** avec GDB pour trouver et corriger les erreurs à l'exécution.
- La **chaîne de compilation** complète (`-E`, `-S`, `-c`, édition de liens).
- La **manipulation de chaînes** avec et sans bibliothèque standard.
- L'utilisation des **structures** pour organiser des données complexes.
- La **lecture de fichiers** et la recherche de motifs ligne par ligne.
