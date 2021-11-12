#include <stdio.h>
#include <string.h>

int main(void){
    char str1[80] = "banana";
    char str2[80] = "apple";
    char temp[80] = {0};
    char *ps1 = "cat";
    char *ps2 = "dog";
    char *ps3;

    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);

    ps3 = ps1;
    ps1 = ps2;
    ps2 = ps3;

    printf("str1: %s, str2: %s\n", str1, str2);
    printf("ps1: %s, ps2: %s\n", ps1, ps2);

    return 0;
}