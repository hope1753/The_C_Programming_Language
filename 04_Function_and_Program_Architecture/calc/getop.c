#include "calc.h"
#include <string.h>
#include <ctype.h>
#define BUFSIZE 100

int bufp = 0;
char buf[BUFSIZE];

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar(); // 2 3 +
}
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch : too many character\n");
    }
    else {
        buf[bufp++] = c;
    }
}

void ungets(char s[]) {
    int i = strlen(s);

    while (i > 0) {
        ungetch(s[--i]);
    }
}

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');

    s[1] = '\0';

    if (c >= 'a' && c <= 'z') {
        return VARIABLE;
    }

    if (!isdigit(c) && c != '.' && c != '-' ) {
        return c;
    }
    
    i = 0;
    if (c == '-') {
        if (isdigit(s[++i] = c = getch())) {
            while (isdigit(s[++i] = c = getch()));
        }
        else {
            return c;
        }    
    }
    else {
        if (isdigit(c)) {
            while (isdigit(s[++i] = c = getch()));
        }
        if (c == '.') {
            while (isdigit(s[++i] = c = getch()));
        }

        if (c != EOF) {
            ungetch(c);
        }
    }
    
    
    return NUMBER;
}