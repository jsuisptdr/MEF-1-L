/**
 * @file utils.h
 * @brief Définitions des fonctions utilitaires
 */

 #ifndef UTILS_H
 #define UTILS_H
 
 #include <stdbool.h>
 
 /**
  * @brief Lit un entier à partir de l'entrée standard avec validation
  * @param min Valeur minimale acceptée
  * @param max Valeur maximale acceptée
  * @param promptMessage Message d'invite
  * @param errorMessage Message d'erreur
  * @return L'entier lu
  */
 int readInt(int min, int max, const char *promptMessage, const char *errorMessage);
 
 /**
  * @brief Lit une chaîne de caractères à partir de l'entrée standard
  * @param buffer Buffer pour stocker la chaîne
  * @param size Taille du buffer
  * @param promptMessage Message d'invite
  * @return Pointeur vers la chaîne lue
  */
 char* readString(char *buffer, int size, const char *promptMessage);
 
 /**
  * @brief Met le programme en pause jusqu'à ce que l'utilisateur appuie sur Entrée
  * @param message Message à afficher
  */
 void pauseWithMessage(const char *message);
 
 /**
  * @brief Génère un nombre aléatoire entre min et max inclus
  * @param min Valeur minimale
  * @param max Valeur maximale
  * @return Le nombre aléatoire généré
  */
 int getRandomNumber(int min, int max);
 
 /**
  * @brief Initialise le générateur de nombres aléatoires
  */
 void initRandom();
 
 #endif // UTILS_H
