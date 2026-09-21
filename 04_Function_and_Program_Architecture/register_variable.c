#include <stdio.h>

int main() {
    register int x = 2;
    register int y = 5;

    printf("x + y = %d\n", x + y);
    return 0;
}