#include <stdio.h>

void squeeze (char s[], char c) {
    int j = 0;

    for (int i = 0; s[i] != '\0' && s[i] != '\n' && s[i] != EOF; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

int any(char s1[], char s2[]) {
    for (int i = 0; s1[i] != '\0' && s1[i] != '\n' && s1[i] != EOF; i++) {
        for (int j = 0; s2[j] != '\0' && s2[j] != '\n' && s2[j] != EOF; j++) {
            if (s1[i] == s2[j]) {
                printf("first find character : %c\nlocation : %d\n", s1[i], i);

                return i;
            }
        }
    }
}

int main() {
    char s[14] = "Hello, World!";
    char s2[10] = "aeiou";

    any(s, s2);
    printf("%s\n", s);
    squeeze(s, 'l');
    printf("%s\n", s);

    

    return 0;
}