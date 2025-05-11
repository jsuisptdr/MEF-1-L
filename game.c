#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "game.h"
#include "card.h"
#include "player.h"
#include "display.h"
#include "utils.h"
#include "save.h"

bool initializeGame(GameState *game, int numPlayers, CardValueMode valueMode, CardNumberMode cardNumberMode) {
if (numPlayers < MIN_PLAYERS || numPlayers > MAX_PLAYERS) {
afficher_erreur("Nombre de joueurs invalide.");
return false;
}

// Initialiser les variables du jeu
game->numPlayers = numPlayers;
game->currentPlayerIndex = 0;
game->gameOver = false;
game->lastRound = false;
game->winnerIndex = -1;
game->valueMode = valueMode;
game->cardNumberMode = cardNumberMode;

// Initialiser le nombre de cartes par joueur
game->cardsPerPlayer = initializeCardsPerPlayer(game); // se situe dans card.c

// Initialiser les joueurs (noms)
if (!initializePlayers(game)) {
return false;
}

// Initialiser le jeu de cartes
switch (valueMode) {
case VALUE_DEFAULT:
    initializeDefaultCardDeck(game->centralDeck, &game->centralDeckSize);
    break;
case VALUE_FILE:
    // proposer de changer les valeurs a l'interieur du fichier
    if (proposer_de_changer_les_valeurs()) {
        if (!changeCardValuesToFile("saves/VALUE_CARD.txt")) {
            afficher_erreur("Impossible de changer les valeurs des cartes dans le fichier.");
            return false;
        }
    }
    if (!initializeCardDeckFromFile(game->centralDeck, &game->centralDeckSize, "VALUE_CARD.txt")) {
        afficher_erreur("Impossible de charger les valeurs des cartes depuis le fichier.");
        return false;
    }
    break;
case VALUE_USER:
    if (!initializeCardDeckFromUserInput(game->centralDeck, &game->centralDeckSize)) {
        afficher_erreur("Échec de la configuration des valeurs des cartes.");
        return false;
    }
    break;
}

// Mélanger le jeu de cartes
shuffleDeck(game->centralDeck, game->centralDeckSize);
printf("Jeu de cartes mélangé avec succès!\n");
// Initialiser les cartes des joueurs (toutes face cachées)
for (int i = 0; i < game->numPlayers; i++) {
for (int j = 0; j < game->cardsPerPlayer; j++) {
    game->playerCards[i][j] = EMPTY_CARD;
}
game->visibleCards[i] = 0;
game->personalDiscards[i] = EMPTY_CARD;
}
printf("Cartes des joueurs initialisées avec succès!\n");
// Initialiser la carte actuelle de la pioche centrale
game->currentCentralCard = EMPTY_CARD;


// Distribuer les cartes aux joueurs
dealCards(game);

// Piocher la première carte pour la pioche centrale
game->currentCentralCard = drawFromCentralDeck(game);
if (game->currentCentralCard == EMPTY_CARD) {
afficher_erreur("Échec de la pioche de la carte centrale.");
return false;
}

return true;
}

bool startGame(GameState *game) {


// Boucle principale du jeu
while (!game->gameOver) {
// Afficher l'état du jeu
nettoyer_ecran();
afficher_jeu(game);

// Afficher le tour du joueur actuel
afficher_tour_joueur(game);

// Menu pour sauvegarder ou jouer
printf("\n1. Jouer\n");
printf("2. Sauvegarder et quitter\n");

int choice = readInt(1, 2, "Choisissez une option: ", "Option invalide. Choisissez 1 ou 2.");

if (choice == 2) {
    // Sauvegarder la partie
    char filename[100];
    readString(filename, sizeof(filename), "Entrez le nom du fichier de sauvegarde: ");
    if (saveGame(game, filename)) {
        afficher_info("Partie sauvegardée avec succès!");
        return true;
    } else {
        afficher_erreur("Erreur lors de la sauvegarde.");
        pauseWithMessage("Appuyez sur Entrée pour continuer...");
        continue;
    }
}

// Jouer le tour du joueur actuel
if (!playTurn(game)) {
    afficher_erreur("Erreur lors du tour du joueur.");
    pauseWithMessage("Appuyez sur Entrée pour continuer...");
    continue;
}

// Passer au joueur suivant
nextPlayer(game);

}

// La partie est terminée, calculer et afficher les scores
int scores[MAX_PLAYERS];
int sortedIndices[MAX_PLAYERS];

calculateScores(game, scores);
sortPlayersByScore(game, sortedIndices, scores);

printf("\n\n");
afficher_resultats(game, sortedIndices, scores);

pauseWithMessage("Appuyez sur Entrée pour revenir au menu principal...");
return true;
}

void nextPlayer(GameState *game) {
game->currentPlayerIndex = (game->currentPlayerIndex + 1) % game->numPlayers;

// Si nous sommes au dernier tour et que nous avons fait le tour des joueurs
if (game->lastRound && game->currentPlayerIndex == game->winnerIndex) {
game->gameOver = true;
}
}

bool playTurn(GameState *game) {
return playerTurn(game);
}

int drawFromCentralDeck(GameState *game) {
if (game->centralDeckSize <= 0) {
afficher_erreur("La pioche centrale est vide.");
return EMPTY_CARD;
}

int card = game->centralDeck[--game->centralDeckSize];
return card;
}

