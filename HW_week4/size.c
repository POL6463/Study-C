#include <stdio.h>

int main(void){
    int age;
    int size;

    printf("나이: ");
    scanf("%d", &age);
    printf("가슴둘레: ");
    scanf("%d", &size);

    if (age < 20)
    {
        if(size < 85){
            printf("S(small)\n");
        }
        else if(size < 95){
            printf("M(medium)\n");
        }
        else{
            printf("L(large)\n");
        }
    }
    else if(age >= 20)
    {
        if(size < 90){
            printf("S(small)\n");
        }
        else if(size < 100){
            printf("M(medium)\n");
        }
        else{
            printf("L(large)\n");
        }
    }

    return 0;
    
}