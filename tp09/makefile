CC=gcc
CFLAGS=-std=c11 -Wpedantic -Wall -Wextra -fsanitize=address
LDLIBS=-lm
RM=rm -f
OBJ=tp9.o matrice.o image.o ti.o
EXE=tp9
# Pour produire le fichier exécutable
$(EXE):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LDLIBS)
# Pour produire les fichiers objets
tp9.o:tp9.c matrice.h image.h ti.h
	$(CC) $(CFLAGS) -c tp9.c
matrice.o:matrice.c matrice.h
	$(CC) $(CFLAGS) -c matrice.c
image.o:image.c image.h
	$(CC) $(CFLAGS) -c image.c
ti.o:ti.c ti.h
	$(CC) $(CFLAGS) -c ti.c
# Pour effacer les objets et les exécutables
clean:
	$(RM) $(OBJ) $(EXE) 
debug:
	gdb $(EXE)