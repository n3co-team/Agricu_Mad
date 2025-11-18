# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -fPIC
DEBUG_FLAGS = -g -DDEBUG
RELEASE_FLAGS = -O2 -DNDEBUG
LDFLAGS = -lm
SHARED_FLAGS = -shared
AR = ar
ARFLAGS = rcs

# Répertoires
SRC_DIR = src
HEADERS_DIR = headers
BIN_DIR = bin
LIB_DIR = lib
OBJ_DIR = object
STATIC_LIB_DIR = $(LIB_DIR)/static
SHARED_LIB_DIR = $(LIB_DIR)/shared

# Sous-répertoires source
SRC_SUBDIRS = USER_I/menu USER_I/resultat anal- conven BD_prod

# Fichiers source principaux
MAIN_SRC = $(SRC_DIR)/main.c

# Trouver tous les fichiers source C
SRCS = $(MAIN_SRC) \
       $(wildcard $(SRC_DIR)/USER_I/menu/*.c) \
       $(wildcard $(SRC_DIR)/USER_I/resultat/*.c) \
       $(wildcard $(SRC_DIR)/anal-/*.c) \
       $(wildcard $(SRC_DIR)/conven/*.c) \
       $(wildcard $(SRC_DIR)/BD_prod/*.c) \
       $(wildcard $(SRC_DIR)/dom.c)

# Fichiers objets correspondants
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Bibliothèques partagées
SHARED_LIBS = $(SHARED_LIB_DIR)/libmenu.so $(SHARED_LIB_DIR)/libanal.so $(SHARED_LIB_DIR)/libconven.so $(SHARED_LIB_DIR)/libbdprod.so

# Bibliothèques statiques
STATIC_LIBS = $(STATIC_LIB_DIR)/libmenu.a $(STATIC_LIB_DIR)/libanal.a $(STATIC_LIB_DIR)/libconven.a $(STATIC_LIB_DIR)/libbdprod.a

# Exécutable principal (utilise les bibliothèques partagées par défaut)
EXEC = $(BIN_DIR)/agricu
EXEC_STATIC = $(BIN_DIR)/agricu-static

# Cible par défaut
all: $(OBJ_DIR) $(BIN_DIR) $(SHARED_LIB_DIR) $(SHARED_LIBS) $(EXEC)

# Création des répertoires
$(BIN_DIR) $(SHARED_LIB_DIR) $(STATIC_LIB_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@
	$(foreach dir,$(SRC_SUBDIRS),mkdir -p $(OBJ_DIR)/$(dir);)

# Règles pour les bibliothèques partagées
$(SHARED_LIB_DIR)/libmenu.so: $(filter $(OBJ_DIR)/USER_I/menu/%.o $(OBJ_DIR)/USER_I/resultat/%.o,$(OBJS))
	$(CC) $(SHARED_FLAGS) -o $@ $^ $(LDFLAGS)

$(SHARED_LIB_DIR)/libanal.so: $(filter $(OBJ_DIR)/anal-/%.o $(OBJ_DIR)/dom.o,$(OBJS))
	$(CC) $(SHARED_FLAGS) -o $@ $^ $(LDFLAGS)

$(SHARED_LIB_DIR)/libconven.so: $(filter $(OBJ_DIR)/conven/%.o,$(OBJS))
	$(CC) $(SHARED_FLAGS) -o $@ $^ $(LDFLAGS)

$(SHARED_LIB_DIR)/libbdprod.so: $(filter $(OBJ_DIR)/BD_prod/%.o,$(OBJS))
	$(CC) $(SHARED_FLAGS) -o $@ $^ $(LDFLAGS)

# Règles pour les bibliothèques statiques
$(STATIC_LIB_DIR)/libmenu.a: $(filter $(OBJ_DIR)/USER_I/menu/%.o $(OBJ_DIR)/USER_I/resultat/%.o,$(OBJS))
	$(AR) $(ARFLAGS) $@ $^

$(STATIC_LIB_DIR)/libanal.a: $(filter $(OBJ_DIR)/anal-/%.o $(OBJ_DIR)/dom.o,$(OBJS))
	$(AR) $(ARFLAGS) $@ $^

$(STATIC_LIB_DIR)/libconven.a: $(filter $(OBJ_DIR)/conven/%.o,$(OBJS))
	$(AR) $(ARFLAGS) $@ $^

$(STATIC_LIB_DIR)/libbdprod.a: $(filter $(OBJ_DIR)/BD_prod/%.o,$(OBJS))
	$(AR) $(ARFLAGS) $@ $^

# Exécutable principal avec bibliothèques partagées
$(EXEC): $(OBJ_DIR)/main.o $(SHARED_LIBS)
	$(CC) -o $@ $(OBJ_DIR)/main.o -L$(SHARED_LIB_DIR) -lmenu -lanal -lconven -lbdprod $(LDFLAGS) -Wl,-rpath,$(SHARED_LIB_DIR)

# Solution 1: Utiliser --start-group et --end-group pour résoudre les dépendances circulaires
$(EXEC_STATIC): $(OBJ_DIR)/main.o $(STATIC_LIBS)
	$(CC) -static -o $@ $(OBJ_DIR)/main.o -L$(STATIC_LIB_DIR) -Wl,--start-group -lconven -lmenu -lanal -lbdprod -Wl,--end-group $(LDFLAGS)

# Solution 2: Lier toutes les bibliothèques statiques en un seul groupe (plus simple)
$(EXEC_STATIC)-all: $(OBJ_DIR)/main.o $(STATIC_LIBS)
	$(CC) -static -o $@ $(OBJ_DIR)/main.o $(STATIC_LIB_DIR)/*.a $(LDFLAGS)

# Solution 3: Créer une méga-bibliothèque statique combinée
$(STATIC_LIB_DIR)/libagricu.a: $(STATIC_LIBS)
	cd $(STATIC_LIB_DIR) && for lib in *.a; do ar x $$lib; done
	cd $(STATIC_LIB_DIR) && $(AR) $(ARFLAGS) libagricu.a *.o
	cd $(STATIC_LIB_DIR) && rm -f *.o

$(EXEC_STATIC)-combined: $(OBJ_DIR)/main.o $(STATIC_LIB_DIR)/libagricu.a
	$(CC) -static -o $@ $(OBJ_DIR)/main.o -L$(STATIC_LIB_DIR) -lagricu $(LDFLAGS)

# Règle générique pour les fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@

# Cibles pour construire les bibliothèques statiques
static: $(OBJ_DIR) $(BIN_DIR) $(STATIC_LIB_DIR) $(STATIC_LIBS) $(EXEC_STATIC)

static-all: $(OBJ_DIR) $(BIN_DIR) $(STATIC_LIB_DIR) $(STATIC_LIBS) $(EXEC_STATIC)-all

static-combined: $(OBJ_DIR) $(BIN_DIR) $(STATIC_LIB_DIR) $(STATIC_LIBS) $(STATIC_LIB_DIR)/libagricu.a $(EXEC_STATIC)-combined

# Cible pour construire les deux types de bibliothèques
both: all static

# Règles de nettoyage
clean:
	rm -rf $(OBJ_DIR)

distclean: clean
	rm -rf $(BIN_DIR) $(LIB_DIR)

# Installation des bibliothèques partagées
PREFIX ?= /usr/local
install-shared: all
	mkdir -p $(PREFIX)/bin $(PREFIX)/lib $(PREFIX)/include/agricu
	cp $(EXEC) $(PREFIX)/bin/
	cp $(SHARED_LIBS) $(PREFIX)/lib/
	cp $(HEADERS_DIR)/*.h $(PREFIX)/include/agricu/
	ldconfig

# Installation des bibliothèques statiques (utilise la solution avec groupes)
install-static: static
	mkdir -p $(PREFIX)/bin $(PREFIX)/lib $(PREFIX)/include/agricu
	cp $(EXEC_STATIC) $(PREFIX)/bin/
	cp $(STATIC_LIBS) $(PREFIX)/lib/
	cp $(HEADERS_DIR)/*.h $(PREFIX)/include/agricu/

# Installation avec la bibliothèque combinée
install-static-combined: static-combined
	mkdir -p $(PREFIX)/bin $(PREFIX)/lib $(PREFIX)/include/agricu
	cp $(EXEC_STATIC)-combined $(PREFIX)/bin/agricu-static
	cp $(STATIC_LIB_DIR)/libagricu.a $(PREFIX)/lib/
	cp $(HEADERS_DIR)/*.h $(PREFIX)/include/agricu/

# Installation des deux types de bibliothèques
install: install-shared install-static

# Installation de développement (headers + bibliothèques)
install-dev: both
	mkdir -p $(PREFIX)/bin $(PREFIX)/lib $(PREFIX)/include/agricu
	cp $(EXEC) $(PREFIX)/bin/
	cp $(EXEC_STATIC) $(PREFIX)/bin/
	cp $(SHARED_LIBS) $(PREFIX)/lib/
	cp $(STATIC_LIBS) $(PREFIX)/lib/
	cp $(HEADERS_DIR)/*.h $(PREFIX)/include/agricu/
	ldconfig

# Désinstallation
uninstall:
	rm -f $(PREFIX)/bin/agricu
	rm -f $(PREFIX)/bin/agricu-static
	rm -f $(PREFIX)/lib/libmenu.*
	rm -f $(PREFIX)/lib/libanal.*
	rm -f $(PREFIX)/lib/libconven.*
	rm -f $(PREFIX)/lib/libbdprod.*
	rm -f $(PREFIX)/lib/libagricu.*
	rm -rf $(PREFIX)/include/agricu

# Développement avec debug
debug: CFLAGS += $(DEBUG_FLAGS)
debug: all

debug-static: CFLAGS += $(DEBUG_FLAGS)
debug-static: static

# Release
release: CFLAGS += $(RELEASE_FLAGS)
release: all

release-static: CFLAGS += $(RELEASE_FLAGS)
release-static: static

# Affichage des variables (pour debug)
print:
	@echo "Sources: $(SRCS)"
	@echo "Objects: $(OBJS)"
	@echo "Shared Libraries: $(SHARED_LIBS)"
	@echo "Static Libraries: $(STATIC_LIBS)"
	@echo "CFLAGS: $(CFLAGS)"

# Dépendances (génération automatique)
-include $(OBJS:.o=.d)

# Génération automatique des dépendances
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -MMD -c $< -o $@

.PHONY: all static static-all static-combined both clean distclean install install-shared install-static install-static-combined install-dev uninstall debug debug-static release release-static print
