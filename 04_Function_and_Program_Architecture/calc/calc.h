#ifndef CALC_H
#define CALC_H

#include <stdio.h>
#define NUMBER '0'
#define VARIABLE 'a'
#define MAXVAL 100

extern double val[MAXVAL];
extern int sp;

int getop(char s[]);
void push(double f);
double pop(void);


#endif