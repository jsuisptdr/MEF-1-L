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

const char* obtenir_couleur(int valeur);
void afficher_ligne_cartes(int joueurs[][MAX_CARDS_PER_PLAYER], int debut, int fin, int indice_carte_debut, int indice_carte_fin);
void afficher_defausses(int defausses[], int debut, int fin);
void afficher_numeros_joueurs(int debut, int fin, GameState *game);
void afficher_pioche(int currentCard);
void afficher_jeu(GameState *game);
void afficher_bienvenue();
void afficher_instructions();
void afficher_erreur(const char *message);
void afficher_info(const char *message);
void nettoyer_ecran();
void afficher_tour_joueur(GameState *game);
void afficher_resultats(GameState *game, int sortedIndices[], int scores[]);

#endif // DISPLAY_H