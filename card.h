 #ifndef CARD_H
 #define CARD_H
 
 #include "game.h"
 
 
 #define MAX_CARDS 104
 
 void initializeDefaultCardDeck(int cards[], int *size);
 
 bool initializeCardDeckFromFile(int cards[], int *size, const char *filename);
 
 bool initializeCardDeckFromUserInput(int cards[], int *size);
 
 void shuffleDeck(int cards[], int size);
 
 void dealCards(GameState *game);
 
 bool allCardsVisible(GameState *game, int playerIndex);
 
 int initializeCardsPerPlayer(GameState *game);
 
 #endif
