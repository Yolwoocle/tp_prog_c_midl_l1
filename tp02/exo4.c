#include <stdio.h>

/*
    Écrivez un programme qui affiche à l’écran un triangle isocèle constitué de n lignes. Ce nombre de
lignes doit être demandé à l’utilisateur. Par exemple, pour n = 5, l’affichage obtenu doit être le suivant
(la première étoile est précédée de n − 1 = 4 espaces) :

        *
       ***
      *****
     *******
    *********
*/

int main(void) {
    int n;
    printf("n = ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            printf(" ");
        }
        for (int j = 0; j < (2*i + 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}