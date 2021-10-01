#include <stdio.h>

int main(void) {

    int i, j, k;

    for(i = 5; i > 0; i--){
        for(k = 0; k < 5-i; k++){
            printf(" ");
        }
        for(j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}