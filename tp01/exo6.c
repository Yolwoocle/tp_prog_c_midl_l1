#include <stdio.h>

int main(void) {
    int f;
    printf("Température en F° : ");
    scanf("%d", &f);
    
    int c = (5 * (f - 32)) / 9;
    printf("%d °F = %d °C\n", f, c);
    
    return 0;
}
