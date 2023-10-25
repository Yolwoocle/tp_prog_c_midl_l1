#include <stdio.h>

void afficher_tab_raw(int tab[], int nb_elt) {
    for (int i = 0; i < nb_elt-1; i++) {
        printf("%d ", tab[i]);
    }
    printf("%d", tab[nb_elt-1]);
}

void afficher_tab(int tab[], int nb_elt) {
    for (int i = 0; i < nb_elt; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int min(int tab[], int nb_elt) {
    int m = tab[0];
    for (int i = 1; i < nb_elt; i++) {
        if (tab[i] < m)
            m = tab[i];
    }
    return m;
}

int max(int tab[], int nb_elt) {
    int m = tab[0];
    for (int i = 1; i < nb_elt; i++) {
        if (tab[i] > m)
            m = tab[i];
    }
    return m;
}

void minmax(int tab[], int nb_elt, int *pmin, int *pmax) {
    *pmin = tab[0];
    *pmax = tab[0];
    for (int i = 1; i < nb_elt; i++) {
        if (tab[i] < *pmin)
            *pmin = tab[i];
        if (tab[i] > *pmax)
            *pmax = tab[i];
    }
}

/*
 5. Écrivez la fonction d’en-tête :
    int SupprimerVal(int Tab[], int *pNbElt, int Val)
    qui supprime toutes les occurrences d’une valeur dans un tableau d’entiers. Le nombre de suppressions sera retourné par la fonction et le nombre d’éléments du tableau sera mis à jour.
    Paramètres :
    • Tab : tableau de int ;
    • pNbElt : adresse pointant vers le nombre d’éléments du tableau ;
    • Val : valeur à supprimer.
 */
int supprimer_val(int tab[], int* p_nbelt, int val) {
    int len_new = 0;
    int i = (*p_nbelt) - 1;
    while (i >= 0) {
        if (tab[i] == val) {
            for (int j = i + 1; j < *p_nbelt; j++) {
                tab[j - 1] = tab[j];
            }
            (*p_nbelt)--;
            len_new++;
        }
        i--;
    }
    return len_new;
}

int main1() {
    int tableau[] = {1, 2, 3, 4, 5};
    int tab21[] = {7, 3, 0, 64, -23, 0, 0};
    int tab22[] = {-4, 3, 5, -4, 2342342};
    int tab23[] = {1};
    int tab3[] = {-5, -5, 3, -3, 0, 32, 3, 3};
    int tab4[] = {6, 1, 12, 42, 56, 26, 35, 4012};
    printf("\n  EXO 1 \n");
    printf("tableau = ");
    afficher_tab(tableau, 5);
    printf("tab21 = ");
    afficher_tab(tab21, 7);
    printf("tab22 = ");
    afficher_tab(tab22, 5);
    printf("tab23 = ");
    afficher_tab(tab23, 1);
    printf("tab3 = ");
    afficher_tab(tab3, 8);
    printf("tab4 = ");
    afficher_tab(tab4, 8);

    printf("\n  EXO 2 \n");
    printf("min(tab21) = %d\n", min(tab21, 7));
    printf("min(tab22) = %d\n", min(tab22, 5));
    printf("min(tab23) = %d\n", min(tab23, 1));

    printf("\n  EXO 3 \n");
    printf("max(tab21) = %d\n", max(tab21, 7));
    printf("max(tab22) = %d\n", max(tab22, 5));
    printf("max(tab23) = %d\n", max(tab23, 1));

    int mini;
    int maxi;

    printf("\n  EXO 4 \n");
    minmax(tab3, 8, &mini, &maxi);
    printf("tab3:  min = %d; max = %d\n", mini, maxi);
    minmax(tab21, 7, &mini, &maxi);
    printf("tab21: min = %d; max = %d\n", mini, maxi);
    minmax(tab22, 5, &mini, &maxi);
    printf("tab22: min = %d; max = %d\n", mini, maxi);
    minmax(tab23, 1, &mini, &maxi);
    printf("tab23: min = %d; max = %d\n", mini, maxi);

    printf("\n  EXO 5 \n");
    int tab5[] = {1, 3, 2, 2, 3, 4, 2, 5};
    int len_tab5 = 8;

    printf("tab5 = ");
    afficher_tab(tab5, len_tab5);
    printf("> len_tab5 = %d\n", len_tab5);
        supprimer_val(tab5, &len_tab5, 2);
    printf("tab5 = ");
    afficher_tab(tab5, len_tab5);
    printf("> len_tab5 = %d\n", len_tab5);
        supprimer_val(tab5, &len_tab5, 5);
    printf("tab5 = ");
    afficher_tab(tab5, len_tab5);
    printf("> len_tab5 = %d\n", len_tab5);

    return 0;
}
