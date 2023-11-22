CC=gcc
CFLAGS=-std=c11 -Wpedantic -Wall -Wextra
LDLIBS=-lm
RM=rm -f
OBJ=ex2.o matrice.o image.o
EXE=ex2
# Pour produire le fichier exécutable
$(EXE):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LDLIBS)
# Pour produire les fichiers objets
ex2.o:ex2.c matrice.h image.h
	$(CC) $(CFLAGS) -c ex2.c
image.o:image.c image.h
	$(CC) $(CFLAGS) -c image.c
matrice.o:matrice.c matrice.h
	$(CC) $(CFLAGS) -c matrice.c
# Pour effacer les objets et les exécutables
clean:
	$(RM) $(OBJ) $(EXE) 
debug:
	gdb $(EXE)