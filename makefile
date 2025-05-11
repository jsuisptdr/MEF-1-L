#Programme à créer
PROG = CardYard

# Sources
SRC = main.c card.c display.c game.c player.c save.c utils.c

# Dossier de sauvegarde
SAVE_DIR = saves

# Vérification si le dossier de sauvegarde existe et le crée si il n'existe pas
ifneq ($(wildcard $(SAVE_DIR)),)
	# Le dossier existe déjà
else
	$(shell mkdir -p $(SAVE_DIR))
endif

# Règle par défaut : compile et exécute
all: $(PROG)
	./$(PROG)

# Compilation du programme
$(PROG): $(SRC) card.h display.h game.h player.h save.h utils.h
	gcc -Wall -o $(PROG) $(SRC)

# Nettoyage
clean:
	rm -f $(PROG)