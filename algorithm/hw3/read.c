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
    int i, j;

    readFileName(&row, &column, name); //파일 이름을 읽고 행, 열 읽는 함수

    fp = fopen(name, "r");
    
    if(fp == NULL){ //파일이 없을 시 에러 반환후 종료
        printf("Error : Unable to open file %s", name);
        exit(1);
    }

    for(i = 0; i < column; i++){
        for(j = 0; j < row; j++){
            if(EOF == fscanf(fp, "%d", &arr[i][j])){
                printf("Error : End of file reached prior to getting all the required data\n");
                exit(1);
            }
        }
    }

    if(EOF != fgetc(fp)){
        printf("Error : Too many data points\n");
        exit(1);
    }

    

    for(i = 0; i < column; i++){
        for(j = 0; j < row; j++){
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
    




    return 0;
}




void readFileName(int *row, int *column, char *arr){
    int i, temp;
    char compName[100] = "map-input-"; //입력받은 파일 앞부분 확인하는 배열
    int firstNum[100] = {0}; //첫번째 숫자 잠시 보관할 배열
    int firstNumCounter = 0; //첫번째 숫자 자릿수 저장할 변수
    int secondNum[100] = {0}; //두번째 숫자 보관할 배열
    int secondNumCounter = 0; //두번째 숫자 자릿수 저장할 변수

    printf("파일 이름을 입력하세요: ");
    scanf("%s", arr); //파일 이름 입력받아서 arr로 저장해 main에서도 자용할 수 있게 함

    if (strncmp(compName, arr, 10) == 0){  //파일 이름 앞부분 비교
    }
    else{
        printf("Error: Unable to open file %s", arr); //앞부분 형식과 다를 시 프로그램 종료
        exit(1);
    }

    for(int i = 0; arr[10 + i] != '-'; i++){
        if(arr[10 + i] < '0' || arr[10 + i] > '9'){
            printf("Error: Problem reading in rows and columns"); //숫자 부분이 숫자가 아닌 문자가 들어오면 에러 발생
            exit(1);
        }
        firstNum[i] = arr[10 + i] - '0';
        firstNumCounter++;
    }//10번째 자리부터 '-'가 나올때 까지 읽고 숫자를 배열에 저장

    temp = 0; 
    for(i = firstNumCounter -1; i >= 0; i--){
        *row += firstNum[temp++] * pow(10, i);
    } //앞부분 숫자 배열에 저장한걸 row 변수에 입력


    for(i = 0; arr[11+firstNumCounter+i] != '.'; i++){// '.'점이 나올때까지 읽고 secondNum 배열에 저장
        if(arr[11 + firstNumCounter + i] < '0' || arr[11 + firstNumCounter + i] > '9'){
            printf("Error: Problem reading in rows and columns"); //숫자 부분이 숫자가 아닌 문자가 들어오면 에러 발생
            exit(1);
        }
        secondNum[i] = arr[11+firstNumCounter+i] - '0';
        secondNumCounter++;
    }

    temp = 0;
    for(i = secondNumCounter -1; i >= 0; i--){
        *column += secondNum[temp++] * pow(10, i);
    } //secondNum에 있는 숫자를 column에 저장
}