#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrice.h"
#include "image.h"

struct sImage
{
    int nb_lig; // Nombre de lignes de l ’ image
    int nb_col; // Nombre de colonnes de l ’ image
    tMatrice niv_gris; // Matrice des niveaux de gris de l ’ image
};

tImage im_allouer(int nb_lignes, int nb_colonnes) {
    tImage image = malloc(sizeof(struct sImage));
    
    image->nb_lig = nb_lignes;
    image->nb_col = nb_colonnes;
    tMatrice mat = mat_allouer(nb_lignes, nb_colonnes);
    image->niv_gris = mat;

    return image;
}

void im_liberer(tImage *pIm) {
    tImage im = *pIm;
    mat_liberer(&(im->niv_gris));
    free(*pIm);
    *pIm = NULL;
}

int im_nb_lig(tImage im) {
    return im->nb_lig;
}

int im_nb_col(tImage im) {
    return im->nb_col;
}

tMatrice im_niv_gris(tImage im) {
    return im->niv_gris;
}

/*
Retourne le nombre de colonnes de l’image `im`.
*/
tImage im_lire(char nom_fichier[]) {
    FILE * pfile = fopen(nom_fichier, "rt");
    if (pfile == NULL) {
        printf("Fichier invalide\n");
        perror(nom_fichier);
        return NULL;
    }
    char format[3];
    fscanf(pfile, "%s", format);
    
    int w, h;
    fscanf(pfile, "%d", &w);
    fscanf(pfile, "%d", &h); 

    tImage img = im_allouer(h, w);

    int max_val;
    fscanf(pfile, "%d", &max_val);
    
    for (int ilig = 0; ilig < h; ilig++) {
        for (int icol = 0; icol < w; icol++) {
            int val; 
            fscanf(pfile, "%d", &val);
            img->niv_gris[ilig][icol] = round(255.0 * ((double) val) / ((double) max_val));
        }
    }

    fclose(pfile);
    return img;
}

/*
    Écrit l’image `Im` dans le fichier de nom `NomFichier` au format `pgm-ascii`. La valeur du
niveau de gris maximal à écrire est 255.
*/
// void im_ecrire(tImage im, char nom_fichier[]) {
    
// }
