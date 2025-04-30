#include <stdio.h>

#define LIGNES 3
#define COLONNES 4
#define NB_JOUEURS 
#define NB_CARTES 150

typedef struct {
    int valeur;     
    int visible;   
} Carte;

typedef struct {
    Carte grille[LIGNES][COLONNES];  
    int score_total;                 
} Joueur;

typedef struct {
    Carte cartes[NB_CARTES];
    int sommet; 
} Pioche;


typedef struct {
    Carte cartes[NB_CARTES];
    int sommet;
} Defausse;
     
     


