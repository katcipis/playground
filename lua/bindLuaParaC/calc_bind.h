#ifndef CALC_H
#define CALC_H

#include <stdio.h>
#include <stdlib.h>
#include <lua.h>

typedef struct _Calc Calc;

Calc* calc_new(int a, int b);

int calc_sum(Calc *c);
int calc_sub(Calc *c);
int calc_mul(Calc *c);
int calc_div(Calc *c);
void calc_destroy(Calc* c);

#endif /* CALC_H */
