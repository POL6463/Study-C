#include <stdio.h>
#include <math.h>

int main(void) {
    int i, k;
    int j;
    int num = 1;
    i = 1;
    for(k = 0; k < 31; k++){
        i*= 2;
    }
    j = i -1;

    printf("2의 31승 - 1\n");
    printf("%d\n", j);
    printf("%o\n", j);
    printf("%X\n", j);

    printf("2의 31승\n");
    printf("%u\n", i);
    printf("%o\n", i);
    printf("%X\n", i);

    return 0;
}