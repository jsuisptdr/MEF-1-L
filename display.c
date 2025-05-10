/**
 * @file display.c
 * @brief Implémentation des fonctions d'affichage du jeu
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 #include "display.h"
 #include "game.h"
 
 const char* obtenir_couleur(int valeur) {
     if (valeur == EMPTY_CARD) return BLANC; // Cartes non retournées en blanc
     else if (valeur == -5) return ROUGE;
     else if (valeur == -4) return B_ROUGE;
     else if (valeur == -3) return VERT;
     else if (valeur == -2) return B_VERT;
     else if (valeur == -1) return JAUNE;
     else if (valeur == 0) return B_JAUNE;
     else if (valeur == 1) return BLEU;
     else if (valeur == 2) return B_BLEU;
     else if (valeur == 3) return MAGENTA;
     else if (valeur == 4) return B_MAGENTA;
     else if (valeur == 5) return CYAN;
     else if (valeur == 6) return B_CYAN;
     else if (valeur == 7) return ROUGE;
     else if (valeur == 8) return B_ROUGE;
     else if (valeur == 9) return VERT;
     else if (valeur == 10) return B_VERT;
     else if (valeur == 11) return BLEU;
     else if (valeur == 12) return B_BLEU;
     else if (valeur == 13) return MAGENTA;
     else if (valeur == 14) return B_MAGENTA;
     else if (valeur == 15) return CYAN;
     else return BLANC; // Valeur par défaut
 }
 
 void afficher_ligne_cartes(int joueurs[][MAX_CARDS_PER_PLAYER], int debut, int fin, int indice_carte_debut, int indice_carte_fin) {
     // Première ligne des cartes (bordure supérieure)
     for (int j = debut; j <= fin; j++) {
         for (int i = indice_carte_debut; i <= indice_carte_fin; i++) {
             const char* couleur = obtenir_couleur(joueurs[j][i]);
             printf("%s┌──────┐%s ", couleur, RESET);
         }
         printf("   ");  // Espace entre les joueurs
     }
     printf("\n");
     
     // Deuxième ligne (CARD)
     for (int j = debut; j <= fin; j++) {
         for (int i = indice_carte_debut; i <= indice_carte_fin; i++) {
             const char* couleur = obtenir_couleur(joueurs[j][i]);
             printf("%s│ CARD │%s ", couleur, RESET);
         }
         printf("   ");
     }
     printf("\n");
     
     // Troisième ligne (numéro de la carte)
     for (int j = debut; j <= fin; j++) {
         for (int i = indice_carte_debut; i <= indice_carte_fin; i++) {
             const char* couleur = obtenir_couleur(joueurs[j][i]);
             if (joueurs[j][i] == EMPTY_CARD) {
                 printf("%s│~~~~~~│%s ", couleur, RESET);
             } else if (joueurs[j][i] < 0 || joueurs[j][i] > 9) {
                 printf("%s│  %d  │%s ", couleur, joueurs[j][i], RESET);
             } else {
                 printf("%s│   %d  │%s ", couleur, joueurs[j][i], RESET);
             }
         }
         printf("   ");
     }
     printf("\n");
     
     // Quatrième ligne (YARD)
     for (int j = debut; j <= fin; j++) {
         for (int i = indice_carte_debut; i <= indice_carte_fin; i++) {
             const char* couleur = obtenir_couleur(joueurs[j][i]);
             printf("%s│ YARD │%s ", couleur, RESET);
         }
         printf("   ");
     }
     printf("\n");
     
     // Cinquième ligne (bordure inférieure)
     for (int j = debut; j <= fin; j++) {
         for (int i = indice_carte_debut; i <= indice_carte_fin; i++) {
             const char* couleur = obtenir_couleur(joueurs[j][i]);
             printf("%s└──────┘%s ", couleur, RESET);
         }
         printf("   ");
     }
     printf("\n");
 }
 
 void afficher_defausses(int defausses[], int debut, int fin) {
     // Bordure supérieure
     for (int j = debut; j <= fin; j++) {
         const char* couleur = obtenir_couleur(defausses[j]);
         printf("         %s┌──────┐%s             ", couleur, RESET);
     }
     printf("\n");
     
     // Ligne DEFAUSSE
     for (int j = debut; j <= fin; j++) {
         const char* couleur = obtenir_couleur(defausses[j]);
         printf("         %s│DEFAU.│%s             ", couleur, RESET);
     }
     printf("\n");
     
     // Valeur de la carte
     for (int j = debut; j <= fin; j++) {
         const char* couleur = obtenir_couleur(defausses[j]);
         if (defausses[j] == EMPTY_CARD) {
             printf("         %s│~~~~~~│%s             ", couleur, RESET);
         } else if (defausses[j] < 0 || defausses[j] > 9) {
             printf("         %s│  %d  │%s             ", couleur, defausses[j], RESET);
         } else {
             printf("         %s│   %d  │%s             ", couleur, defausses[j], RESET);
         }
     }
     printf("\n");
     
     // Ligne JOUEUR
     for (int j = debut; j <= fin; j++) {
         const char* couleur = obtenir_couleur(defausses[j]);
         printf("         %s│      │%s             ", couleur, RESET);
     }
     printf("\n");
     
     // Bordure inférieure
     for (int j = debut; j <= fin; j++) {
         const char* couleur = obtenir_couleur(defausses[j]);
         printf("         %s└──────┘%s             ", couleur, RESET);
     }
     printf("\n");
 }
 
 void afficher_numeros_joueurs(int debut, int fin, GameState *game) {
     for (int j = debut; j <= fin; j++) {
         printf("        ~%s~            ", game->playerNames[j]);
     }
     printf("\n\n");
 }
 
 void afficher_pioche(int currentCard) {
     const char* couleur = obtenir_couleur(currentCard);
     
     printf("\n        %s┌──────┐%s\n", couleur, RESET);
     printf("        %s│ CARD │%s\n", couleur, RESET);
     
     if (currentCard == EMPTY_CARD) {
         printf("        %s│~~~~~~│%s\n", couleur, RESET);
     } else if (currentCard < 0 || currentCard > 9) {
         printf("        %s│  %d  │%s\n", couleur, currentCard, RESET);
     } else {
         printf("        %s│   %d  │%s\n", couleur, currentCard, RESET);
     }
     printf("        %s│ YARD │%s\n", couleur, RESET);
     printf("        %s└──────┘%s\n", couleur, RESET);
     printf("         PIOCHE\n\n");
 }
 
 void afficher_jeu(GameState *game) {
     // Vérification que le nombre de joueurs est valide
     if (game->numPlayers < MIN_PLAYERS || game->numPlayers > MAX_PLAYERS) {
         printf("Erreur: Le nombre de joueurs doit être entre %d et %d.\n", MIN_PLAYERS, MAX_PLAYERS);
         return;
     }
     
     // Pour chaque groupe de joueurs
     for (int groupe = 0; groupe < game->numPlayers; groupe += 4) {
         int debut = groupe;
         int fin = (groupe + 3 < game->numPlayers) ? groupe + 3 : game->numPlayers - 1;
         
         // Affichage des cartes (premières moitié) des joueurs
         int milieu = game->cardsPerPlayer / 2;
         afficher_ligne_cartes(game->playerCards, debut, fin, 0, milieu - 1);
         
         // Affichage des cartes (seconde moitié) des joueurs
         afficher_ligne_cartes(game->playerCards, debut, fin, milieu, game->cardsPerPlayer - 1);
         
         // Affichage des défausses personnelles
         afficher_defausses(game->personalDiscards, debut, fin);
         
         // Numéros des joueurs
         afficher_numeros_joueurs(debut, fin, game);
     }
     
     // Afficher la pioche
     afficher_pioche(game->currentCentralCard);
 }
 
 void afficher_bienvenue() {
     printf("\n\n");
     printf("  ██████╗ █████╗ ██████╗ ██████╗     ██╗   ██╗ █████╗ ██████╗ ██████╗ \n");
     printf(" ██╔════╝██╔══██╗██╔══██╗██╔══██╗    ╚██╗ ██╔╝██╔══██╗██╔══██╗██╔══██╗\n");
     printf(" ██║     ███████║██████╔╝██║  ██║     ╚████╔╝ ███████║██████╔╝██║  ██║\n");
     printf(" ██║     ██╔══██║██╔══██╗██║  ██║      ╚██╔╝  ██╔══██║██╔══██╗██║  ██║\n");
     printf(" ╚██████╗██║  ██║██║  ██║██████╔╝       ██║   ██║  ██║██║  ██║██████╔╝\n");
     printf("  ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝        ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ \n");
     printf("\n\n");
     printf("Bienvenue dans le jeu Card Yard!\n\n");
     
     pauseWithMessage("Appuyez sur Entrée pour continuer...");
 }
 
void afficher_instructions() {
    nettoyer_ecran();
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║                     INSTRUCTIONS                           ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    printf("Card Yard est un jeu de cartes où le but est d'avoir le score le plus bas.\n\n");
    
    printf("RÈGLES DU JEU:\n");
    printf("-------------\n");
    printf("1. Chaque joueur commence avec un certain nombre de cartes face cachée.\n");
    printf("2. À chaque tour, un joueur peut:\n");
    printf("   a. Piocher une carte de la pioche centrale et l'échanger avec une de ses cartes\n");
    printf("   b. Prendre une carte d'une défausse et l'échanger avec une de ses cartes\n");
    printf("3. La carte remplacée est placée dans la défausse du joueur.\n");
    printf("4. Les cartes sont retournées lors des échanges.\n");
    printf("5. Le premier joueur à retourner toutes ses cartes termine la manche.\n");
    printf("6. Tous les autres joueurs jouent alors un dernier tour.\n");
    printf("7. Le score de chaque joueur est la somme des valeurs de ses cartes.\n");
    printf("8. Le joueur avec le score le plus bas gagne!\n\n");
    
    printf("COMMANDES:\n");
    printf("---------\n");
    printf("- Suivez les instructions à l'écran pour jouer.\n");
    printf("- Utilisez les touches numériques pour sélectionner vos actions.\n");
    printf("- Appuyez sur Entrée pour valider vos choix.\n\n");
    
    printf("ASTUCES:\n");
    printf("-------\n");
    printf("- Essayez de mémoriser les cartes que vous avez retournées.\n");
    printf("- Observez les défausses des autres joueurs pour anticiper leurs mouvements.\n");
    printf("- Échangez stratégiquement vos cartes pour minimiser votre score.\n\n");
    
    pauseWithMessage("Appuyez sur Entrée pour revenir au menu principal...");
}

void afficher_erreur(const char *message) {
    printf("%sErreur: %s%s\n", ROUGE, message, RESET);
}

void afficher_info(const char *message) {
    printf("%sInfo: %s%s\n", BLEU, message, RESET);
}

void nettoyer_ecran() {
    system("clear || cls"); // Clear screen for Unix/Linux or Windows
}

void afficher_tour_joueur(GameState *game) {
    printf("C'est le tour de %s!\n", game->playerNames[game->currentPlayerIndex]);
    printf("Sélectionnez une action:\n");
    printf("1. Piocher une carte de la pioche centrale\n");
    printf("2. Prendre une carte d'une défausse personnelle\n");
    printf("3. Échanger une carte avec un autre joueur\n");
    printf("4. Terminer le tour\n");
}


void afficher_resultats(GameState *game, int sortedIndices[], int scores[]) {
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║                RÉSULTATS                    ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");
    
    for (int i = 0; i < game->numPlayers; i++) {
        printf("%s: %d points\n", game->playerNames[sortedIndices[i]], scores[sortedIndices[i]]);
    }
    
    printf("\nLe gagnant est %s avec %d points!\n", game->playerNames[sortedIndices[0]], scores[sortedIndices[0]]);
}
    
    printf("\nLe gagnant est %s avec %d points!\n", game->playerNames[sortedIndices[0]], scores[sortedIndices[0]]);
}
