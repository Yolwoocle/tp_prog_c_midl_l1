#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
#include "image.h"
#include "ti.h"

int main(void) {
    tImage img_src = im_lire("paysage.pgm");

    tImage img_rot = rotation(img_src);
    im_ecrire(img_rot, "paysage_rot.pgm");
    
    unsigned char table[256];
    remplir_table_inversion(table);
    tImage img_tab = appliquer_table(table, img_src);
    im_ecrire(img_tab, "paysage_tab.pgm");

    remplir_table_gamma(0.4, table);
    tImage img_gam04 = appliquer_table(table, img_src);
    im_ecrire(img_gam04, "paysage_gamma_04.pgm");
    
    remplir_table_gamma(2.5, table);
    tImage img_gam25 = appliquer_table(table, img_src);
    im_ecrire(img_gam25, "paysage_gamma_25.pgm");

    im_liberer(&img_src);
    im_liberer(&img_gam25);
    im_liberer(&img_gam04);
    im_liberer(&img_rot);
    im_liberer(&img_tab);

    return 0;
}