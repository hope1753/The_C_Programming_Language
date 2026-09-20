#include <stdio.h>

#define MAXLINE 1000

char pattern[] = "ould";

int getline(char s[], int lim) {
    char c;
    int i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c== '\n') {
        s[i] = c;
        i++;
    }

    return i;
}

int strindex(char source[], char searchfor[]) {
    int i, j, k;

    for (i = 0; source[i] != '\0'; i++) {
        for (j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++);
        if (k > 0 && searchfor[k] == '\0') {
            return i;
        }
    }

    return -1;
}

int main() {
    char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s\n", line);
            found++;
        }
    }

    return found;
}