#include <stdio.h>
#include <stdlib.h>
#include "image.h"

int main(void) {
    printf("m1\n");
    tImage img = im_lire("feep.pgm");
    printf("m2\n");
    im_niv_gris(img);
    printf("m3\n");

    
    //mat_afficher(im_niv_gris(img), im_nb_lig(img), im_nb_col(img));

    im_liberer(&img);
    printf("m4\n");
    return 0;
}