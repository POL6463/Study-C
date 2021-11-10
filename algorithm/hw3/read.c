#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int arr[1000][1000] = {0};
void readFileName(int *, int *, char *);

int main(void){
    FILE *fp;
    char name[100]; //파일 이름 저장하는 배열
    int row = 0, column = 0;

    readFileName(&row, &column, name); //파일 이름을 읽고 행, 열 읽는 함수



    printf("%d\n", row);

    return 0;
}

void readFileName(int *row, int *column, char *arr){
    int i, temp;
    char compName[100] = "map-input-";
    int firstNum[100] = {0};
    int firstNumCounter = 0;
    int secondNum[100] = {0};
    int secondNumCounter = 0;

    printf("파일 이름을 입력하세요: ");
    scanf("%s", arr);

    if (strncmp(compName, arr, 10) == 0){  //파일 이름 앞부분 비교
        printf("%s\n", arr);
    }
    else{
        printf("Error: Unable to open file %s", arr); //앞부분 형식과 다를 시 프로그램 종료
        exit(1);
    }

    for(int i = 0; arr[10 + i] != '-'; i++){
        printf("%c", arr[10 + i]);
        firstNum[i] = arr[10 + i] - '0';
        firstNumCounter++;
    }
    printf("\n");

    temp = 0;
    for(i = firstNumCounter -1; i >= 0; i--){
        *row += firstNum[temp++] * pow(10, i);
    }

    printf("\n");
    for(int i = 0; arr[i] != 0 ;i++){
        printf("%c", arr[i]);
    }
    printf("\n");



}