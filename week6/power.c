# include <stdio.h>

int power(int, int);

int main(void){
    int x, y, res;
    printf("두 정수값 입력: ");
    scanf("%d%d", &x, &y);

    res = power(x, y);
    printf("%d의 %d승은 %d입니다.\n", x, y, res);
    return 0;
}

int power(int x, int y){
    int res = 1, i;

    for(i = 0; i < y; i++){
        res *= x;
    }

    return res;
    
}