#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int arr[1000][1000] = {0}; //처음 데이터를 저장할 2차원 배열
struct RGB{ //RGB 값을 저장할 구조체 정의
    int red;
    int green;
    int blue;
};
struct RGB list[1000][1000] = {0}; //RGB 값을 저장할 구조체 배열 선언
void readFileName(int *, int *, char *); //파일 이름을 입력받고 검사, row colum값을 받는 함수
void findMaxMin(int *, int *, int, int); //배열에서 최대 최솟값 찾아내는 함수
void loadGrayscale(int, int, int, int); //배열에서 rgb값으로 변환 후 구조체 배열에 입력하는 함수
void findPath(int, int, int);//최단 경로를 찾아가면서 빨간색칠할 함수
void outputImage(char *, int, int); //ppm파일 작성하는 함수
int findMin(int, int, int);//findPath에서 최솟값을 구해주는 함수

int main(void){
    FILE *fp;
    char name[100]; //파일 이름 저장하는 배열
    int row = 0, column = 0;
    int i, j;
    int max, min;

    readFileName(&row, &column, name); //파일 이름을 읽고 행, 열 읽는 함수

    fp = fopen(name, "r");
    
    if(fp == NULL){ //파일이 없을 시 에러 반환후 종료
        printf("Error : Unable to open file %s", name);
        exit(1);
    }

    for(i = 0; i < row; i++){ //파일의 데이터를 순차적으로 이중배열에 입력
        for(j = 0; j < column; j++){
            if(feof(fp)){
                printf("Error : End of file reached prior to getting all the required data\n"); //데이터의 수가 부족하면 에러 반환 후 종료
                exit(1);
            }
            if(fscanf(fp, "%d", &arr[i][j]) == 0){ //정수형이 아니면 오류 반환후 종료
                printf("Error : Read a non-integer value");
                exit(1);
            }
        }
    }

    if(fscanf(fp, "%d", &arr[i][j]) == 1){ //아직 파일에 데이터가 남아있는지 확인 후 남아있으면 에러 발생
        printf("Error : Too many data points\n");
        exit(1);
    }

    findMaxMin(&max, &min, row, column); //최대 최솟값 알아내는 함수 호출, max, min을 변경시켜야해서 참조에의한 호출

    loadGrayscale(max, min, row, column); //RGB값으로 변환해 입력하는 함수 호출

    for(i = 0; i < row; i++){//row 0부터 끝까지 재귀함수 호출
        findPath(i, 0, column);//경로찾는 함수 호출
    }
    
    outputImage(name, row, column); //파일 작성하는 함수 호출


    return 0;
}




void readFileName(int *row, int *column, char *name){
    int i, temp;
    char compName[100] = "map-input-"; //입력받은 파일 앞부분 확인하는 배열
    int firstNum[100] = {0}; //첫번째 숫자 잠시 보관할 배열
    int firstNumCounter = 0; //첫번째 숫자 자릿수 저장할 변수
    int secondNum[100] = {0}; //두번째 숫자 보관할 배열
    int secondNumCounter = 0; //두번째 숫자 자릿수 저장할 변수

    printf("파일 이름을 입력하세요: ");
    scanf("%s", name); //파일 이름 입력받아서 name 저장해 main에서도 자용할 수 있게 함

    if (strncmp(compName, name, 10) == 0){  //파일 이름 앞부분 비교
    }
    else{
        printf("Error: Unable to open file %s", name); //앞부분 형식과 다를 시 프로그램 종료
        exit(1);
    }

    for(int i = 0; name[10 + i] != '-'; i++){
        if(name[10 + i] < '0' || name[10 + i] > '9'){
            printf("Error: Problem reading in rows and columns"); //숫자 부분이 숫자가 아닌 문자가 들어오면 에러 발생
            exit(1);
        }
        firstNum[i] = name[10 + i] - '0';
        firstNumCounter++;
    }//10번째 자리부터 '-'가 나올때 까지 읽고 숫자를 배열에 저장

    temp = 0; 
    for(i = firstNumCounter -1; i >= 0; i--){
        *column += firstNum[temp++] * pow(10, i);
    } //앞부분 숫자 배열에 저장한걸 row 변수에 입력


    for(i = 0; name[11+firstNumCounter+i] != '.'; i++){// '.'점이 나올때까지 읽고 secondNum 배열에 저장
        if(name[11 + firstNumCounter + i] < '0' || name[11 + firstNumCounter + i] > '9'){
            printf("Error: Problem reading in rows and columns"); //숫자 부분이 숫자가 아닌 문자가 들어오면 에러 발생
            exit(1);
        }
        secondNum[i] = name[11+firstNumCounter+i] - '0';
        secondNumCounter++;
    }

    temp = 0;
    for(i = secondNumCounter -1; i >= 0; i--){
        *row += secondNum[temp++] * pow(10, i);
    } //secondNum에 있는 숫자를 column에 저장
}

