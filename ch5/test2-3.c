#include <stdio.h>

int main(void)
{
    int age = 25, chest = 100;
    char size;
    if (age < 20)
    {
        if (chest < 85)
        {
            size = 'S';
        }
        else if(85 <= chest && chest < 95)
        {
            size = 'M';
        }
        else if(chest >= 95)
        {
            size = 'L';
        }
    }
    else
    {
        if (chest < 90)
        {
            size = 'S';
        }
        else if(90 <= chest && chest < 100)
        {
            size = 'M';
        }
        else if(chest >= 100)
        {
            size = 'L';
        }
    }
    printf("사이즈는 %c 입니다.\n", size);

    return 0;
    
}