#include <stdio.h>

double power (double x, int n)
{
    if(n==0) return 1;
    else if ((n%2)==0)
        return power(x*x, n/2);
    else return x*power(x*x, (n-1)/2);
}

int main(void) {
    int res;
    int i, j;
    scanf("%d%d", &i, &j);
    res = power(i, j);

    printf("%d", res);
    return 0;
}