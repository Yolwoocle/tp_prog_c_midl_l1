#include <stdio.h>
#include <math.h>

int main(void) {

    // Lecture de la taille de la matrice carrée de taille n×n, n ∈ [[1, 10]]
    int n;
    printf("Taille de la matrice : ");
    scanf("%d", &n);
    if (!(1 <= n && n <= 10)) {
        printf("Nombre incorrect.\n");
        return 0;
    }
    
    // Saisie des valeurs de la matrice m 
    double mat[10][10];
    printf("          +-\n");
    for (int i = 0; i < n; i++) {
        printf("Ligne %d : | ", i);
        for (int j = 0; j < n; j++) {
            double coeff; 
            scanf("%lf", &coeff);
            mat[i][j] = coeff;
        }
    }
    printf("          +-\n");

    // Affichage de la matrice
    printf("+-\n");
    for (int i = 0; i < n; i++) {
        printf("| ");
        for (int j = 0; j < n; j++) {
            printf("%.2lf ", mat[i][j]);                
        }
        printf("\n");
    } 
    printf("+-\n\n");

    // Détermination du caractère symétrique de m
    // Affichage du résultat
    double ε = 10e-10;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (fabs(mat[i][j] - mat[j][i]) >= ε) {
                printf("--> Pas symétrique\n");
                return 0;
            }
        }
    }
    printf("--> Symétrique\n");
}