#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100


#define PI 3.14159265358979323846

double variables[26];

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