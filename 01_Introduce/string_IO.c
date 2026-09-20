#include <stdio.h>

//#define EOF 1 수정은 되는데 원래 역할을 잃는 느낌인데

int main() {
    int c;
    
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    
    printf("%d\n", EOF);

    return 0;
}