#ifndef DISPLAY_H
#define DISPLAY_H

#include "game.h"
#include "utils.h"

// Définition des codes de couleur ANSI
#define RESET       "\033[0m"
#define NOIR        "\033[30m"
#define B_NOIR     "\033[1;30m"
#define ROUGE       "\033[31m"
#define B_ROUGE     "\033[1;31m"
#define VERT        "\033[32m"
#define B_VERT      "\033[1;32m"
#define JAUNE       "\033[33m"
#define B_JAUNE     "\033[1;33m"
#define BLEU        "\033[34m"
#define B_BLEU      "\033[1;34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define BLANC       "\033[37m"
#define B_NOIR      "\033[1;30m"
#define B_ROUGE     "\033[1;31m"
#define B_VERT      "\033[1;32m"
#define B_JAUNE     "\033[1;33m"
#define B_BLEU      "\033[1;34m"
#define B_MAGENTA   "\033[1;35m"
#define B_CYAN      "\033[1;36m"
#define B_BLANC     "\033[1;37m"

const char* get_color(int colorValue);
void display_card_row(int joueurs[][MAX_CARDS_PER_PLAYER], int startIndex, int endIndex, int indice_carte_debut, int indice_carte_fin);
void display_faults(int defausses[], int startIndex, int endIndex);
void display_player_numbers(int startIndex, int endIndex, GameState *game);
void display_draw_pile(int currentCard);
void display_game(GameState *game);
void display_welcome_message();
void display_instructions();
void display_error(const char *message);
void display_message(const char *message);
void clear_screen();
void display_player_turn(GameState *game);
void display_game_results(GameState *game, int sortedIndices[], int scores[]);

#endif // DISPLAY_H
