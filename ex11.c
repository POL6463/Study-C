#include <stdio.h>

int main(void){
    int num[] = {1, 2, 3, 4, 5};

    printf("%lu", sizeof(num)/sizeof(num[0]));

    return 0;
}