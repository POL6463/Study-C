#include <stdio.h>
#include <string.h>

int arr[1000][1000] = {0};
void readFileName(int *, int *, char *);

int main(void){
    FILE *fp;
    char name[100]; //파일 이름 저장하는 배열
    char compName[100] = "map-input-";
    int row, column;

    printf("파일 이름을 입력하세요: ");
    scanf("%s", name); //파일 이름 입력

    if (strncmp(compName, name, 10) == 0){  //파일 이름 앞부분 비교
        printf("%s\n", name);
    }
    else{
        printf("Error: Unable to open file %s", name); //앞부분 형식과 다를 시 프로그램 종료
        return 0;
    }

    return 0;
}

void readFileName(int *row, int *column, char *arr){
    
}