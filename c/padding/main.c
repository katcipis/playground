#include <stdio.h>

typedef struct{
    char a;
    char b;
    char c;
} no_padding;

typedef struct{
    char a;
    short b;
    char c;
} padding_array;

int main(int argc, char **argv) {
    printf("no_padding: size type: %i\n", sizeof(no_padding));
    no_padding two_no_padding[2];
    printf("no_padding: address: %p\n", &two_no_padding);
    printf("no_padding: size array: %i\n", sizeof(two_no_padding));

    printf("sizeof short: %i\n", sizeof(short));
    printf("padding_array: size type: %i\n", sizeof(padding_array));
    padding_array two_padding_array[2];
    printf("padding_array: address: %p\n", &two_padding_array);
    printf("padding_array: size array: %i\n", sizeof(two_padding_array));
    return 0;
}
