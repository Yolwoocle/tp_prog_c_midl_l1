#include <stdio.h>
#include <stdlib.h>

/*
    Alloue dynamiquement un tableau de NbElts éléments de type double et retourne l’adresse
    de ce tableau ou NULL en cas de problème lors de l’allocation.
*/
double* creer_tableau(int nbelt) {
    return malloc(sizeof(double) * nbelt);
}

/*
    Saisit NbElts éléments de type double tapés au clavier et les range dans le tableau Tab. 
    On suppose que l’appelant a réservé l’espace mémoire nécessaire.
*/
void saisir_tableau(double *tab, int nb_elts) {
    for (int i = 0; i < nb_elts; i++) {
        double val;
        printf("tab[%3d] = ", i);
        scanf("%lf", &val);
        tab[i] = val;
    }
}

/*
    Affiche à l’écran le contenu du tableau passé en paramètre.
*/
void afficher_tableau(double *tab, int nb_elts) {
    printf("[");
    for (int i = 0; i < nb_elts; i++) {
        printf("%.2lf", tab[i]);
        if(i < nb_elts-1)
            printf(", ");
    }
    printf("]\n");
}

/*
    Libère l’espace mémoire occupé par le tableau passé en paramètre.
*/
void liberer_tableau(double *tab) {
    free(tab);
}

/*
    La fonction principale d’un programme permettant de tester les fonctions précédentes en
    demandant à l’utilisateur de donner le nombre de valeurs qu’il souhaite saisir puis les 
    valeurs du tableau.
*/
int main() {
    int n; 
    printf("Longueur du tableau = ");
    scanf("%d", &n);

    double *tab = creer_tableau(n);
    afficher_tableau(tab, n);
    saisir_tableau(tab, n);
    afficher_tableau(tab, n);

    liberer_tableau(tab);
    return 0;
}