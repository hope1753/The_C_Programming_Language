#include <stdio.h>

void strcpy_c(char *s, char *t) {
    while (*s != '\0' && *s != '\n' && *s != EOF) {
        *t++ = *s++;
    }
    *t = '\0';
}

int main() {
    char s1[] = "Hello my name is Heewon.";
    char s2[100];
    
    strcpy_c(s1, s2);
    printf("s1 : %s\ns2 : %s", s1, s2);

    return 0;
}