#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
#include "image.h"

tImage im_rotation90(tImage im) {
    tImage nv_img = im_allouer(im_nb_col(im), im_nb_lig(im));

    for (int ilig = 0; ilig < im_nb_lig(im); ilig++) {
        for (int icol = 0; icol < im_nb_col(im); icol++) {
            im_niv_gris(nv_img)[icol][ilig] = im_niv_gris(im)[ilig][im_nb_col(im)-1 - icol];
        }
    } 

    return nv_img;      
}

int main(void) {
    printf("====| START |====\n"); 

    tImage img = im_lire("chien.pgm");
    tImage nv_img = im_rotation90(img);

    im_ecrire(nv_img, "chien_new.pgm");

    im_liberer(&img);
    im_liberer(&nv_img);

    printf("=====| END |=====\n"); 
    return 0;
}
