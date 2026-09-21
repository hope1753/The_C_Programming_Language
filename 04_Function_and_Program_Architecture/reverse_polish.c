#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define PI 3.14159265358979323846
#define VARIABLE 'a'

int sp = 0;
double val[MAXVAL];
int bufp = 0;
char buf[BUFSIZE];
double variables[26];

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

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    }
    else {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    }
    else {
        printf("error : stack empty.\n");

        return 0.0;
    }
}

int main() {
    int type;
    double op2;
    char s[MAXOP];
    char var;
    int var_code = -1;

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER: 
                push(atof(s));
                break;
            case VARIABLE:
                var_code = s[0] - 'a';
                push(variables[var_code]);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                    push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                }
                else {
                    printf("error : zero divisor\n");
                }
                break;
            case '*':
                push(pop() * pop());
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    push(fmod(pop(), op2));
                    break;
                }
                else {
                    printf("error : zero modulus.\n");
                    break;
                }
            case 'S':
                push(sin(pop() * (PI / 180)));
                break;
            case 'E':
                push(exp(pop()));
                break;
            case 'P':
                op2 = pop();
                if (fmod(op2, 1) == 0) {
                    push(pow(pop(), op2));
                }
                else {
                    printf("error : pow error\n");
                }
                break;
            case '\n':
                printf("\t%.4g\n", pop());
                break;
            case 'r':
                printf("%.3f\n", val[sp - 1]);
                break;
            case '=':
                pop();
                op2 = pop();
                variables[var_code] = op2;
                push(variables[var_code]);
                break;
            default:
                printf("error : unknown command %s\n", s);
                break;
        }
        
    }

    return 0;
}