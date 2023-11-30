#ifndef TI_H
#define TI_H 

#include <stdio.h>
#include <stdlib.h>
#include "image.h"

tImage rotation(tImage im);
tImage appliquer_table(unsigned char table[256], tImage im);
void remplir_table_inversion(unsigned char table[256]);
void remplir_table_gamma(double gamma, unsigned char table[256]);

#endif