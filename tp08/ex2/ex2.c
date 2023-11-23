#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
#include "image.h"

int main(void) {
    tImage img = im_lire("feep.pgm");
    
    mat_afficher(im_niv_gris(img), im_nb_lig(img), im_nb_col(img));

    im_liberer(&img);
    return 0;
}