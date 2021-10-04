#include <stdio.h>

int findsum(int);

int main(void){
    int num, x;
    printf("\nEnter a number: ");
    scanf("%d", &num);
    x = findsum(num);
    printf("Sum of the digits of %d is: %d", num, x);
    return 0;
}

int findsum(int num){
    int x, one;
    if (num == 0)
    {
        return 0;
    }
    else{
        one = num % 10;
        num /= 10;
        x = findsum(num);
        return (one + x);
    }
    
}