SKYJO/YARDCARD

3-5 fichiers 

1. main.c

2. game.c + game.h

3. pioche.c + pioche.h

4. player.c + player.H
 
5. save.c + save.h

6. card.c + card.h

7. utils.c + utils.h

8. display.c + display.c

9. makefile


- [x] Modéliser les données du jeu (AYA)
* Définir les structures :
    * Carte : valeur, état (visible/cachée)
    * Joueur : tableau de cartes (grille 3x4), score
    * Pioche et Défausse : piles de cartes

- [ ]  Initialiser le jeu (TENZIN)
* Créer la pioche complète (valeurs -2 à 12 avec les bonnes quantités)
* Mélanger les cartes 
* Distribuer 12 cartes par joueur (face cachée)
* Afficher 2 cartes par joueur
* Mettre une carte dans la défausse

- [ ] Boucle de jeu principale (GREG)
* Si personne n’a terminé, faire :
        * Afficher ses cartes visibles et masquées
        * Proposer de piocher dans la pioche ou la défausse
        * Choisir de remplacer une carte ou de défausser
        * Révéler une carte si carte défaussée

    * Vérifier si un joueur a toutes ses cartes visibles

- [ ]  Fin de manche (on verra)
* Calculer le score de chaque joueur
* Ajouter au score total
* Redémarrer une manche si personne n’a atteint 100

- [ ] Fin de partie 
* Afficher le joueur avec le plus petit score total

- [ ]  Fonctions utiles à coder
* melanger_pioche()
* distribuer_cartes()
* afficher_grille_joueur()
* piocher()
* jouer_tour(joueur)
* calculer_score(joueur)


Makefile : plusieurs fichier pour compiler sans avoir a tout réécrire 

Faire un make clean 
Et un make 
     
     


