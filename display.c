#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "display.h"
#include "game.h"

// Couleurs des joueurs
const char* COULEURS_JOUEURS[] = {
    B_CYAN,      // Joueur 1
    B_MAGENTA,   // Joueur 2
    B_JAUNE,     // Joueur 3
    B_VERT,      // Joueur 4
    B_BLEU,      // Joueur 5
    B_ROUGE      // Joueur 6

};

const char* get_color(int colorValue) {
    if (colorValue == EMPTY_CARD) return BLANC; // Cartes non retournées en blanc
    else if (colorValue == -20) return NOIR; 
    else if (colorValue == -19) return B_NOIR;
    else if (colorValue == -18) return ROUGE;
    else if (colorValue == -17) return B_ROUGE;
    else if (colorValue == -16) return VERT;
    else if (colorValue == -15) return B_VERT;
    else if (colorValue == -14) return JAUNE;
    else if (colorValue == -13) return B_JAUNE;
    else if (colorValue == -12) return BLEU;
    else if (colorValue == -11) return B_BLEU;
    else if (colorValue == -10) return MAGENTA;
    else if (colorValue == -9) return B_MAGENTA;
    else if (colorValue == -8) return CYAN;
    else if (colorValue == -7) return B_CYAN;
    else if (colorValue == -6) return BLANC;
    else if (colorValue == -5) return ROUGE;
    else if (colorValue == -4) return B_ROUGE;
    else if (colorValue == -3) return VERT;
    else if (colorValue == -2) return B_VERT;
    else if (colorValue == -1) return JAUNE;
    else if (colorValue == 0) return B_JAUNE;
    else if (colorValue == 1) return BLEU;
    else if (colorValue == 2) return B_BLEU;
    else if (colorValue == 3) return MAGENTA;
    else if (colorValue == 4) return B_MAGENTA;
    else if (colorValue == 5) return CYAN;
    else if (colorValue == 6) return B_CYAN;
    else if (colorValue == 7) return ROUGE;
    else if (colorValue == 8) return B_ROUGE;
    else if (colorValue == 9) return VERT;
    else if (colorValue == 10) return B_VERT;
    else if (colorValue == 11) return BLEU;
    else if (colorValue == 12) return B_BLEU;
    else if (colorValue == 13) return MAGENTA;
    else if (colorValue == 14) return B_MAGENTA;
    else if (colorValue == 15) return CYAN;
    else if (colorValue == 16) return B_CYAN;
    else if (colorValue == 17) return ROUGE;
    else if (colorValue == 18) return B_ROUGE;
    else if (colorValue == 19) return VERT;
    else if (colorValue == 20) return B_VERT;
    else return BLANC; // Valeur par défaut
}

// Obtenir la chaîne formatée pour une colorValue
const char* get_formatted_value(int colorValue) {
    if (colorValue == EMPTY_CARD) {
        return "~~~~~~";
    } else if (colorValue <= -10) {
        // Pour les nombres négatifs à deux chiffres
        if (colorValue == -10) return " -10  ";
        if (colorValue == -11) return " -11  ";
        if (colorValue == -12) return " -12  ";
        if (colorValue == -13) return " -13  ";
        if (colorValue == -14) return " -14  ";
        if (colorValue == -15) return " -15  ";
        if (colorValue == -16) return " -16  ";
        if (colorValue == -17) return " -17  ";
        if (colorValue == -18) return " -18  ";
        if (colorValue == -19) return " -19  ";
        if (colorValue == -20) return " -20  ";
        return " -??  "; // Valeur par défaut pour d'autres cas
    } else if (colorValue < 0) {
        // Pour les nombres négatifs à un chiffre
        if (colorValue == -1) return "  -1  ";
        if (colorValue == -2) return "  -2  ";
        if (colorValue == -3) return "  -3  ";
        if (colorValue == -4) return "  -4  ";
        if (colorValue == -5) return "  -5  ";
        if (colorValue == -6) return "  -6  ";
        if (colorValue == -7) return "  -7  ";
        if (colorValue == -8) return "  -8  ";
        if (colorValue == -9) return "  -9  ";
        return "  -?   "; // Ne devrait jamais arriver ici
    } else if (colorValue >= 10) {
        // Pour les nombres positifs à deux chiffres
        if (colorValue == 10) return "  10  ";
        if (colorValue == 11) return "  11  ";
        if (colorValue == 12) return "  12  ";
        if (colorValue == 13) return "  13  ";
        if (colorValue == 14) return "  14  ";
        if (colorValue == 15) return "  15  ";
        if (colorValue == 16) return "  16  ";
        if (colorValue == 17) return "  17  ";
        if (colorValue == 18) return "  18  ";
        if (colorValue == 19) return "  19  ";
        if (colorValue == 20) return "  20  ";
        return "  ??  "; // Valeur par défaut pour d'autres cas
    } else {
        // Pour les nombres positifs à un chiffre
        if (colorValue == 0) return "   0  ";
        if (colorValue == 1) return "   1  ";
        if (colorValue == 2) return "   2  ";
        if (colorValue == 3) return "   3  ";
        if (colorValue == 4) return "   4  ";
        if (colorValue == 5) return "   5  ";
        if (colorValue == 6) return "   6  ";
        if (colorValue == 7) return "   7  ";
        if (colorValue == 8) return "   8  ";
        if (colorValue == 9) return "   9  ";
        return "   ?   "; // Ne devrait jamais arriver ici
    }
}

