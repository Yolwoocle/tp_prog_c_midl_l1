/*
 * >>> Exercice 2 (Conversion de durées)
      L’objectif de cet exercice consiste à écrire deux fonctions permettant de convertir une durée exprimée
    en secondes en la même durée exprimée en heures, minutes et secondes. Par exemple, 3666 secondes
    représentent 1 heure 1 minute et 6 secondes.
      Pour tester vos deux fonctions, écrivez une fonction principale qui demande à l’utilisateur de taper
    une durée en seconde, la lit, appelle chacune des deux fonctions et affiche les résultats. Aucune entrée
    au clavier ni sortie à l’écran ne sera donc réalisée par les fonctions de conversion.
      Les informations en entrée et en sortie des deux fonctions doivent passer par leurs paramètres selon
    le schéma suivant :
      1. la première fonction doit prendre en entrée la durée en secondes et délivrer en sortie le nombre
          d’heures, le nombre de minutes et le nombre de secondes (4 paramètres en tout) ;
      2. la seconde fonction doit prendre en entrée la durée en secondes et délivrer en sortie le résultat
          sous la forme d’un tableau à 3 cases, la première contenant le nombre d’heures, la deuxième le
          nombre de minutes et la troisième le nombre de secondes (2 paramètres en tout).
 */

#include <stdio.h>

void temps(int secs, int* ptr_h, int* ptr_m, int* ptr_s) {
    *ptr_h = secs / 3600;
    *ptr_m = (secs % 3600) / 60;
    *ptr_s = secs % 60;
}

int main2() {
    int h;
    int m;
    int s;
    temps(3663, &h, &m, &s);
    printf("%d h %d m %d s", h, m, s);

    return 0;
}
