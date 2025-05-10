#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "game.h"
#include "display.h"
#include "player.h"
#include "card.h"
#include "utils.h"
#include "save.h"

int main() {
// Pour Windows, décommenter cette ligne pour activer les couleurs ANSI
// system("color");

// Initialiser le générateur de nombres aléatoires
initRandom();

// Initialiser l'état du jeu
GameState game;
bool quit = false;

// Afficher le message de bienvenue
afficher_bienvenue();

// Boucle principale du programme
while (!quit) {
    int choice = displayMainMenu();
    
    switch (choice) {
        case 1: // Nouvelle partie
            if (displayGameSetupMenu(&game)) {
                if (initializeGame(&game, game.numPlayers, game.valueMode, game.cardNumberMode)) { // se situe dans game.h
                    startGame(&game);
                }
            }
            break;
            
        case 2: // Charger une partie
        {
            char* filename = listSavedGames();
            if (filename != NULL) {
                if (loadGame(&game, filename)) {
                    afficher_info("Partie chargée avec succès!");
                    startGame(&game);
                } else {
                    afficher_erreur("Impossible de charger la partie.");
                }
                free(filename);
            }
        }
        break;
            
        case 3: // Afficher les instructions
            afficher_instructions();
            pauseWithMessage("Appuyez sur Entrée pour continuer...");
            break;
            
        case 4: // Quitter
            quit = true;
            break;
            
        default:
            afficher_erreur("Option non valide.");
            break;
    }
}

printf("Merci d'avoir joué à Card Yard!\n");
return 0;
}
