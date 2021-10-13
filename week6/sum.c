#include <stdio.h>

int sum(int);

int main(void){
    int n;
    printf("정수: ");
    scanf("%d", &n);

    printf("%d", sum(n));

    return 0;
}

int sum(int n){
    if(n == 1){
        return 1;
    }
    else{
        return sum(n-1)+n;
    }
}