/***** Exercice 1 *****/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char tCoeff;
typedef tCoeff ** tMatrice;

/*
# Exercice 1
Alloue et initialise l’espace mémoire nécessaire pour stocker une matrice contenant 
NbLig lignes et NbCol colonnes. Cette fonction doit retourner la matrice ou NULL en 
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
# Exercice 2
  • demande à l’utilisateur le nombre de lignes et le nombre de colonnes de la matrice qu’il 
souhaite saisir ;
  • alloue la matrice grâce à l’appel de la fonction précédente ;
  • lit, ligne par ligne (la lecture d’une valeur de type unsigned char nécessite d’utiliser 
le spécificateur de format %hhu), les éléments et les stocke dans la matrice ;
  • délivre en sortie le nombre de lignes et de colonnes de la matrice ;
  • retourne la matrice ou NULL en cas de problème.
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
# Exercice 3
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
# Exercice 4
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
# Exercice 5
qui libère tout l’espace mémoire occupé par la matrice d’adresse pMat (le tableau contenant les éléments
et le tableau des pointeurs). Cette fonction doit aussi affecter la valeur NULL à la matrice libérée (ceci
permet d’éviter les erreurs à l’exécution si on essaie de libérer plusieurs fois la même matrice).
*/
void mat_liberer(tMatrice *p_mat) {
    free((*p_mat)[0]);
    free(*p_mat);
    *p_mat = NULL;
}

int main() {
    int nb_lig, nb_col;
    tMatrice mat = mat_lire(&nb_lig, &nb_col);

    mat_afficher(mat, nb_lig, nb_col);
    printf("\n");

    tMatrice mat2 = mat_copier(mat, nb_lig, nb_col);
    mat_afficher(mat2, nb_lig, nb_col);

    mat_liberer(&mat);
    mat_liberer(&mat2);

    if (mat == NULL)
        printf("mat NULL");
    else 
        printf("mat not NULL");

    if (mat2 == NULL)
        printf("mat2 NULL\n");
    else 
        printf("mat2 not NULL\n");
}