// Affiche les cartes d'un joueur en horizontal, mais ligne par ligne
void display_player_cards_horizontal(int playerCards[], int startIndex, int endIndex, const char* player_color) {
    // Première ligne (bordure supérieure) pour toutes les cartes
    for (int i = startIndex; i <= endIndex; i++) {
        const char* cardColor = get_color(playerCards[i]);
        printf("%s┌──────┐%s ", cardColor, RESET);
    }
    printf("\n");
    
    // Deuxième ligne (CARD) pour toutes les cartes
    for (int i = startIndex; i <= endIndex; i++) {
        const char* cardColor = get_color(playerCards[i]);
        printf("%s│ CARD │%s ", cardColor, RESET);
    }
    printf("\n");
    
    // Troisième ligne (colorValue) pour toutes les cartes
    for (int i = startIndex; i <= endIndex; i++) {
        const char* cardColor = get_color(playerCards[i]);
        const char* colorValue = get_formatted_value(playerCards[i]);
        printf("%s│%s│%s ", cardColor, colorValue, RESET);
    }
    printf("\n");
    
    // Quatrième ligne (YARD) pour toutes les cartes
    for (int i = startIndex; i <= endIndex; i++) {
        const char* cardColor = get_color(playerCards[i]);
        printf("%s│ YARD │%s ", cardColor, RESET);
    }
    printf("\n");
    
    // Cinquième ligne (bordure inférieure) pour toutes les cartes
    for (int i = startIndex; i <= endIndex; i++) {
        const char* cardColor = get_color(playerCards[i]);
        printf("%s└──────┘%s ", cardColor, RESET);
    }
    printf("\n");
}

// Affiche une seule défausse
void display_discard(int colorValue, const char* player_color) {
    const char* cardColor = get_color(colorValue);
    const char* valeur_formatee = get_formatted_value(colorValue);
    
    printf("%s┌──────┐%s\n", cardColor, RESET);
    printf("%s│%sDEFAU.%s│%s\n", cardColor, player_color, cardColor, RESET);
    printf("%s│%s│%s\n", cardColor, valeur_formatee, RESET);
    printf("%s│      │%s\n", cardColor, RESET);
    printf("%s└──────┘%s\n", cardColor, RESET);
}

// Affiche la pioche centrale
void display_draw_pile(int currentCard) {
    const char* cardColor = get_color(currentCard);
    const char* colorValue = get_formatted_value(currentCard);
    
    printf("\n");
    printf("╔════════════════════════╗\n");
    printf("║    PIOCHE CENTRALE     ║\n");
    printf("╚════════════════════════╝\n\n");
    
    printf("        %s┌──────┐%s\n", cardColor, RESET);
    printf("        %s│ CARD │%s\n", cardColor, RESET);
    printf("        %s│%s│%s\n", cardColor, colorValue, RESET);
    printf("        %s│ YARD │%s\n", cardColor, RESET);
    printf("        %s└──────┘%s\n\n", cardColor, RESET);
}

