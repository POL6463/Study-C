#include <stdio.h>

void is369(int);

int main(void){
    int num;

    printf("양의 정수: ");
    scanf("%d", &num);

    is369(num);

    return 0;
}

void is369(int num){
    int i, j, count, temp;

    for(i = 1; i <=num; i++){
        temp = i;
        while (temp != 0)
        {
            if(temp % 10 != 0 && ((temp%10) % 3 == 0)){
                break;
            }
            temp = temp/10;
            if(temp == 0){
                printf("%d ", i);
                count++;
                if(count % 5 == 0){
                    printf("\n");
                }
            }
        }
    }
}