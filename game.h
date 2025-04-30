/**
 * @file game.h
 * @brief Définitions des structures et fonctions principales du jeu Card Yard
 */

 #ifndef GAME_H
 #define GAME_H
 
 #include <stdbool.h>
 
 // Constantes du jeu
 #define MAX_PLAYERS 8        // Nombre maximum de joueurs
 #define MIN_PLAYERS 2        // Nombre minimum de joueurs
 #define DEFAULT_CARDS 6      // Nombre de cartes par défaut par joueur
 #define MAX_CARDS_PER_PLAYER 12  // Nombre maximum de cartes par joueur
 #define EMPTY_CARD 99        // Valeur représentant une carte vide ou face cachée
 
 // Variantes du jeu
 typedef enum {
     VALUE_DEFAULT,    // Valeurs par défaut
     VALUE_FILE,       // Valeurs définies dans un fichier
     VALUE_USER        // Valeurs définies par l'utilisateur
 } CardValueMode;
 
 typedef enum {
     CARD_DEFAULT,     // Nombre de cartes par défaut
     CARD_USER,        // Nombre de cartes défini par l'utilisateur
     CARD_RAND         // Nombre de cartes aléatoire
 } CardNumberMode;
 
 // Structure représentant l'état du jeu
 typedef struct {
     int numPlayers;                                   // Nombre de joueurs
     int currentPlayerIndex;                           // Index du joueur actuel
     int playerCards[MAX_PLAYERS][MAX_CARDS_PER_PLAYER]; // Cartes de chaque joueur
     int personalDiscards[MAX_PLAYERS];                // Défausses personnelles
     int centralDeck[52];                              // Pioche centrale
     int centralDeckSize;                              // Taille actuelle de la pioche centrale
     int currentCentralCard;                           // Carte actuelle de la pioche centrale
     int cardsPerPlayer;                               // Nombre de cartes par joueur
     int visibleCards[MAX_PLAYERS];                    // Nombre de cartes visibles par joueur
     char playerNames[MAX_PLAYERS][50];               // Noms des joueurs
     bool gameOver;                                    // Indique si le jeu est terminé
     bool lastRound;                                   // Indique si c'est le dernier tour
     int winnerIndex;                                  // Index du joueur gagnant
     CardValueMode valueMode;                          // Mode de valeur des cartes
     CardNumberMode cardNumberMode;                    // Mode de nombre de cartes
 } GameState;
 
 /**
  * @brief Initialise un nouveau jeu
  * @param game Pointeur vers la structure du jeu
  * @param numPlayers Nombre de joueurs
  * @param valueMode Mode de valeur des cartes
  * @param cardNumberMode Mode de nombre de cartes
  * @return true si l'initialisation a réussi, false sinon
  */
 bool initializeGame(GameState *game, int numPlayers, CardValueMode valueMode, CardNumberMode cardNumberMode);
 
 /**
  * @brief Commence une nouvelle partie
  * @param game Pointeur vers la structure du jeu
  * @return true si le début de la partie a réussi, false sinon
  */
 bool startGame(GameState *game);
 
 /**
  * @brief Termine le tour du joueur actuel et passe au joueur suivant
  * @param game Pointeur vers la structure du jeu
  */
 void nextPlayer(GameState *game);
 
 /**
  * @brief Effectue un tour de jeu pour le joueur actuel
  * @param game Pointeur vers la structure du jeu
  * @return true si l'action a été effectuée, false sinon
  */
 bool playTurn(GameState *game);
 
 /**
  * @brief Pioche une carte depuis la pioche centrale
  * @param game Pointeur vers la structure du jeu
  * @return La valeur de la carte piochée
  */
 int drawFromCentralDeck(GameState *game);
 
 /**
  * @brief Pioche une carte d'une défausse personnelle
  * @param game Pointeur vers la structure du jeu
  * @param discardIndex Index de la défausse
  * @return La valeur de la carte piochée, ou EMPTY_CARD si la défausse est vide
  */
 int drawFromPersonalDiscard(GameState *game, int discardIndex);
 
 /**
  * @brief Échange une carte piochée avec une carte du joueur
  * @param game Pointeur vers la structure du jeu
  * @param playerCardIndex Index de la carte du joueur
  * @param newCard Nouvelle carte à placer chez le joueur
  * @return La carte remplacée
  */
 int exchangePlayerCard(GameState *game, int playerCardIndex, int newCard);
 
 /**
  * @brief Place une carte dans la défausse personnelle d'un joueur
  * @param game Pointeur vers la structure du jeu
  * @param playerIndex Index du joueur
  * @param card Carte à placer dans la défausse
  */
 void placeInPersonalDiscard(GameState *game, int playerIndex, int card);
 
 /**
  * @brief Vérifie si la partie est terminée
  * @param game Pointeur vers la structure du jeu
  * @return true si la partie est terminée, false sinon
  */
 bool isGameOver(GameState *game);
 
 /**
  * @brief Calcule les scores de tous les joueurs
  * @param game Pointeur vers la structure du jeu
  * @param scores Tableau pour stocker les scores (doit être de taille numPlayers)
  */
 void calculateScores(GameState *game, int scores[]);
 
 /**
  * @brief Termine le jeu et affiche les résultats
  * @param game Pointeur vers la structure du jeu
  */
 void endGame(GameState *game);
 
 /**
  * @brief Affiche le menu principal du jeu
  * @return L'option sélectionnée
  */
 int displayMainMenu();
 
 /**
  * @brief Affiche le menu de configuration de la partie
  * @param game Pointeur vers la structure du jeu
  * @return true si la configuration a réussi, false sinon
  */
 bool displayGameSetupMenu(GameState *game);
 
 #endif // GAME_H