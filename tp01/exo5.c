#include <stdio.h>

int main(void) {
    int a;
    int b;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    
    int tmp;
    tmp = a;
    a = b;
    b = tmp;

    printf("a = %d, b = %d\n", a, b);
}
