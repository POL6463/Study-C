#include <stdio.h>
#include <stdlib.h>

typedef struct node_type{
    int data;
    struct node_type *next;
}node; //연결리스트로 쓸 구조체 선언

typedef node *list; //구조체의 주소를 담는 변수 list선언

int searchList(list, int);
list insert(list, list, int, int);
void showList(list);


int main(void){
    FILE *fp; //파일 주소 변수
    list head = NULL, tail = NULL; //앞뒤 구분을 위해 head, tail선언
    int dat, count = 0, hit = 0;//dat = 데이터값, count = 총 몇개의 데이터가 들어왔는지, hit = hit하면 증가
    int nums;//현재 연결리스트가 몇개 연결되어있는지

    fp = fopen("input.txt", "r"); //파일오픈

    while(1){

        fscanf(fp, "%d", &dat); //파일에서 하나 꺼냄
        if(dat == 99){// 99나오면 종료
            break;
        }

        nums = searchList(head, dat); //hit인지 아닌지 search하는 함수, 리스트에 몇개들어있는지 반환
        
        if(nums == 5){
            hit++;// num이 5이면 hit이기에 힛 증가
        }
        else if(nums == 0){//첫번째로 들어왔으면 공간 만들어주고 헤드로 지정
            head = (list)malloc(sizeof(node));
            head->data = dat;
            head->next = NULL;
            tail = head;
        }
        else{
            tail = insert(head, tail, dat, nums);//나머지 들어왔을경우 insert 함수 호출
            if(nums == 4){
                head = head->next;//만약 4개있는상태에서 hit이아닌데이터가 들어왔을때 제일 앞의 head 하나 줄임
            }
        }

        //showList(head); //마지막으로 메모리에 있는 숫자들 출력
        //printf("dat : %d\n", dat); 


        count++;
    }

    showList(head); //마지막으로 메모리에 있는 숫자들 출력

    printf("적중률 = %d/%d\n", hit, count); //적중률 출력
   
    return 0;

}

int searchList(list head, int dat){
    list temp;
    int count = 0;


    if(head == NULL){
        return 0;
    }
    else{
        temp = head;
        while(temp != NULL){

            if(temp->data == dat){
                return 5;
            }
            else{
                count++;
            }

            temp = temp->next;
        }
    }
    return count;
}

list insert(list head, list tail, int dat, int nums){
    list temp = NULL;

    temp = (list)malloc(sizeof(node));
    temp->data = dat;
    temp->next = NULL;
    tail->next = temp;
    tail = tail->next;
    return tail;


}

void showList(list head){
    list temp = head;
    while(temp != NULL){
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}