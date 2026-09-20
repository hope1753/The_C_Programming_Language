#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getline() {
    char c;
    int i;

    for (i = 0; i < MAXLINE - 1; i++) {
        if ((c = getchar()) != EOF) {
            if (c != '\n') {
                line[i] = c;            
            }
            else {
                break;
            }
        }
        else {
            break;
        }
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

//관계연산자를 사용하지않고 getline을 구현 예제 2-2