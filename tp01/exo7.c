#include <stdio.h>

int main(void) {
    unsigned char n;
    printf("n = ");
    scanf("%hhu", &n);

    unsigned char nsqr = n*n;
    printf("%hhu^2 = %hhu\n", n, nsqr);
    return 0;
}