void findMaxMin(int *max, int *min, int column, int row){ //최대 최솟값 알아내는 함수
    int i, j;
    *max = arr[0][0]; //제일 처음값으로 최대 최솟값 초기화
    *min = arr[0][0];

    for(i = 0; i < column; i++){ //for 루프로 최대 최소 검색하기
        for(j = 0; j < row; j++){
            if(arr[i][j] > *max){
                *max = arr[i][j];
            }
            if(arr[i][j] < *min){
                *min = arr[i][j];
            }
        }
    }
    
}

void loadGrayscale(int max, int min, int column, int row){
    int i, j;
    double gray = 0;
    int grayscale = 0;

    for(i = 0; i < column; i++){
        for(j = 0; j < row; j++){
            gray = ((arr[i][j] - min)/(double)(max-min)) * 255; //shade of gray 공식을 적용해 gray 변수에 입력
            grayscale = round(gray); //실수형이여서 반올림하여 grayscale에 대입
            list[i][j].red = grayscale; //rgb값 배열에 입력
            list[i][j].green = grayscale;
            list[i][j].blue = grayscale;
        }
    }
}

void findPath(int row, int column, int MaxColumn){//재귀함수 시작
    int first, second, third, min;//최솟값을 찾기 위해서 column+1값들 저장할 변수 선언
    
    if(column == MaxColumn){//재귀함수 마지막까지 도달했으면 색칠하고 리턴
        list[row][column].red = 252;
        list[row][column].green = 25;
        list[row][column].blue = 63;
        
        return;
    }
    else{
        first = abs(arr[row][column] - arr[row-1][column+1]);//다음 칼럼값들 현재칼럼에 뺀 값을 절댓값으로 저장
        second = abs(arr[row][column] - arr[row][column+1]);
        third = abs(arr[row][column] - arr[row+1][column+1]);

        list[row][column].red = 252;//우선 색칠하기
        list[row][column].green = 25;
        list[row][column].blue = 63;

        min = findMin(first, second, third);//최솟값 찾아내주는 함수
        
        findPath(row+min, column+1, MaxColumn);//최솟값 리턴값이 -1. 0, 1로 설정했기에 다음 경로 찾기 호출
        return;
    }

}

int findMin(int a, int b, int c){//최솟값 찾는 함수
    if(a < b && a < c){//a값이 같지않고 최소면 -1리턴
        return -1;
    }
    else if(b <= a && b <= c){//b가 같거나 제일 작으면 0 리턴
        return 0;
    }
    else if(c <= a && c < b){//c가 a와 같거나 제일 작을경우 1 리턴
        return 1;
    }
}

void outputImage(char *name, int column, int row){
    FILE *wfp; //파일 포인터 변수 선언
    int i, j;
    char file[20] = ".ppm";
    strcat(name, file); //파일 이름 뒤에 ppm 붙이기

    wfp = fopen(name, "w"); //파일 write로 생성

    fprintf(wfp, "P3\n"); //첫번째줄 작성
    fprintf(wfp, "%d %d\n", row, column); //두번째 줄 row column 입력
    fprintf(wfp, "255\n");
    for(i = 0; i < column; i++){ //띄어쓰기를 간격으로 RGB값 입력
        for(j = 0; j < row; j++){
            fprintf(wfp, "%d %d %d ", list[i][j].red, list[i][j].green, list[i][j].blue);
        }
    }
    fclose(wfp);
}