#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getline() {
    char c;
    int i;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if (c== '\n') {
        line[i] = c;
        i++;
    }

    return i;
}

void copy() {
    int i = 0;
    while ((longest[i] = line[i]) != '\0') {
        i++;
    }
}

int main() {
    int len;
    extern int max;
    max = 0;
    while ((len = getline()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
        if(max > 0) {
            printf("%s", longest);
        }
    }

    return 0;
}