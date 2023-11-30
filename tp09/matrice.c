#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

/*
Alloue et initialise l’espace mémoire nécessaire pour stocker une matrice contenant 
`NbLig` lignes et `NbCol` colonnes. Cette fonction doit retourner la matrice ou `NULL` en 
cas de problème. Ses principales étapes sont :
  • l’allocation du tableau contenant les éléments ;
  • l’allocation du tableau des pointeurs ;
  • le remplissage du tableau des pointeurs avec les adresses de début des lignes ;
  • la transmission à l’appelant de l’accès à la matrice.
*/
tMatrice mat_allouer(int nb_lig, int nb_col) {
    tCoeff * coeffs = malloc(sizeof(tCoeff) * nb_col * nb_lig);
    tMatrice matrice = malloc(sizeof(tCoeff *) * nb_lig);

    for (int i = 0; i < nb_lig; i++) {
        matrice[i] = &(coeffs[i*nb_col]);
    }

    return matrice;
}

/*
* - Demande à l’utilisateur le nombre de lignes et le nombre de colonnes de la matrice qu’il 
souhaite saisir ;
* - Alloue la matrice grâce à l’appel de la fonction précédente ;
* - Lit, ligne par ligne (la lecture d’une valeur de type unsigned char nécessite d’utiliser 
le spécificateur de format %hhu), les éléments et les stocke dans la matrice ;
* - Délivre en sortie le nombre de lignes et de colonnes de la matrice ;
* - Retourne la matrice ou NULL en cas de problème.
*/
tMatrice mat_lire(int *p_nb_lig, int *p_nb_col) {
    printf("Nombre de lignes   = ");
    scanf("%d", p_nb_lig);
    printf("Nombre de colonnes = ");
    scanf("%d", p_nb_col);

    tMatrice mat = mat_allouer(*p_nb_lig, *p_nb_col);

    for (int i = 0; i < *p_nb_lig; i++) {
        for (int j = 0; j < *p_nb_col; j++) {
            tCoeff val;
            printf("Valeur à (%3d, %3d): ", i, j);
            scanf("%hhu", &val);
            mat[i][j] = val;
        }
    }

    return mat;
}

/*
Affiche à l’écran le contenu de la matrice passée en paramètre (l’affichage d’une valeur de type
unsigned char se fait avec le spécificateur de format %d).
*/
void mat_afficher(tMatrice mat, int nb_lig, int nb_col) {
    for (int i = 0; i < nb_lig; i++) {
        for (int j = 0; j < nb_col; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}

/*
Affiche à l’écran le contenu de moitié inférieure gauche de la matrice passée en paramètre 
(l’affichage d’une valeur de type unsigned char se fait avec le spécificateur de format %d).
Suppose que la matrice est carrée.
*/
void afficher_triangle(tMatrice mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}

/*
Réalise une copie de la matrice Mat de taille NbLig×NbCol. Cette fonction doit retourner la copie
ou NULL en cas de problème. Ses principales étapes sont :
  • l’allocation de la copie ;
  • la copie des éléments ;
  • la transmission à l’appelant de l’accès à la copie.
*/
tMatrice mat_copier(tMatrice mat, int nb_lig, int nb_col) {
    tMatrice nmat = mat_allouer(nb_lig, nb_col);
    
    for (int i = 0; i < nb_lig; i++) {
        for (int j = 0; j < nb_col; j++) {
            nmat[i][j] = mat[i][j];
        }
    }

    return nmat;
}

/*
Libère tout l’espace mémoire occupé par la matrice d’adresse pMat (le tableau contenant les éléments
et le tableau des pointeurs). Cette fonction doit aussi affecter la valeur NULL à la matrice libérée (ceci
permet d’éviter les erreurs à l’exécution si on essaie de libérer plusieurs fois la même matrice).
*/
void mat_liberer(tMatrice *p_mat) {
    free((*p_mat)[0]);
    free(*p_mat);
    *p_mat = NULL;
}

tMatrice triangle(int n) {
    tMatrice mat = mat_allouer(n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                mat[i][j] = 1;
            } else {
                mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
            }
        }
    }

    return mat;
}
