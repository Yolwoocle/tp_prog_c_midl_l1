#include <stdlib.h>
#include <stdio.h>
#include "matrice.h"

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    tMatrice mat = triangle(n);

    afficher_triangle(mat, n);
}