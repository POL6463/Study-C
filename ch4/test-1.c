#include <stdio.h>

int main(void)
{
    double a = 4.0, b = 1.2;

    printf("%.1lf + %.1lf = %.1lf\n", a, b, a+b);
    printf("%.1lf - %.1lf = %.1lf\n", a, b, a-b);
    printf("%.1lf * %.1lf = %.1lf\n", a, b, a*b);
    printf("%.1lf / %.1lf = %.1lf\n", a, b, a/b);

    return 0;
}