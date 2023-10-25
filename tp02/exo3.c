#include <stdio.h>

/*
  1. En utilisant une boucle for, écrire un programme qui affiche à l’écran la moyenne 
d’une série de valeurs réelles. L’utilisateur donnera le nombre de valeurs dont il veut 
calculer la moyenne suivi des valeurs.

  2. Modifiez votre programme afin de considérer uniquement des notes. Pour cela, vous 
vérifierez que chaque note est comprise entre 0 et 20. Si ce n’est pas le cas, demandez 
à l’utilisateur de saisir de nouveau la note tant qu’elle n’est pas comprise entre 0 et 20.
*/

int main(void) {
    printf("Combien de valeurs ? ");
    int n;
    scanf("%d", &n);

    int som = 0;
    int i = 0;
    while (i < n) {
        printf("[%d/%d] Entrez une valeur: ", i+1, n);
        int val;
        scanf("%d", &val);
        if (0 <= val && val <= 20) {
            som += val;
            i++;
        } else {
            printf("Nombre incorrect.\n");
        }
    }
    printf("Moyenne = %lf\n", ((double) som)/((double) n));
    return 0;
}