#include <stdio.h>

int main(void)
{
    int counter = 0;
    char var1[80];
    char var2[80];
    int i;

    printf("문장 입력 : ");
    gets(var1);

    for (i = 0; i < 80; i++)
    {
        if (var1[i] >= 'A' && var1[i] <= 'Z')
        {
            var2[i] = (var1[i] + 32);
            counter++;
        }
        else
        {
            var2[i] = var1[i];
        }
        
    }
    printf("바뀐 문장 : %s\n", var2);
    printf("바뀐 문자 수 : %d\n", counter);

    return 0;
}