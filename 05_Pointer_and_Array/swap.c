#include <stdio.h>

void swap(int* x, int* y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
} 
int main() {
    int x, y;
    x = 5;
    y = 2;
    swap (&x, &y);

    printf("x = %d, y = %d\n", x ,y);

    return 0;
}