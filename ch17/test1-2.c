#include <stdio.h>

struct cracker{
    int price;
    int cal;
};

int main(void)
{
    struct cracker c1;
    printf("바사삭의 가격과 열량을 입력하세요 : ");
    scanf("%d%d", &c1.price, &c1.cal);
    
    printf("바사삭의 가격 : %d\n", c1.price);
    printf("바사삭의 열량 : %d\n", c1.cal);

    return 0;
}