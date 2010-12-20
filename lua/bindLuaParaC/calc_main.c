#include <stdio.h>
#include "calc_bind.h"

int main(int argc, const char *argv[]) {
    int result;
    int a, b;

    Calc *calc = NULL;
    
    if (argc < 3) {
        printf("Use: %s [a] [b]\n", argv[0]);
        return 0;
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    calc = calc_new(a, b);

    if (!calc) {
        printf("Error creating first calc !!\n");
        return 0;
    }
    result = calc_sum(calc);
    printf("%i + %i = %i\n", a, b, result);
    result = calc_sub(calc);
    printf("%i - %i = %i\n", a, b, result);
    result = calc_mul(calc);
    printf("%i * %i = %i\n", a, b, result);
    result = calc_div(calc);
    printf("%i / %i = %i\n", a, b, result);
    
    calc_destroy(calc);

    calc = calc_new(b, a);
    if (!calc) {
        printf("Error creating second calc !!\n");
        return 0;
    }

    result = calc_sum(calc);
    printf("%i + %i = %i\n", b, a, result);
    result = calc_sub(calc);
    printf("%i - %i = %i\n", b, a, result);
    result = calc_mul(calc);
    printf("%i * %i = %i\n", b, a, result);
    result = calc_div(calc);
    printf("%i / %i = %i\n", b, a, result);

    calc_destroy(calc);
    return 0;
}
