#ifndef CARD_H
#define CARD_H

#include "game.h"

// Maximum de cartes dans le jeu
#define MAX_CARDS 150

bool proposer_de_changer_les_valeurs();
void initializeDefaultCardDeck(int cards[], int *size);
bool changeCardValuesToFile(const char *filename);
bool initializeCardDeckFromFile(int cards[], int *size, const char *filename);
bool initializeCardDeckFromUserInput(int cards[], int *size);
void shuffleDeck(int cards[], int size);
void dealCards(GameState *game);
bool allCardsVisible(GameState *game, int playerIndex);
int initializeCardsPerPlayer(GameState *game);


#endif // CARD_H