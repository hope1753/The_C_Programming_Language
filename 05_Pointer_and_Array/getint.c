#include <stdio.h>
#include <ctype.h>

int getint(int *pn) {
    int c, sign;

    while (isspace(c = getc(stdin)));

    if (!isdigit(c) && c != EOF && c != '+' && c !=  '-') {
        ungetc(c, stdin);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c =='-') {
        c = getc(stdin);
    }

    printf("check1 : %d\n", '0');

    for (*pn = 0; isdigit(c); c = getc(stdin)) {
        *pn = 10 * *pn + (c - '0');
    } 

    *pn *= sign;
    printf("check2 : %d\n", c);
    if (c != EOF) {
        ungetc(c, stdin);
    }
    printf("check : %d\n", c);
    return c;
}

int main() {
    int n;
    getint(&n);
    printf("result : %d\n", n);

    return 0;
}