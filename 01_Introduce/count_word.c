#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c== '\n') {
            nl++;
        }
        if (c == ' ' || c == '\n' || c =='\t') {
            nw++;
        } 
    }

    printf("Word : %3d\nNew Line : %3d\nNew Character : %3d", nw, nl, nc);

    return 0;
}