// Affiche un séparateur de section
void display_section_divider(const char* titre) {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║ %-56s   ║\n", titre);
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
}

// Affiche l'entête pour un joueur
void display_player_header(int index, const char* nom, const char* player_color) {
    printf("\n");
    printf("%s╔═══════════════════════════════════════════════╗%s\n", player_color, RESET);
    printf("%s║ JOUEUR %d : %-34s ║%s\n", player_color, index + 1, nom, RESET);
    printf("%s╚═══════════════════════════════════════════════╝%s\n\n", player_color, RESET);
}

// Fonction principale pour afficher l'état du jeu
void display_game(GameState *game) {
    // Vérification que le nombre de joueurs est valide
    if (game->numPlayers < MIN_PLAYERS || game->numPlayers > MAX_PLAYERS) {
        printf("Erreur: Le nombre de joueurs doit être entre %d et %d.\n", MIN_PLAYERS, MAX_PLAYERS);
        return;
    }
    
    clear_screen();
    
    // Afficher la pioche centrale
    display_draw_pile(game->currentCentralCard);
    
    // Afficher toutes les défausses
    display_section_divider("DÉFAUSSES DES JOUEURS");
    
    for (int i = 0; i < game->numPlayers; i++) {
        printf("%s%s (J%d)%s\n", COULEURS_JOUEURS[i], game->playerNames[i], i + 1, RESET);
        display_discard(game->personalDiscards[i], COULEURS_JOUEURS[i]);
        printf("\n");
    }
    
    // Ensuite, afficher chaque joueur individuellement avec ses cartes
    display_section_divider("CARTES DES JOUEURS");
    
    for (int i = 0; i < game->numPlayers; i++) {
        // Afficher l'entête du joueur avec sa cardColor
        display_player_header(i, game->playerNames[i], COULEURS_JOUEURS[i]);
        
        // Afficher les cartes du joueur
        int milieu = game->cardsPerPlayer / 2;
        if (game->cardsPerPlayer > 6) {
            // Première moitié des cartes
            display_player_cards_horizontal(game->playerCards[i], 0, milieu - 1, COULEURS_JOUEURS[i]);
            printf("\n");
            
            // Seconde moitié des cartes
            display_player_cards_horizontal(game->playerCards[i], milieu, game->cardsPerPlayer - 1, COULEURS_JOUEURS[i]);
        } else {
            // Toutes les cartes sur une seule rangée
            display_player_cards_horizontal(game->playerCards[i], 0, game->cardsPerPlayer - 1, COULEURS_JOUEURS[i]);
        }
    }
    
    // Indiquer le joueur actuel
    printf("\n\n");
    printf("%s╔════════════════════════════════════════════════════════════╗%s\n", 
           COULEURS_JOUEURS[game->currentPlayerIndex], RESET);
    printf("%s║ C'EST AU TOUR DE %-38s    ║%s\n", 
           COULEURS_JOUEURS[game->currentPlayerIndex], game->playerNames[game->currentPlayerIndex], RESET);
    printf("%s╚════════════════════════════════════════════════════════════╝%s\n", 
           COULEURS_JOUEURS[game->currentPlayerIndex], RESET);
}

void display_welcome_message() {
    printf("\n\n");
    printf("  ██████╗ █████╗ ██████╗ ██████╗     ██╗   ██╗ █████╗ ██████╗ ██████╗ \n");
    printf(" ██╔════╝██╔══██╗██╔══██╗██╔══██╗    ╚██╗ ██╔╝██╔══██╗██╔══██╗██╔══██╗\n");
    printf(" ██║     ███████║██████╔╝██║  ██║     ╚████╔╝ ███████║██████╔╝██║  ██║\n");
    printf(" ██║     ██╔══██║██╔══██╗██║  ██║      ╚██╔╝  ██╔══██║██╔══██╗██║  ██║\n");
    printf(" ╚██████╗██║  ██║██║  ██║██████╔╝       ██║   ██║  ██║██║  ██║██████╔╝\n");
    printf("  ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝        ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ \n");
    printf("\n\n");
    printf("Bienvenue dans le jeu Card Yard!\n\n");
    
    pauseWithMessage("Appuyez sur Entrée pour continuer...");
}

