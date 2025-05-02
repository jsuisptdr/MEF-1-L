SKYJO/YARDCARD

 fichiers :

1. main.c

2. game.c + game.h

3. pioche.c + pioche.h

4. player.c + player.Hhh
 
5. save.c + save.h

6. card.c + card.h

7. utils.c + utils.h

8. display.c + display.c

9. makefile


# Card Yard

## Description
Card Yard est un jeu de cartes stratégique où l'objectif est d'obtenir le score le plus bas possible. Les joueurs échangent des cartes entre leur main, la pioche centrale et les défausses personnelles pour optimiser leur jeu.

## Règles du jeu

1. Chaque joueur commence avec un certain nombre de cartes face cachée.
2. À chaque tour, un joueur peut:
   - Piocher une carte de la pioche centrale et l'échanger avec une de ses cartes
   - Prendre une carte d'une défausse personnelle et l'échanger avec une de ses cartes
3. La carte remplacée est placée dans la défausse du joueur.
4. Les cartes sont retournées lors des échanges.
5. Le premier joueur à retourner toutes ses cartes termine la manche.
6. Tous les autres joueurs jouent alors un dernier tour.
7. Le score de chaque joueur est la somme des valeurs de ses cartes.
8. Le joueur avec le score le plus bas gagne!

## Caractéristiques

- Support pour 2 à 8 joueurs
- Interface en mode texte avec couleurs ANSI
- Configuration personnalisable:
  - Valeurs des cartes (par défaut, depuis un fichier ou personnalisées)
  - Nombre de cartes par joueur (par défaut, personnalisé ou aléatoire)
- Système de sauvegarde et chargement de parties

## Installation

### Prérequis
- Compilateur C (GCC recommandé)
- Make (optionnel mais recommandé)

### Compilation

#### Avec Make
```bash
make
```

#### Sans Make
```bash
gcc -o card_yard main.c game.c card.c player.c display.c utils.c save.c -std=c99
```

## Exécution
```bash
./card_yard
```

## Structure du projet

- `main.c` - Point d'entrée du programme
- `game.c/h` - Logique principale du jeu
- `card.c/h` - Gestion des cartes
- `player.c/h` - Gestion des joueurs
- `display.c/h` - Affichage et interface utilisateur
- `utils.c/h` - Fonctions utilitaires
- `save.c/h` - Fonctions de sauvegarde et chargement

## Configuration des cartes

Le jeu propose trois modes de configuration des valeurs de cartes:

1. **Valeurs par défaut**: Un ensemble prédéfini de cartes avec des valeurs entre -2 et 12
2. **Valeurs depuis un fichier**: Possibilité de charger une configuration depuis un fichier texte
3. **Valeurs personnalisées**: Définition interactive des valeurs et quantités de cartes

## Format du fichier de configuration des cartes

Si vous choisissez de charger les valeurs depuis un fichier, celui-ci doit être nommé `cards.txt` et suivre le format suivant:
```
valeur quantité
```

Exemple:
```
-2 2
-1 2
0 4
1 4
...
```

## Comment jouer

1. Au menu principal, sélectionnez "Nouvelle partie"
2. Configurez les paramètres du jeu selon vos préférences
3. Entrez les noms des joueurs
4. À chaque tour, choisissez d'où piocher et quelle carte échanger
5. Essayez de mémoriser vos cartes et observez les défausses des autres joueurs
6. Le joueur qui retourne toutes ses cartes en premier déclenche le dernier tour
7. À la fin, les scores sont calculés et le gagnant est annoncé

## Conseils stratégiques

- Observez les défausses des autres joueurs pour anticiper leurs mouvements
- Les cartes à valeur négative sont particulièrement intéressantes à garder
- Parfois, il peut être stratégique de ne pas retourner toutes vos cartes immédiatement

## Auteur

MEF1-L
TENZIN
AYA
GREGOIRE
     
     


