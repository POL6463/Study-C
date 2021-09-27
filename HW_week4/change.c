#include <stdio.h>

int main(void) {
    int cost, pay, exc;
    int big = 0;
    int mid = 0;
    int small = 0;
    

    printf("음료값: ");
    scanf("%d", &cost);
    printf("지불액: ");
    scanf("%d", &pay);
    exc = pay - cost;

    while (exc >= 500)
    {
        big++;
        exc -= 500;
    }
    while (exc >= 100)
    {
        mid++;
        exc -= 100;
    }
    while (exc >= 50)
    {
        small++;
        exc -= 50;
    }
    
    printf("500원 동전: %d 개\n100원 동전: %d 개\n50원 동전: %d 개\n", big, mid, small);

    return 0;
    
}