 #ifndef PLAYER_H
 #define PLAYER_H
 
 #include "game.h"
 
 bool initializePlayers(GameState *game);
 
 bool playerTurn(GameState *game);
 
 void sortPlayersByScore(GameState *game, int sortedIndices[], int scores[]);
 
 void displayPlayerScores(GameState *game, int sortedIndices[], int scores[]);

 int askPlayerForCardExchange(GameState *game, int drawnCard);
 
 int askPlayerForDrawChoice(GameState *game);
 
 #endif 
