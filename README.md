# MEF-1-L

#include <stdio.h>

int main(){

int nb_joueurs;
     printf("Bienvenue dans CardYard !\n");
     printf("Entrez le nombre de joueurs (2-8): ");
     scanf("%d", &nb_joueurs);
     
     Jeu jeu = creer_jeu(nb_joueurs);
     initialiser_pioche(&jeu)


