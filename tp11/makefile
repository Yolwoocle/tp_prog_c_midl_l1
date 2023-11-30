CC=gcc
CFLAGS=-std=c11 -Wpedantic -Wall -Wextra -fsanitize=address
LDLIBS=-lm
RM=rm -f
OBJ=tp11ex.o
EXE=tp11ex
# Pour produire le fichier exécutable
$(EXE):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LDLIBS)
# Pour produire les fichiers objets
ex2.o:tp11ex.c
	$(CC) $(CFLAGS) -c tp11ex.c
# Pour effacer les objets et les exécutables
clean:
	$(RM) $(OBJ) $(EXE) 
debug:
	gdb $(EXE)