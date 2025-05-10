/**
 * @file card.h
 * @brief Définitions des fonctions liées aux cartes
 */

 #ifndef CARD_H
 #define CARD_H
 
 #include "game.h"
 
 // Maximum de cartes dans le jeu
 #define MAX_CARDS 104
 
 /**
  * @brief Initialise le jeu de cartes avec les valeurs par défaut
  * @param cards Tableau pour stocker les cartes
  * @param size Pointeur pour stocker la taille du jeu de cartes
  */
 void initializeDefaultCardDeck(int cards[], int *size);
 
 /**
  * @brief Initialise le jeu de cartes depuis un fichier
  * @param cards Tableau pour stocker les cartes
  * @param size Pointeur pour stocker la taille du jeu de cartes
  * @param filename Nom du fichier contenant les valeurs des cartes
  * @return true si l'initialisation a réussi, false sinon
  */
 bool initializeCardDeckFromFile(int cards[], int *size, const char *filename);
 
 /**
  * @brief Initialise le jeu de cartes à partir des entrées de l'utilisateur
  * @param cards Tableau pour stocker les cartes
  * @param size Pointeur pour stocker la taille du jeu de cartes
  * @return true si l'initialisation a réussi, false sinon
  */
 bool initializeCardDeckFromUserInput(int cards[], int *size);
 
 /**
  * @brief Mélange le jeu de cartes
  * @param cards Tableau de cartes
  * @param size Taille du tableau
  */
 void shuffleDeck(int cards[], int size);
 
 /**
  * @brief Distribue les cartes aux joueurs
  * @param game Pointeur vers la structure du jeu
  */
 void dealCards(GameState *game);
 
 /**
  * @brief Vérifie si toutes les cartes d'un joueur sont visibles
  * @param game Pointeur vers la structure du jeu
  * @param playerIndex Index du joueur
  * @return true si toutes les cartes sont visibles, false sinon
  */
 bool allCardsVisible(GameState *game, int playerIndex);
 
 /**
  * @brief Initialise le nombre de cartes par joueur selon le mode choisi
  * @param game Pointeur vers la structure du jeu
  * @return Le nombre de cartes par joueur
  */
 int initializeCardsPerPlayer(GameState *game);
 
 #endif // CARD_H
