#include <stdio.h>
#include <string.h>

void swap_ptr(char **, char **);

int main(void){
    char *dogs[] = {"poodle", "maltese", "shitzu", "chihuahua", "pomeranian", "mixed", "dachshund", "shepherd"};
    int i, j;
    int size = sizeof(dogs)/sizeof(char *);

    printf("%s\n", dogs[0]);
    printf("%d\n", strcmp(dogs[0], dogs[1]));

    for(i = 0; i < size -1; i++){
        for(j = 0; j < size -1; j++){
            if(strcmp(dogs[j], dogs[j+1]) > 0){
                swap_ptr(dogs+j, dogs+j+1);
            }
        }
    }
    
    for(i = 0; i < size; i++){
        printf("%s\n", dogs[i]);
    
    }

    return 0;
}

void swap_ptr(char **a, char **b){
    char* temp;
    temp = *a;
    *a = *b;
    *b = temp;
}