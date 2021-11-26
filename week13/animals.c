#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char * animals[20] = {0};
    char temp[80];
    int i;
    char enter[5] = "\0";

    for(i = 0; i < 20; i++){
        printf("input: ");
        gets(temp);
        
        animals[i] = (char *)malloc(strlen(temp) + 1);
        strcpy(animals[i], temp);
        if(strcmp(temp, enter)==0){
            break;
        }
    }

    for(i = 0; i < 20; i++){
        if(strcmp(animals[i], enter)==0){
            break;
        }
        printf("%s\n", animals[i]);
    }

    return 0;

}