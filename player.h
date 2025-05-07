/**
 * @file player.h
 * @brief Définitions des fonctions liées aux joueurs
 */

 #ifndef PLAYER_H
 #define PLAYER_H
 
 #include "game.h"
 
 /**
  * @brief Initialise les joueurs avec leurs noms
  * @param game Pointeur vers la structure du jeu
  * @return true si l'initialisation a réussi, false sinon
  */
 bool initializePlayers(GameState *game);
 
 /**
  * @brief Demande au joueur actuel de jouer son tour
  * @param game Pointeur vers la structure du jeu
  * @return true si l'action a été effectuée, false sinon
  */
 bool playerTurn(GameState *game);
 
 /**
  * @brief Trie les joueurs par score
  * @param game Pointeur vers la structure du jeu
  * @param sortedIndices Tableau pour stocker les indices des joueurs triés
  * @param scores Tableau des scores des joueurs
  */
 void sortPlayersByScore(GameState *game, int sortedIndices[], int scores[]);
 
 /**
  * @brief Affiche les noms et scores des joueurs triés
  * @param game Pointeur vers la structure du jeu
  * @param sortedIndices Tableau contenant les indices des joueurs triés
  * @param scores Tableau des scores des joueurs
  */
 void displayPlayerScores(GameState *game, int sortedIndices[], int scores[]);
 
 /**
  * @brief Demande au joueur quelle carte échanger
  * @param game Pointeur vers la structure du jeu
  * @param drawnCard La carte piochée
  * @return L'index de la carte à échanger, ou -1 pour mettre la carte en défausse
  */
 int askPlayerForCardExchange(GameState *game, int drawnCard);
 
 /**
  * @brief Demande au joueur de choisir entre piocher du deck central ou d'une défausse
  * @param game Pointeur vers la structure du jeu
  * @return L'index de la défausse (-1 pour le deck central, 0..numPlayers-1 pour les défausses)
  */
 int askPlayerForDrawChoice(GameState *game);
 
 #endif // PLAYER_H
