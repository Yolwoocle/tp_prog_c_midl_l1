#include <stdio.h>
#include <math.h>
#include "image.h"

/*
    Cette fonction doit créer une image qui est le résultat de la rotation de 90° 
    de l’image `im`. Cette fonction retourne la nouvelle image ou `NULL` en cas de 
    problème.
*/
tImage rotation(tImage im) {
    tImage nv_img = im_allouer(im_nb_col(im), im_nb_lig(im));
    if (nv_img == NULL)
        return NULL;

    for (int ilig = 0; ilig < im_nb_lig(im); ilig++) {
        for (int icol = 0; icol < im_nb_col(im); icol++) {
            im_niv_gris(nv_img)[icol][ilig] = im_niv_gris(im)[ilig][im_nb_col(im)-1 - icol];
        }
    } 

    return nv_img;
}

/*
    Le résultat de `appliquer_table` est une autre image dont le niveau de gris 
    de chaque pixel est fonction du niveau de gris du pixel situé au même endroit 
    dans l’image initiale.
    Les niveaux de gris étant des entiers compris entre 0 et 255, cette transformation 
    peut être complètement décrite par une « table de transcodage » qui est représentée 
    par un tableau de 256 valeurs de type `unsigned char`. 
    L’indice de chaque case de cette table indique l’ancien niveau de gris et son contenu 
    indique le nouveau niveau de gris. Par exemple, si la case d’indice 112 contient la 
    valeur 184, cela signifie que tous les pixels dont le niveau de gris dans l’image
    initiale était égal à 112 vont avoir le niveau de gris 184 dans l’image finale.
    Pour obtenir l’image résultat, il suffit donc de parcourir l’image initiale et, 
    pour chaque pixel, mettre dans l’image finale le niveau de gris contenu dans la 
    case de la table de transcodage dont l’indice est égal au niveau de gris de l’image 
    initiale.
    L’effet visuel obtenu dépendra des valeurs contenues dans la table de transcodage. 
    Par exemple, si elle est représentée par le tableau `table` et si `table[0]==255`, 
    `table[1]==254`, `table[2]==253`, ..., `Table[254]==1`, `Table[255]==0`, c’est-à-dire 
    si `table[g]==255-g`, alors l’image finale sera le « négatif » (au sens de la 
    photographie) de l’image initiale.
    La fonction `appliquer_table` prend en entrée la table de transcodage `table` et 
    l’image initiale `im`. Elle crée et retourne l’image finale.
*/
tImage appliquer_table(unsigned char table[256], tImage im) {
    tImage nv_img = im_allouer(im_nb_lig(im), im_nb_col(im));
    if (nv_img == NULL)
        return NULL;

    for (int ilig = 0; ilig < im_nb_lig(im); ilig++) {
        for (int icol = 0; icol < im_nb_col(im); icol++) {
            int val = im_niv_gris(im)[ilig][icol];
            im_niv_gris(nv_img)[ilig][icol] = table[val];
        }
    } 

    return nv_img;
}

/*
    Cette fonction remplit le tableau `table` pour créer la table de transcodage correspondant 
    à la transformation d’inversion des niveaux de gris (obtention du négatif) :
    ```
        F(g) = 255 − g
    ```
    où g désigne l’ancien niveau de gris et F(g) le nouveau niveau de gris.
*/
void remplir_table_inversion(unsigned char table[256]) {
    for (int i = 0; i < 256; i++) {
        table[i] = 255-i;
    }
}

/*
    Cette fonction crée la table de transcodage correspondant à la transformation appelé « correction
    gamma » :
    ```
        F(g) = [255 * (g/255)^γ]
    ```
    où [x] désigne l’entier le plus proche de x. Si γ = 1 alors la transformation sera sans effet. Si γ < 1
    alors l’image finale sera plus claire que l’image initiale (généralement, on choisit γ ∈ [0.4, 0.5]).
    Si γ > 1 alors l’image finale sera plus sombre que l’image initiale (généralement, on choisit
    γ ∈ [2, 2.5]).
*/
void remplir_table_gamma(double gamma, unsigned char table[256]) {
    for (int i = 0; i < 256; i++) {
        table[i] = round(255.0 * pow(((double) i) / 255.0, gamma));
    }
}