#include <stdio.h>

int main(void){
    int a = 20, b = 21;
    scanf("%d", &a);
    scanf("%d", &b);
    int c = a; a = b; b = c;
    printf("%d, %d", a, b);
    return 0;
}
