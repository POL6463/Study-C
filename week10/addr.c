#include <stdio.h>
#include <string.h>

int main(void){
    char city[100] = {0};
    char district[100] = {0};

    printf("도시: ");
    scanf("%s", city);
    printf("구: ");
    scanf("%s", district);

    strcat(city, " ");
    strcat(city, district);
    printf("%s", city);

    return 0;
}