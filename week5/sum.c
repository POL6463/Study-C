#include <stdio.h>

int main(void) {
    int i, sum;

    while (1)
    {
        printf("input: ");
        scanf("%d", &i);
        if(i <= 0) break;

        sum += i;
        printf("sum = %d\n", sum);
    }
    printf("current sum = %d\n", sum);

    return 0;
    
    
    
}