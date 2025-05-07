/**
 * @file save.h
 * @brief Définitions des fonctions de sauvegarde et chargement
 */

 #ifndef SAVE_H
 #define SAVE_H
 
 #include "game.h"
 
 /**
  * @brief Sauvegarde l'état du jeu dans un fichier
  * @param game Pointeur vers la structure du jeu
  * @param filename Nom du fichier
  * @return true si la sauvegarde a réussi, false sinon
  */
 bool saveGame(GameState *game, const char *filename);
 
 /**
  * @brief Charge l'état du jeu à partir d'un fichier
  * @param game Pointeur vers la structure du jeu
  * @param filename Nom du fichier
  * @return true si le chargement a réussi, false sinon
  */
 bool loadGame(GameState *game, const char *filename);
 
 /**
  * @brief Affiche la liste des sauvegardes disponibles
  * @return Le nom du fichier sélectionné, ou NULL si aucun fichier sélectionné
  */
 char* listSavedGames();
 
 #endif // SAVE_H
