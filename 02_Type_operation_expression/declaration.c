#include <stdio.h>

int a;

int main() {
    char esc = '\\';
    int i;

    printf("%d\n", a); // local variable이 아닌 값은 0으로 초기화
    printf("%d", i); // local variable은 초기값이 들어감..

    return 0;
}