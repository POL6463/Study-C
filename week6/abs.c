#include <stdio.h>

int abs(int);

int main(void){

    int n;
    printf("정수: ");
    scanf("%d", &n);

    n = abs(n);

    printf("절대값: %d", n);

    return 0;
}

int abs(int n){
    if(n >= 0){
        return n;
    }
    else return -n;
}