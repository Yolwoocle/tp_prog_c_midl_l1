#include <stdio.h>

int main(void) {
    printf("Entrez une année : ");
    int annee;
    scanf("%d", &annee);

    // Une année est bissextile si son expression numérale 
    // est divisible par 4 mais pas par 100, ou si elle 
    // est divisible par 400
    
    if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0) {
        printf("oui\n");
    } else {
        printf("non\n");
    }

    return 0;
}