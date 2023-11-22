#ifndef MATRICE_H
#define MATRICE_H
#include <stddef.h>

typedef unsigned char tCoeff;
typedef tCoeff ** tMatrice;

extern tMatrice mat_allouer(int nb_lig, int nb_col);
extern void mat_liberer(tMatrice *p_mat);
extern tMatrice triangle(int n);

extern void mat_afficher(tMatrice mat, int nb_lig, int nb_col);
extern void afficher_triangle(tMatrice mat, int n);

extern tMatrice mat_lire(int *p_nb_lig, int *p_nb_col);
extern tMatrice mat_copier(tMatrice mat, int nb_lig, int nb_col);

#endif