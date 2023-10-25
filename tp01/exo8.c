#include <stdio.h>

int main(void) {
    int n = 5;
    double min;
    double max;
    double k;
        
    printf("Entrez un nombre : ");    
    scanf("%lf", &k);
    min = k;
    max = k;
    for (int i = 1; i < n; i++) {
        printf("Entrez un nombre : ");
        scanf("%lf", &k);
        if (k < min)
            min = k;
        if (k > max)
            max = k;
    }
    
    printf("min = %lf\n", min);
    printf("max = %lf\n", max);

    return 0;
}
