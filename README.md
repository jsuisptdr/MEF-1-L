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

// TENZIN : INITIALISATION DU JEU 

void initialiser_pioche(Pioche *pioche) {
    int index = 0;

    // Exemple des vraies quantités dans Skyjo :
    // (valeur, quantité)
    int valeurs[] = {-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int quantites[] = {5, 10, 15, 15, 15, 15, 15, 15, 10, 10, 10, 10, 10, 10, 5};

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < quantites[i]; j++) {
            pioche->cartes[index].valeur = valeurs[i];
            pioche->cartes[index].visible = 0;
            index++;
        }
    }

    pioche->sommet = index - 1;
}

void melanger_pioche(Pioche *pioche) {
    for (int i = pioche->sommet; i > 0; i--) {
        int j = rand() % (i + 1);
        Carte temp = pioche->cartes[i];
        pioche->cartes[i] = pioche->cartes[j];
        pioche->cartes[j] = temp;
    }
}

void initialiser_defausse(Pioche *pioche, Defausse *defausse) {
    defausse->sommet = 0;
    defausse->cartes[0] = pioche->cartes[pioche->sommet];
    defausse->cartes[0].visible = 1;
    pioche->sommet--;
}



// GREG : BOUCLES 

// FIN DE JEU


int main() {
    srand(time(NULL));

    Pioche pioche;
    Defausse defausse;

    initialiser_pioche(&pioche);
    melanger_pioche(&pioche);
    initialiser_defausse(&pioche, &defausse);

    printf("Carte visible en haut de la défausse : %d\n", defausse.cartes[defausse.sommet].valeur);

    return 0;
}
     
     


