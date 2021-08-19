#include <stdio.h>

int res_func(int n);

int main(void)
{
    int result;
    int a;
    printf("1부터 n까지 더하기 : ");
    scanf("%d", &a);
    result = res_func(a);

    printf("%d\n", result);
    
    return 0;
}

int res_func(int n)
{
    int res;

    if (n == 1)
    {
        return 1;
    }
    else if (n > 1)
    {
        
        
        res = n + res_func(n - 1);
        printf("%d,  ", res);
        printf("%d\n", n);
    }
    
    

    
    
    return res;
}