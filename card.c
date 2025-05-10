/**
 * @file card.c
 * @brief Implémentation des fonctions liées aux cartes
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 
 #include "card.h"
 #include "game.h"
 #include "display.h"
 #include "utils.h"
 
 void initializeDefaultCardDeck(int cards[], int *size) {
     // Cartes par défaut
     int defaultCards[] = {
         -2, -2, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 
         4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 
         9, 9, 9, 9, 10, 10, 11, 11, 12, 12
     };
     
     int defaultSize = sizeof(defaultCards) / sizeof(defaultCards[0]);
     *size = defaultSize;
     
     // Copier les cartes dans le tableau fourni
     for (int i = 0; i < defaultSize; i++) {
         cards[i] = defaultCards[i];
     }
 }
 
 bool initializeCardDeckFromFile(int cards[], int *size) {
     FILE *file = fopen(value.txt, "r");
     if (file == NULL) {
         return false;
     }
     
     int value, count;
     int index = 0;
     
     // Format du fichier: valeur quantité (ex: 5 4 pour quatre cartes de valeur 5)
     while (fscanf(file, "%d %d", &value, &count) == 2) {
         for (int i = 0; i < count; i++) {
             if (index >= MAX_CARDS) {
                 fclose(file);
                 return false;
             }
             cards[index++] = value;
         }
     }
     
     *size = index;
     fclose(file);
     return true;
 }
 
 bool initializeCardDeckFromUserInput(int cards[], int *size) {
     printf("Configuration des valeurs des cartes\n");
     printf("===================================\n");
     printf("Vous pouvez définir les valeurs entre -5 et 15\n\n");
     
     int minValue = readInt(-5, 15, "Valeur minimale: ", "Valeur invalide. Entrez un nombre entre -5 et 15.");
     int maxValue = readInt(minValue, 15, "Valeur maximale: ", "Valeur invalide. Entrez un nombre supérieur ou égal à la valeur minimale.");
     
     int index = 0;
     
     for (int value = minValue; value <= maxValue; value++) {
         char prompt[100];
         snprintf(prompt, sizeof(prompt), "Nombre de cartes pour la valeur %d (0-10): ", value);
         
         int count = readInt(0, 10, prompt, "Nombre invalide. Entrez un nombre entre 0 et 10.");
         
         for (int i = 0; i < count; i++) {
             if (index >= MAX_CARDS) {
                 afficher_erreur("Trop de cartes. Impossible de toutes les stocker.");
                 return false;
             }
             cards[index++] = value;
         }
     }
     
     if (index < 20) {
         afficher_erreur("Pas assez de cartes. Il faut au moins 20 cartes pour jouer.");
         return false;
     }
     
     *size = index;
     return true;
 }
 
 void shuffleDeck(int cards[], int size) {
     for (int i = size - 1; i > 0; i--) {
         int j = getRandomNumber(0, i);
         // Échanger cards[i] et cards[j]
         int temp = cards[i];
         cards[i] = cards[j];
         cards[j] = temp;
     }
 }
 
 void dealCards(GameState *game) {
     for (int i = 0; i < game->numPlayers; i++) {
         for (int j = 0; j < game->cardsPerPlayer; j++) {
             if (game->centralDeckSize > 0) {
                 game->playerCards[i][j] = EMPTY_CARD; // Face cachée
             }
         }
         game->visibleCards[i] = 0;
         game->personalDiscards[i] = EMPTY_CARD;
     }
 }
 
 bool allCardsVisible(GameState *game, int playerIndex) {
     return game->visibleCards[playerIndex] == game->cardsPerPlayer;
 }
 
 int initializeCardsPerPlayer(GameState *game) {
     switch (game->cardNumberMode) {
         case CARD_DEFAULT:
             return DEFAULT_CARDS;
             
         case CARD_USER:
             {
                 int minCards = 3; // Minimum raisonnable
                 int maxCards = MAX_CARDS_PER_PLAYER;
                 
                 return readInt(minCards, maxCards, 
                               "Entrez le nombre de cartes par joueur (3-12): ", 
                               "Nombre de cartes invalide. Entrez un nombre entre 3 et 12.");
             }
             
         case CARD_RAND:
             {
                 int minCards = 3;
                 int maxCards = 8;
                 
                 int cards = getRandomNumber(minCards, maxCards);
                 printf("Nombre de cartes par joueur (aléatoire): %d\n", cards);
                 pauseWithMessage("Appuyez sur Entrée pour continuer...");
                 return cards;
             }
             
         default:
             return DEFAULT_CARDS;
     }
 }
