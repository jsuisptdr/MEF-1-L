/**
 * @file display.h
 * @brief Définitions des fonctions d'affichage du jeu
 */

 #ifndef DISPLAY_H
 #define DISPLAY_H
 
 #include "game.h"
 
 // Définition des codes de couleur ANSI
 #define RESET       "\033[0m"
 #define NOIR        "\033[30m"
 #define ROUGE       "\033[31m"
 #define VERT        "\033[32m"
 #define JAUNE       "\033[33m"
 #define BLEU        "\033[34m"
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
 
 /**
  * @brief Obtient la couleur appropriée selon la valeur de la carte
  * @param valeur Valeur de la carte
  * @return Code de couleur ANSI
  */
 const char* obtenir_couleur(int valeur);
 
 /**
  * @brief Affiche une ligne de cartes pour plusieurs joueurs
  * @param joueurs Cartes des joueurs
  * @param debut Index du premier joueur à afficher
  * @param fin Index du dernier joueur à afficher
  * @param indice_carte_debut Index de la première carte à afficher
  * @param indice_carte_fin Index de la dernière carte à afficher
  */
 void afficher_ligne_cartes(int joueurs[][MAX_CARDS_PER_PLAYER], int debut, int fin, int indice_carte_debut, int indice_carte_fin);
 
 /**
  * @brief Affiche les défausses personnelles
  * @param defausses Défausses des joueurs
  * @param debut Index du premier joueur à afficher
  * @param fin Index du dernier joueur à afficher
  */
 void afficher_defausses(int defausses[], int debut, int fin);
 
 /**
  * @brief Affiche les numéros des joueurs horizontalement
  * @param debut Index du premier joueur à afficher
  * @param fin Index du dernier joueur à afficher
  * @param game Etat du jeu pour afficher les noms des joueurs
  */
 void afficher_numeros_joueurs(int debut, int fin, GameState *game);
 
 /**
  * @brief Affiche la pioche
  * @param currentCard Carte actuelle de la pioche
  */
 void afficher_pioche(int currentCard);
 
 /**
  * @brief Affiche l'état complet du jeu
  * @param game Pointeur vers la structure de l'état du jeu
  */
 void afficher_jeu(GameState *game);
 
 /**
  * @brief Affiche le message d'accueil du jeu
  */
 void afficher_bienvenue();
 
 /**
  * @brief Affiche les instructions du jeu
  */
 void afficher_instructions();
 
 /**
  * @brief Affiche un message d'erreur
  * @param message Message d'erreur
  */
 void afficher_erreur(const char *message);
 
 /**
  * @brief Affiche un message d'information
  * @param message Message d'information
  */
 void afficher_info(const char *message);
 
 /**
  * @brief Nettoie l'écran du terminal
  */
 void nettoyer_ecran();
 
 /**
  * @brief Affiche le tour du joueur actuel
  * @param game Pointeur vers la structure du jeu
  */
 void afficher_tour_joueur(GameState *game);
 
 /**
  * @brief Affiche les résultats finaux du jeu
  * @param game Pointeur vers la structure du jeu
  * @param sortedIndices Indices des joueurs triés par score
  * @param scores Scores des joueurs
  */
 void afficher_resultats(GameState *game, int sortedIndices[], int scores[]);
 
 #endif // DISPLAY_H