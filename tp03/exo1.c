#include <stdio.h>


int main(void) {
    // Lecture du nombre de valeurs dans [[1, 100]]
    int n;
    printf("Nombre de valeurs : ");
    scanf("%d", &n);
    if (n < 1 || 100 > n) {
        printf("Nombre incorrect doit être entre 1 et 100\n");
        return 0;
    }

    // Lecture des valeurs et calcul de leur somme `s`
    double vals[100];
    double somme = 0;
    for (int i = 0; i < n; i++) {
        printf("[%d] : ", i);
        
        double val;
        scanf("%lf", &val);
        vals[i] = val;
        somme += val;
    }

    // Calcul et affichage de la moyenne `m`
    double moy = somme / n;
    printf("\n----> Moyenne = %.3lf\n", moy);

    // Affichage des valeurs supérieures à `m`
    printf("\n==| Valeurs supérieures à %.3lf |==\n", moy);
    for (int i = 0; i < n; i++) {
        if (vals[i] > moy) {
            printf("* [%d] %lf\n", i, vals[i]);
        }
    }
    printf("\n");

    return 0;
}