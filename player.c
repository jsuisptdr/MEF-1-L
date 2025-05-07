 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 #include "player.h"
 #include "game.h"
 #include "card.h"
 #include "display.h"
 #include "utils.h"
 
 bool initializePlayers(GameState *game) {
     printf("Entrée des noms des joueurs\n");
     printf("==========================\n");
     
     for (int i = 0; i < game->numPlayers; i++) {
         char prompt[100];
         snprintf(prompt, sizeof(prompt), "Nom du joueur %d: ", i + 1);
         
         if (readString(game->playerNames[i], 50, prompt) == NULL) {
             afficher_erreur("Erreur lors de la lecture du nom du joueur.");
             return false;
         }
         
         // Si le nom est vide, utiliser un nom par défaut
         if (strlen(game->playerNames[i]) == 0) {
             snprintf(game->playerNames[i], 50, "Joueur %d", i + 1);
         }
     }
     
     return true;
 }
 
 bool playerTurn(GameState *game) {
     // Demander au joueur s'il veut piocher du deck central ou d'une défausse
     int drawChoice = askPlayerForDrawChoice(game);
     
     int drawnCard;
     
     if (drawChoice == -1) {
         // Piocher du deck central
         drawnCard = game->currentCentralCard;
         game->currentCentralCard = drawFromCentralDeck(game);
     } else {
         // Piocher d'une défausse
         drawnCard = drawFromPersonalDiscard(game, drawChoice);
         if (drawnCard == EMPTY_CARD) {
             afficher_erreur("Cette défausse est vide. Piochage impossible.");
             pauseWithMessage("Appuyez sur Entrée pour réessayer...");
             return false;
         }
     }
     
     // Afficher la carte piochée
     printf("Vous avez pioché la carte: ");
     const char* color = obtenir_couleur(drawnCard);
     printf("%s%d%s\n", color, drawnCard, RESET);
     
     // Demander au joueur ce qu'il veut faire avec la carte
     int cardChoice = askPlayerForCardExchange(game, drawnCard);
     
     if (cardChoice == -1) {
         // Mettre la carte dans la défausse
         placeInPersonalDiscard(game, game->currentPlayerIndex, drawnCard);
     } else {
         // Échanger avec une carte du joueur
         int replacedCard = exchangePlayerCard(game, cardChoice, drawnCard);
         
         // Mettre la carte remplacée dans la défausse
         placeInPersonalDiscard(game, game->currentPlayerIndex, replacedCard);
     }
     
     return true;
 }
 
 void sortPlayersByScore(GameState *game, int sortedIndices[], int scores[]) {
     // Initialiser les indices
     for (int i = 0; i < game->numPlayers; i++) {
         sortedIndices[i] = i;
     }
     
     // Trier les indices par score (tri à bulles)
     for (int i = 0; i < game->numPlayers - 1; i++) {
         for (int j = 0; j < game->numPlayers - i - 1; j++) {
             if (scores[sortedIndices[j]] > scores[sortedIndices[j + 1]]) {
                 // Échanger les indices
                 int temp = sortedIndices[j];
                 sortedIndices[j] = sortedIndices[j + 1];
                 sortedIndices[j + 1] = temp;
             }
         }
     }
 }
 
 void displayPlayerScores(GameState *game, int sortedIndices[], int scores[]) {
     printf("\nRésultats:\n");
     printf("==========\n\n");
     
     for (int i = 0; i < game->numPlayers; i++) {
         int playerIndex = sortedIndices[i];
         printf("%d. %s: %d points\n", i + 1, game->playerNames[playerIndex], scores[playerIndex]);
     }
     
     printf("\nGagnant: %s!\n", game->playerNames[sortedIndices[0]]);
 }
 
 int askPlayerForCardExchange(GameState *game, int drawnCard) {
     printf("\nOptions:\n");
     printf("0. Mettre la carte dans ma défausse\n");
     
     for (int i = 0; i < game->cardsPerPlayer; i++) {
         printf("%d. Échanger avec la carte %d", i + 1, i + 1);
         
         if (game->playerCards[game->currentPlayerIndex][i] == EMPTY_CARD) {
             printf(" (face cachée)\n");
         } else {
             const char* color = obtenir_couleur(game->playerCards[game->currentPlayerIndex][i]);
             printf(" (%s%d%s)\n", color, game->playerCards[game->currentPlayerIndex][i], RESET);
         }
     }
     
     int choice = readInt(0, game->cardsPerPlayer, "Votre choix: ", "Choix invalide.");
     
     return choice - 1; // -1 pour la défausse, 0..cardsPerPlayer-1 pour les cartes du joueur
 }
 
 int askPlayerForDrawChoice(GameState *game) {
     printf("\nD'où voulez-vous piocher?\n");
     printf("0. Pioche centrale\n");
     
     // Afficher les défausses non vides
     int validDiscardCount = 0;
     for (int i = 0; i < game->numPlayers; i++) {
         if (game->personalDiscards[i] != EMPTY_CARD) {
             validDiscardCount++;
             const char* color = obtenir_couleur(game->personalDiscards[i]);
             printf("%d. Défausse de %s (%s%d%s)\n", 
                    validDiscardCount, 
                    game->playerNames[i], 
                    color, 
                    game->personalDiscards[i], 
                    RESET);
         }
     }
     
     int maxChoice = validDiscardCount;
     
     if (validDiscardCount == 0) {
         printf("Aucune défausse n'est disponible. Vous devez piocher du deck central.\n");
         pauseWithMessage("Appuyez sur Entrée pour continuer...");
         return -1;
     }
     
     int choice = readInt(0, maxChoice, "Votre choix: ", "Choix invalide.");
     
     if (choice == 0) {
         return -1; // Pioche centrale
     } else {
         // Trouver l'index de la défausse correspondante
         int discardIndex = -1;
         int count = 0;
         
         for (int i = 0; i < game->numPlayers; i++) {
             if (game->personalDiscards[i] != EMPTY_CARD) {
                 count++;
                 if (count == choice) {
                     discardIndex = i;
                     break;
                 }
             }
         }
         
         return discardIndex;
     }
 }
