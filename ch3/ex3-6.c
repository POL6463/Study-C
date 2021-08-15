#include <stdio.h>
#include <string.h>

int main(void)
{
    char fruit[20] = "strawberry";

    printf("딸기 : %s\n", fruit);
    strcpy(fruit, "banana");
    printf("딸기쩀 : %s %s\n", fruit, "jam");

    return 0;
}