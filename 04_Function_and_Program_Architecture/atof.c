#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

double atof(char s[]) { // if inserted 1.2
    double val, power;

    int i, sign;

    for (i = 0; isspace(s[i]); i++);

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-') {
        i++;    
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0'); //vAL = 1.0
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] -'0'); // power = 10 val = 12
        power *= 10.0;
    }

    return sign * val / power; // sign = 1 val = 12 power = 10 12 / 10 = 1.2 return 1.2
}

int getline(char line[], int max) {
    char c;
    int i;
    for (i = 0; i < max && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line ='\0';

    return i;
}

int main() {
    double sum, atof(char[]);
    char line[MAXLINE];
    
    
    sum = 0;

    while (getline(line, MAXLINE) > 0) {
        printf("%s", line);
        printf("\t%g\n", sum += atof(line));
    }

    return 0;
}