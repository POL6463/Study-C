#include <stdio.h>

int arr[1000][1000] = {0};

int main(void){
    FILE *fp;
    char name[100]; //파일 이름 저장하는 배열
    int row, column;

    printf("파일 이름을 입력하세요: ");
    scanf("%s", name); //파일 이름 입력
    printf("%s\n", name);

    return 0;
}