#include <stdio.h>
#include <stdlib.h>

/*
Trie dans l’ordre croissant les NbElts valeurs de type int stockées dans le tableau Tab. Vous
pouvez utiliser l’algorithme du tri à bulles qui consiste à :
```py
Pour i = NbElts−1 ... 1
____Pour j = 0 ... i − 1
________Si Tab[j + 1] < Tab[j]
____________Permuter Tab[j + 1] et Tab[j]
```
*/
void trier(int tab[], int nb_elts) {
    for (int i = nb_elts-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (tab[j+1] < tab[j]) {
                int temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
}

/*
Affiche les éléments du tableau passé en paramètre.
*/
void aff(int tab[], int nb_elts) {
    printf("[");
    for (int i = 0; i < nb_elts; i++) {
        printf("%d", tab[i]);
        if (i < nb_elts-1)
            printf(", ");
    }
    printf("]\n");
}

/*
Affiche les valeurs de type int pointées par chacun des NbElts éléments de TabP. Avec l’exemple
précédent, l’appel :
```c
AffPtr(TableauP,3);
```
devra produire l’affichage de :
```c
1 2 3
```
*/
void aff_ptr(int * tab[], int nb_elts) {
    printf("[");
    for (int i = 0; i < nb_elts; i++) {
        printf("%d", *(tab[i]));
        if (i < nb_elts-1)
            printf(", ");
    }
    printf("]\n");
}

/*
Ne modifie pas les valeurs du tableau Tab, mais qui remplit le tableau Ptr avec les adresses
des éléments du tableau Tab dans l’ordre croissant de ces éléments. Par exemple, si on déclare :
```c
int Tableau[3]={3,1,2};
```
alors, après la séquence suivante :
```c
int *TableauP[3];
TrierPtr(Tableau,3,TableauP);
```
`TableauP[0]` contiendra l’adresse de `Tableau[1]`, `TableauP[1]` contiendra l’adresse de 
`Tableau[2]` et `TableauP[2]` contiendra l’adresse de `Tableau[0]`.
*/
void trier_ptr(int tab[], int nb_elts, int *ptr[]) {
    for (int i = 0; i < nb_elts; i++) {
        ptr[i] = &(tab[i]);
    }

    for (int i = nb_elts-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (*(ptr[j+1]) < *(ptr[j])) {
                int* temp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp;
            }
        }
    }
}

/*
 Écrivez deux nouvelles versions de la fonction TrierPtr dans lesquelles l’espace mémoire du
tableau des pointeurs n’est pas réservé par l’appelant, mais est alloué de manière dynamique
par la fonction TrierPtr. Dans la première de ces deux versions, le tableau des pointeurs sera
retourné par la fonction. Dans la seconde version, le tableau devra être délivré en sortie de la
fonction. Trouver les en-têtes de ces deux versions fait partie de l’exercice.
*/


int main(void) {
    int tab[] = {5, 3, 4, 2, 1};
    int *p_tab_tri[5];
    aff(tab, 5);

    trier_ptr(tab, 5, p_tab_tri);
    
    aff(tab, 5);
    aff_ptr(p_tab_tri, 5);

    return 0;
}