void display_instructions() {
    clear_screen();
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║                     INSTRUCTIONS                           ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");

    printf("Card Yard est un jeu de cartes où le but est d'avoir le score le plus bas.\n\n");

    printf("RÈGLES DU JEU:\n");
    printf("-------------\n");
    printf("1. Chaque joueur commence avec un certain nombre de cartes face cachée.\n");
    printf("2. À chaque tour, un joueur peut:\n");
    printf("   a. Piocher une carte de la pioche centrale et l'échanger avec une de ses cartes\n");
    printf("   b. Prendre une carte d'une défausse et l'échanger avec une de ses cartes\n");
    printf("3. La carte remplacée est placée dans la défausse du joueur.\n");
    printf("4. Les cartes sont retournées lors des échanges.\n");
    printf("5. Le premier joueur à retourner toutes ses cartes termine la manche.\n");
    printf("6. Tous les autres joueurs jouent alors un dernier tour.\n");
    printf("7. Le score de chaque joueur est la somme des valeurs de ses cartes.\n");
    printf("8. Le joueur avec le score le plus bas gagne!\n\n");

    printf("COMMANDES:\n");
    printf("---------\n");
    printf("- Suivez les instructions à l'écran pour jouer.\n");
    printf("- Utilisez les touches numériques pour sélectionner vos actions.\n");
    printf("- Appuyez sur Entrée pour valider vos choix.\n\n");

    printf("ASTUCES:\n");
    printf("-------\n");
    printf("- Essayez de mémoriser les cartes que vous avez retournées.\n");
    printf("- Observez les défausses des autres joueurs pour anticiper leurs mouvements.\n");
    printf("- Échangez stratégiquement vos cartes pour minimiser votre score.\n\n");

    pauseWithMessage("Appuyez sur Entrée pour revenir au menu principal...");
}

void display_error(const char *message) {
    printf("%sErreur: %s%s\n", ROUGE, message, RESET);
}

void display_message(const char *message) {
    printf("%sInfo: %s%s\n", BLEU, message, RESET);
}

void clear_screen() {
    system("clear || cls"); // Clear screen for Unix/Linux or Windows
}

void display_player_turn(GameState *game) {
    int index = game->currentPlayerIndex;
    const char* cardColor = COULEURS_JOUEURS[index];
    
    printf("%sC'est le tour de %s!%s\n\n", cardColor, game->playerNames[index], RESET);
    printf("Sélectionnez une action:\n");
    printf("- Piocher une carte de la pioche centrale\n");
    printf("- Prendre une carte d'une défausse personnelle\n");
    printf("- Échanger une carte avec un autre joueur\n");
    printf("- Terminer le tour\n");
}

void display_game_results(GameState *game, int sortedIndices[], int scores[]) {
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║                RÉSULTATS                     ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    // Afficher tous les scores
    for (int i = 0; i < game->numPlayers; i++) {
        int idx = sortedIndices[i];
        printf("%s%s: %d points%s\n", 
               COULEURS_JOUEURS[idx], 
               game->playerNames[idx], 
               scores[idx], 
               RESET);
    }

    // Afficher le gagnant
    int winnerIdx = sortedIndices[0];
    printf("\n%s╔══════════════════════════════════════════════╗%s\n", COULEURS_JOUEURS[winnerIdx], RESET);
    printf("%s║ LE GAGNANT EST %-25s ║%s\n", COULEURS_JOUEURS[winnerIdx], game->playerNames[winnerIdx], RESET);
    printf("%s║ AVEC %d POINTS                               ║%s\n", COULEURS_JOUEURS[winnerIdx], scores[winnerIdx], RESET);
    printf("%s╚══════════════════════════════════════════════╝%s\n", COULEURS_JOUEURS[winnerIdx], RESET);
}
