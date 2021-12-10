#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *input;
    FILE *output;
    char name[20];
    double eng = 0.0, kor = 0.0, math = 0.0;

    input = fopen("score.txt", "r");
    if(input == NULL){
        printf("IN 파일 열기에러\n");
        exit(1);
    }
    output = fopen("total.txt", "w");
    if(output == NULL){
        printf("OUT 파일 열기 에러\n");
        exit(1);
    }

    while(1){
        fscanf(input, "%s%lf%lf%lf", name, &eng, &kor, &math);
        fprintf(output, "%s  %10.1lf\n", name, eng+kor+math);
        if(feof(input)){
            break;
        }
    }

    if(fclose(input)){
        puts("파일닫기에러");
        exit(1);
    }
    if(fclose(output)){
        puts("파일 닫기 에러");
        exit(1);
    }
    
    return 0;
}