#include <stdio.h>

int main(void)
{
    char *dessert = "apple";

    printf("오늘 후식은 %s 입니다.\n", dessert);
    dessert = "banana";
    printf("내일의 후식은 %s 입니다.\n", dessert);

    return 0;
}