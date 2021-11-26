#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char * animals[20] = {0}; //최대 20개의 주소를 저장할 배열
    char temp[80]; //입력받은값 임시로 저장할 변수 선언
    int i;
    char enter[5] = "\0"; //엔터만 쳤을경우를 알기위해 선언

    for(i = 0; i < 20; i++){
        printf("input: ");
        gets(temp);//입력받은값 임시로 저장
        
        animals[i] = (char *)malloc(strlen(temp) + 1); //저장되어있는 문장의 크기 + 1만큼 공간 할당
        strcpy(animals[i], temp);//할당받은 공간안에 복사
        if(strcmp(temp, enter)==0){ //만악 들어온값이 엔터뿐이면 중단
            break;
        }
    }

    for(i = 0; i < 20; i++){
        if(strcmp(animals[i], enter)==0){ //만약 엔터만있는부분오면 중단
            break;
        }
        printf("%s\n", animals[i]); //순차적으로 출력
    }

    return 0;

}