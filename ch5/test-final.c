#include <stdio.h>

int main(void)
{
    int a, b;
    char operator;
    int res;


    printf("사칙연산 입력(정수) : ");
    scanf("%d%c%d", &a, &operator, &b);

    if (operator == '+')
    {
        res = a + b;
    }
    else if (operator == '-')
    {
        res = a - b;
    }
    else if (operator == '*')
    {
        res = a * b;
    }
    else if (operator == '/')
    {
        res = a / b;
    }
    
    printf("%d%c%d = %d\n", a, operator, b, res);

    return 0;

}