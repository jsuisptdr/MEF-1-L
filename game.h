 #ifndef GAME_H
 #define GAME_H
 
 #include <stdbool.h>
 
 typedef enum {    
     VALUE_FILE               
 } CardValueMode;
 
 typedef enum {
     CARD_RAND         
 } CardNumberMode;
 

 typedef struct {
     int numPlayers;                                  
     int currentPlayerIndex;                           
     int playerCards[MAX_PLAYERS][MAX_CARDS_PER_PLAYER]; 
     int personalDiscards[MAX_PLAYERS];                
     int centralDeck[52];                              
     int centralDeckSize;                             
     int currentCentralCard;                           
     int cardsPerPlayer;                               
     int visibleCards[MAX_PLAYERS];                    
     char playerNames[MAX_PLAYERS][50];               
     bool gameOver;                                    
     bool lastRound;                                  
     int winnerIndex;                                  
     CardValueMode valueMode;                          
     CardNumberMode cardNumberMode;                    
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
 
 #endif 
