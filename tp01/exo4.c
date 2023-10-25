#include <stdio.h>
#include <math.h>

int main(void) {
    double x;
    printf("Entre un réel : ");
    scanf("%lf", &x);
    
    printf("sqrt(%lf) = %lf\n", x, sqrt(x));

    return 0;
}
