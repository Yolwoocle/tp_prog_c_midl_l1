#include <stdio.h>

int main(void) {
    int money;
    printf("Money ?????? :°))))) ");
    scanf("%d", &money);
    
    if (money == 52) {
        printf("quoicoubeh :)\n");
        return 1;
        
    }
    printf("20€ : %d\n", money / 20);
    printf("1€ :  %d\n", money % 20);
    
    return 0;
}
