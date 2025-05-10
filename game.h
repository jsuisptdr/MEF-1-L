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


bool initializeGame(GameState *game, int numPlayers, CardValueMode valueMode, CardNumberMode cardNumberMode);
bool startGame(GameState *game);
void nextPlayer(GameState *game);
bool playTurn(GameState *game);
int drawFromCentralDeck(GameState *game);
int drawFromPersonalDiscard(GameState *game, int discardIndex);
int exchangePlayerCard(GameState *game, int playerCardIndex, int newCard);
void placeInPersonalDiscard(GameState *game, int playerIndex, int card);
bool isGameOver(GameState *game);
void calculateScores(GameState *game, int scores[]);
void endGame(GameState *game);
int displayMainMenu();
bool displayGameSetupMenu(GameState *game);

#endif // GAME_H
