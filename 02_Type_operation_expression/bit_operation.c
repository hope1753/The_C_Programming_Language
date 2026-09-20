#include <stdio.h>

#define SET_ON 1

int main() {
    // && || ^ << >> ~
    int x = 0;
    
    x = x | SET_ON;

    printf("%d\n", x);
    x = x << 3;
    printf("%d\n", x);
    x = x ^ 15;
    // 1000 0001
    printf("%d\n", x);
    x = ~x; 
    printf("%d\n", x);
    return 0;
}