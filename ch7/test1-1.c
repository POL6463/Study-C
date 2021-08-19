#include <stdio.h>

double average(double a, double b);

double res;
int main(void)
{
    res = average(1.5, 3.4);
    printf("%lf", res);
    return 0;
}


double average(double a, double b)
{
    double temp;
    temp = a + b;
    return(temp / 2.0);
}