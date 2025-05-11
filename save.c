#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#include "save.h"
#include "display.h"
#include "utils.h"

// Constantes pour la sauvegarde
#define SAVE_DIRECTORY "saves"
#define SAVE_EXTENSION ".sav"
#define MAX_PATH_LENGTH 256

// Crée le répertoire de sauvegarde s'il n'existe pas
static void ensureSaveDirectoryExists() {
    struct stat st = {0};
    
    if (stat(SAVE_DIRECTORY, &st) == -1) {
        #ifdef _WIN32
            mkdir(SAVE_DIRECTORY);
        #else
            mkdir(SAVE_DIRECTORY, 0700);
        #endif
    }
}

// Sauvegarde l'état du jeu dans un fichier
bool saveGame(GameState *game, const char *filename) {
    ensureSaveDirectoryExists();
    
    // Construire le chemin complet
    char fullPath[MAX_PATH_LENGTH];
    snprintf(fullPath, sizeof(fullPath), "%s/%s%s", SAVE_DIRECTORY, filename, SAVE_EXTENSION);
    
    // Ouvrir le fichier en mode binaire écriture
    FILE *file = fopen(fullPath, "wb");
    if (file == NULL) {
        afficher_erreur("Impossible d'ouvrir le fichier de sauvegarde.");
        return false;
    }
    
    // Écrire les données de base du jeu
    fwrite(&game->numPlayers, sizeof(int), 1, file);
    fwrite(&game->currentPlayerIndex, sizeof(int), 1, file);
    fwrite(&game->cardsPerPlayer, sizeof(int), 1, file);
    fwrite(&game->centralDeckSize, sizeof(int), 1, file);
    fwrite(&game->currentCentralCard, sizeof(int), 1, file);
    fwrite(&game->gameOver, sizeof(bool), 1, file);
    fwrite(&game->lastRound, sizeof(bool), 1, file);
    fwrite(&game->winnerIndex, sizeof(int), 1, file);
    fwrite(&game->valueMode, sizeof(CardValueMode), 1, file);
    fwrite(&game->cardNumberMode, sizeof(CardNumberMode), 1, file);
    
    // Écrire les cartes du jeu
    for (int i = 0; i < MAX_PLAYERS; i++) {
        fwrite(game->playerCards[i], sizeof(int), MAX_CARDS_PER_PLAYER, file);
    }
    
    // Écrire les défausses personnelles
    fwrite(game->personalDiscards, sizeof(int), MAX_PLAYERS, file);
    
    // Écrire la pioche centrale
    fwrite(game->centralDeck, sizeof(int), game->centralDeckSize, file);
    
    // Écrire le nombre de cartes visibles par joueur
    fwrite(game->visibleCards, sizeof(int), MAX_PLAYERS, file);
    
    // Écrire les noms des joueurs
    for (int i = 0; i < game->numPlayers; i++) {
        fwrite(game->playerNames[i], sizeof(char), 50, file);
    }
    
    fclose(file);
    return true;
}

// Charge l'état du jeu à partir d'un fichier
bool loadGame(GameState *game, const char *filename) {
    // Construire le chemin complet
    char fullPath[MAX_PATH_LENGTH];
    snprintf(fullPath, sizeof(fullPath), "%s/%s", SAVE_DIRECTORY, filename);
    
    // Ouvrir le fichier en mode binaire lecture
    FILE *file = fopen(fullPath, "rb");
    if (file == NULL) {
        afficher_erreur("Impossible d'ouvrir le fichier de sauvegarde.");
        return false;
    }
    
    // Lire les données de base du jeu
    fread(&game->numPlayers, sizeof(int), 1, file);
    fread(&game->currentPlayerIndex, sizeof(int), 1, file);
    fread(&game->cardsPerPlayer, sizeof(int), 1, file);
    fread(&game->centralDeckSize, sizeof(int), 1, file);
    fread(&game->currentCentralCard, sizeof(int), 1, file);
    fread(&game->gameOver, sizeof(bool), 1, file);
    fread(&game->lastRound, sizeof(bool), 1, file);
    fread(&game->winnerIndex, sizeof(int), 1, file);
    fread(&game->valueMode, sizeof(CardValueMode), 1, file);
    fread(&game->cardNumberMode, sizeof(CardNumberMode), 1, file);
    
    // Lire les cartes du jeu
    for (int i = 0; i < MAX_PLAYERS; i++) {
        fread(game->playerCards[i], sizeof(int), MAX_CARDS_PER_PLAYER, file);
    }
    
    // Lire les défausses personnelles
    fread(game->personalDiscards, sizeof(int), MAX_PLAYERS, file);
    
    // Lire la pioche centrale
    fread(game->centralDeck, sizeof(int), game->centralDeckSize, file);
    
    // Lire le nombre de cartes visibles par joueur
    fread(game->visibleCards, sizeof(int), MAX_PLAYERS, file);
    
    // Lire les noms des joueurs
    for (int i = 0; i < game->numPlayers; i++) {
        fread(game->playerNames[i], sizeof(char), 50, file);
    }
    
    fclose(file);
    return true;
}

// Affiche la liste des sauvegardes disponibles
char* listSavedGames() {
    ensureSaveDirectoryExists();
    
    DIR *dir;
    struct dirent *ent;
    int count = 0;
    char **files = NULL;
    
    // Ouvrir le répertoire
    if ((dir = opendir(SAVE_DIRECTORY)) != NULL) {
        // Compter le nombre de fichiers de sauvegarde
        while ((ent = readdir(dir)) != NULL) {
            if (strstr(ent->d_name, SAVE_EXTENSION) != NULL) {
                count++;
                files = realloc(files, count * sizeof(char*));
                files[count - 1] = strdup(ent->d_name);
            }
        }
        closedir(dir);
    } else {
        afficher_erreur("Impossible d'ouvrir le répertoire de sauvegarde.");
        return NULL;
    }
    
    if (count == 0) {
        afficher_info("Aucune sauvegarde trouvée.");
        return NULL;
    }
    
    // Afficher la liste des sauvegardes
    nettoyer_ecran();
    printf("\n\n");
    printf(B_JAUNE "===============================================\n" RESET);
    printf(B_JAUNE "=          SAUVEGARDES DISPONIBLES           =\n" RESET);
    printf(B_JAUNE "===============================================\n\n" RESET);
    
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, files[i]);
    }
    printf("\n0. Retour au menu principal\n\n");
    
    int choice = readInt(0, count, "Choisissez une sauvegarde à charger: ", 
                        "Choix invalide. Veuillez réessayer.");
    
    char *result = NULL;
    if (choice > 0) {
        result = strdup(files[choice - 1]);
    }
    
    // Libérer la mémoire
    for (int i = 0; i < count; i++) {
        free(files[i]);
    }
    free(files);
    
    return result;
}