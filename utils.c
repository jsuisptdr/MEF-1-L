/**
 * @file utils.c
 * @brief Implémentation des fonctions utilitaires
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 
 #include "utils.h"
 #include "display.h"
 
 // Lit un entier à partir de l'entrée standard avec validation
 int readInt(int min, int max, const char *promptMessage, const char *errorMessage) {
     int value;
     char buffer[100];
     char *endptr;
     
     while (1) {
         printf("%s", promptMessage);
         
         // Lire l'entrée comme une chaîne
         if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
             afficher_erreur("Erreur de lecture");
             continue;
         }
         
         // Supprimer le caractère de nouvelle ligne
         buffer[strcspn(buffer, "\n")] = '\0';
         
         // Convertir en entier
         value = (int)strtol(buffer, &endptr, 10);
         
         // Vérifier si la conversion a réussi et si la valeur est dans la plage
         if (*endptr != '\0') {
             afficher_erreur(errorMessage);
             continue;
         }
         
         if (value < min || value > max) {
             afficher_erreur(errorMessage);
             continue;
         }
         
         // Valeur valide
         return value;
     }
 }
 
 // Lit une chaîne de caractères à partir de l'entrée standard
 char* readString(char *buffer, int size, const char *promptMessage) {
     printf("%s", promptMessage);
     
     // Lire l'entrée comme une chaîne
     if (fgets(buffer, size, stdin) == NULL) {
         afficher_erreur("Erreur de lecture");
         buffer[0] = '\0';
         return buffer;
     }
     
     // Supprimer le caractère de nouvelle ligne
     buffer[strcspn(buffer, "\n")] = '\0';
     
     return buffer;
 }
 
 // Met le programme en pause jusqu'à ce que l'utilisateur appuie sur Entrée
 void pauseWithMessage(const char *message) {
     printf("%s", message);
     getchar();  // Consommer le caractère de nouvelle ligne
     
     // Si le buffer d'entrée n'est pas vide, vider le
     int c;
     while ((c = getchar()) != '\n' && c != EOF) { }
 }
 
 // Génère un nombre aléatoire entre min et max inclus
 int getRandomNumber(int min, int max) {
     return min + rand() % (max - min + 1);
 }
 
 // Initialise le générateur de nombres aléatoires
 void initRandom() {
     srand((unsigned int)time(NULL));
 }
