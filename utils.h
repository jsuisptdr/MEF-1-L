#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

int readInt(int min, int max, const char *promptMessage, const char *errorMessage);
char* readString(char *buffer, int size, const char *promptMessage);
void pauseWithMessage(const char *message);
int getRandomNumber(int min, int max);
void initRandom();

#endif // UTILS_H