int drawFromPersonalDiscard(GameState *game, int discardIndex) {
if (discardIndex < 0 || discardIndex >= game->numPlayers) {
afficher_erreur("Index de défausse invalide.");
return EMPTY_CARD;
}

if (game->personalDiscards[discardIndex] == EMPTY_CARD) {
afficher_erreur("Cette défausse est vide.");
return EMPTY_CARD;
}

int card = game->personalDiscards[discardIndex];
game->personalDiscards[discardIndex] = EMPTY_CARD;
return card;
}

int exchangePlayerCard(GameState *game, int playerCardIndex, int newCard) {
int playerIndex = game->currentPlayerIndex;

if (playerCardIndex < 0 || playerCardIndex >= game->cardsPerPlayer) {
afficher_erreur("Index de carte invalide.");
return EMPTY_CARD;
}

int oldCard = game->playerCards[playerIndex][playerCardIndex];
game->playerCards[playerIndex][playerCardIndex] = newCard;

// Si la carte était face cachée et qu'elle est maintenant face visible
if (oldCard == EMPTY_CARD) {
game->visibleCards[playerIndex]++;

// Vérifier si toutes les cartes sont visibles
if (game->visibleCards[playerIndex] == game->cardsPerPlayer && !game->lastRound) {
    afficher_info("Toutes vos cartes sont visibles! C'est le dernier tour.");
    game->lastRound = true;
    game->winnerIndex = playerIndex;
}
}

return oldCard;
}

void placeInPersonalDiscard(GameState *game, int playerIndex, int card) {
if (playerIndex < 0 || playerIndex >= game->numPlayers) {
afficher_erreur("Index de joueur invalide.");
return;
}

game->personalDiscards[playerIndex] = card;
}

bool isGameOver(GameState *game) {
// La partie est terminée si nous sommes au dernier tour et que nous avons fait le tour des joueurs
return game->lastRound && game->currentPlayerIndex == game->winnerIndex;
}

void calculateScores(GameState *game, int scores[]) {
for (int i = 0; i < game->numPlayers; i++) {
scores[i] = 0;
for (int j = 0; j < game->cardsPerPlayer; j++) {
if (game->playerCards[i][j] != EMPTY_CARD) {
    scores[i] += game->playerCards[i][j];
}
if (game->playerCards[i][j] == EMPTY_CARD) {
    // Pénalité pour les cartes non retournées: on pioche et ajoute la valeur
    int penaltyCard = drawFromCentralDeck(game);
    if (penaltyCard != EMPTY_CARD) {
        scores[i] += penaltyCard;
        char buffer[100];
        sprintf(buffer, "Pénalité pour joueur %d: +%d points", i+1, penaltyCard);
        afficher_info(buffer);
    } else {
        // Si la pioche est vide, ajouter une pénalité fixe
        scores[i] += 10;
        char buffer[100];
        sprintf(buffer, "Pénalité pour joueur %d: +10 points (pioche vide)", i+1);
        afficher_info(buffer);
    }
}
}
}
}

void endGame(GameState *game) {
int scores[MAX_PLAYERS];
int sortedIndices[MAX_PLAYERS];

calculateScores(game, scores);
sortPlayersByScore(game, sortedIndices, scores);

nettoyer_ecran();
afficher_resultats(game, sortedIndices, scores);
}

int displayMainMenu() {
//nettoyer_ecran();
printf("╔═════════════════════════════════╗\n");
printf("║           CARD YARD             ║\n");
printf("╠═════════════════════════════════╣\n");
printf("║ 1. Nouvelle partie              ║\n");
printf("║ 2. Charger une partie           ║\n");
printf("║ 3. Instructions                 ║\n");
printf("║ 4. Quitter                      ║\n");
printf("╚═════════════════════════════════╝\n");

return readInt(1, 4, "Choisissez une option: ", "Option invalide. Choisissez entre 1 et 4.");
}

bool displayGameSetupMenu(GameState *game) {
nettoyer_ecran();
printf("╔═════════════════════════════════╗\n");
printf("║     CONFIGURATION DU JEU        ║\n");
printf("╚═════════════════════════════════╝\n\n");

// Nombre de joueurs
game->numPlayers = readInt(MIN_PLAYERS, MAX_PLAYERS, 
                    "Entrez le nombre de joueurs (2-8): ", 
                    "Nombre de joueurs invalide. Entrez un nombre entre 2 et 8.");

// Mode de valeurs des cartes
printf("\nMode de valeurs des cartes:\n");
printf("1. Valeurs par défaut\n");
printf("2. Valeurs depuis un fichier\n");
printf("3. Valeurs personnalisées\n");

int valueChoice = readInt(1, 3, "Choisissez un mode: ", "Option invalide. Choisissez entre 1 et 3.");

switch (valueChoice) {
case 1: game->valueMode = VALUE_DEFAULT; break;
case 2: game->valueMode = VALUE_FILE; break;
case 3: game->valueMode = VALUE_USER; break;
}

// Mode de nombre de cartes
printf("\nMode de nombre de cartes par joueur:\n");
printf("1. Nombre de cartes par défaut (%d)\n", DEFAULT_CARDS);
printf("2. Nombre de cartes personnalisé\n");
printf("3. Nombre de cartes aléatoire\n");

int cardChoice = readInt(1, 3, "Choisissez un mode: ", "Option invalide. Choisissez entre 1 et 3.");

switch (cardChoice) {
case 1: game->cardNumberMode = CARD_DEFAULT; break;
case 2: game->cardNumberMode = CARD_USER; break;
case 3: game->cardNumberMode = CARD_RAND; break;
}

return true;
}
