#include <stdio.h>

int strlen(char *s) {
    int n;

    for (n = 0; *s != '\0' && *s != EOF && *s != '\n'; s++) {
        n++;
    }

    return n;
}

int main() {
    char s = "Hello, World!";

    printf("len : %d\n", strlen(s));

    return 0;
}