#ifndef SAVE_H
#define SAVE_H

#include "game.h"

bool saveGame(GameState *game, const char *filename);
bool loadGame(GameState *game, const char *filename);
char* listSavedGames();

#endif // SAVE_H
