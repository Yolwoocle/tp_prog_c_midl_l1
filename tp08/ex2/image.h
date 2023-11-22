#ifndef IMAGE_H
#define IMAGE_H
// #include <stddef.h>
#include "matrice.h"

typedef struct sImage *tImage;

extern tImage im_allouer(int nb_lignes, int nb_colonnes);
extern void im_liberer(tImage *pIm);
extern int im_nb_lig(tImage im);
extern int im_nb_col(tImage im);
extern tMatrice im_niv_gris(tImage im);
tImage im_lire(char nom_fichier[]);

#endif