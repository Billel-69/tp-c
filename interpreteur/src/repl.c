#include <stdio.h>
#include <string.h>
#define VERSION "0.1"
#define APPLICATION "PLP"
/**
 * Programme qui simule un interpréteur de commandes simple.
 * Il lit les commandes utilisateur et les traite en fonction de leur contenu.
 */
void afficher_aider() {
    
}

void afficher_version(){
    printf("%s version %s\n", APPLICATION, VERSION);
}

void traiter_echo(char commande[1024]) {
    int i =0;
    while (commande[i] != '\0') {
        if (i<4) {
            i++;
            continue;
        }
        else {
            printf("%c", commande[i]);
            i++;
        }
    }
}

int main()
{
    int continuer = 1; // Variable pour contrôler la boucle principale

    // Boucle principale qui lit et traite les commandes utilisateur
    while (continuer)
    {
        printf("> "); // Affiche le prompt de commande

        // Buffer pour stocker la commande utilisateur
        char commande[1024];

        // Lit la commande utilisateur et la stocke dans le buffer
        // (fin de fichier, par exemple Ctrl-D : on quitte la boucle)
        if (fgets(commande, sizeof(commande), stdin) == NULL)
        {
            printf("\n");
            break;
        }

        // Enlève le caractère de fin de ligne ajouté par fgets
        commande[strcspn(commande, "\n")] = 0;

        // Traite la commande en fonction de son contenu
        if (strcmp(commande, "quit") == 0)
        {
            // Quitte le programme si la commande est "quit"
            printf("Arrêt...\n");
            continuer = 0;
        }
        else if (strncmp(commande, "echo ", 5) == 0)
        {
            traiter_echo(commande);
        }
        else if (strncmp(commande, "version ", 5) == 0) {
            afficher_version();
        }
        else
        {
            // Affiche un message d'erreur si la commande est inconnue
            printf("Commande non reconnue. Essayez 'echo <text>' pour afficher du texte, ou tapez 'quit' pour quitter.\n");
        }

        printf("\n"); // Saut de ligne après la sortie
    }

    return 0;
}
