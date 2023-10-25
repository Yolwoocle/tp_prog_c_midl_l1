#include <stdio.h>

/*
 1. Écrivez un programme qui lit un texte tapé au clavier se terminant par le caractère # 
et affiche à l’écran le nombre de lettres et de voyelles qu’il contient.
    On suppose que le texte ne contient que des lettres minuscules non accentuées, que les mots
ne sont séparés que par des espaces, qu’il n’y a aucune ponctuation et qu’il ne contient pas de
caractère « saut de ligne » (« new line »).

 2. Modifiez votre programme afin de vérifier que chaque caractère saisi par l’utilisateur est 
bien une lettre minuscule non accentuée ou un espace. Dans le cas contraire, avant d’être 
interrompu, le programme doit afficher un message indiquant le caractère erroné et son code.
*/

#define TEXT_SIZE 256

int main(void) {
    char text[TEXT_SIZE];
    printf("Entrez un texte finissant par '#' : ");
    scanf("%s", &text);

    int i;
    i = 0;
    while (i < TEXT_SIZE && text[i] != '#') {
        if (! ('a' <= text[i] && text[i] <= 'z')) {
            printf("Caractère incorrect ou pas de '#': '%c'\n", text[i]);
            return 0;
        }
        i++;
    }

    i = 0;
    int nVoyelles = 0;
    int nLettres = 0;
    while (i < TEXT_SIZE && text[i] != '#') {
        if ('a' <= text[i] && text[i] <= 'z')
            nLettres++;
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'y')
            nVoyelles++;
        i++;
    }

    printf("%d lettres et %d voyelles\n", i, nVoyelles);

    return 0;
}