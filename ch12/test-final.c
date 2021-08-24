#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80];
    char str2[80];
    char str3[80];
    char temp[80];

    printf("세 단어 입력 : ");
    scanf("%s%s%s", str1, str2, str3);

    if (strcmp(str1, str2) >= 1)
    {
        strcpy(temp, str1);
        strcpy(str1, str2);
        strcpy(str2, temp);
    }
    if (strcmp(str2, str3) >= 1)
    {
        strcpy(temp, str2);
        strcpy(str2, str3);
        strcpy(str3, temp);
    }
    if (strcmp(str1, str2) >= 1)
    {
        strcpy(temp, str1);
        strcpy(str1, str2);
        strcpy(str2, temp);
    }

    printf("%s, %s, %s\n", str1, str2, str3);

    return 0;

}