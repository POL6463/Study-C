#include <stdio.h>

int main(void)
{
    printf("%d\n", 10);
    printf("%lf\n", 3.4);
    printf("%.1lf\n", 3.45);
    printf("%.10lf\n", 3.4);

    printf("%d과 %d의 합은 %d입니다\n", 10, 20, 10 + 20);
    printf("%.1lf-%.1lf = %.1lf\n", 3.4, 1.2, 3.4 - 1.2);
}