#include <stdio.h>
#include <stdlib.h>
#define timeStep 20

typedef struct node_type{
    int process_id;
    int priority;
    int computing_time;
    int enter_time;
    struct node_type *before;
    struct node_type *next;
}node; //연결리스트로 쓸 구조체 선언

typedef node *list; //구조체의 주소를 담는 변수 list선언

int searchList(list, int);
list insert(list, list, int, int, int, int);
void showList(list);
list searchPlace(list, list, int, int);


int main(void){
    FILE *fp; //파일 주소 변수
    list head = NULL, tail = NULL; //앞뒤 구분을 위해 head, tail선언
    int time = 0;
    int totalNode = 0;//현재 연결리스트가 몇개 연결되어있는지
    int process_id, priority, computing_time, flag;

    fp = fopen("input.txt", "r"); //파일오픈

    while(1){

        fscanf(fp, "%d%d%d%d", &flag, &process_id, &priority, &computing_time); //파일에서 하나 꺼냄

        if(flag == -1){// -1나오면 입력 그만 받기
            break;
        }else if(flag == 1){//1이 나오면
            time += timeStep; //시간 단위만큼 증가
            continue;
        }else if(head == NULL){//큐가 비어있을때의 상황
            head = (list)malloc(sizeof(node));
            head->process_id = process_id;
            head->priority = priority;
            head->computing_time = computing_time;
            head->enter_time = time;
            head->before = NULL;
            head->next = NULL;
            tail = head;
            continue;
        }else{//입력받은값 삽입 위해 insert함수 호출
            tail = insert(head, tail, process_id, priority, computing_time, time);
            if(head->before != NULL){ //만약 제일 앞부분으로 삽입되었을때 head 조정
                head = head->before;
            }


        }

        

    }

    showList(head); //마지막으로 메모리에 있는 숫자들 출력

   
    return 0;

}

//노드 삽입하는 함수
list insert(list head, list tail, int process_id, int priority, int computing_time, int enter_time){

    list temp = NULL;
    list insertPlace = NULL;//삽입할 위치의 다음 노드를 받아오는 변수 초기화

    //받은값으로 공간 할당, 데이터 삽입
    temp = (list)malloc(sizeof(node)); 
    temp->process_id = process_id;
    temp->priority = priority;
    temp->computing_time = computing_time;
    temp->enter_time = enter_time;
    
    //computing_time을 비교해서 삽입할 위치를 반환하는 searchPlace 함수 호출
    insertPlace = searchPlace(head, tail, computing_time, priority);

    if(insertPlace == head){ //넣어야 하는곳이 제일 처음이면
        temp->next = head; //다음을 head였던 노드를 바라보게
        temp->before = NULL; //이제 head 이므로 before는 널
        head->before = temp;//제일 앞에 삽입했으므로 before에 저장
        return tail;
    }
    else if(insertPlace){//만약 리턴값이 null이 아닌 노드의 주소가 반환되었을떄
        temp->next = insertPlace; //새로운 노드가 next로 삽입할 위치의 노드를 바라보게
        temp->before = insertPlace->before; //사이에 삽입해야 하므로 이전값을 이전 노드의 이전값과 동일하게
        insertPlace->before->next = temp; //이전노드가 새 노드를 바라보게
        insertPlace->before = temp; //교환당하는 노드 앞에 새 노드 넣기
        return tail;
    }else{ //제일 마지막으로 넣어야 하면 - tail다음으로 삽입
        temp->before = tail;
        temp->next = NULL;
        tail->next = temp;
        tail = tail->next;
        return tail;
    }

    return tail;
}

//남은시간 비교하고 삽입해야하는 위치의 노드의 주소를 반환해주는 함수
list searchPlace(list head, list tail, int newNodeTime, int newNodePriority){
    
    list temp = head;
    while(temp->next != NULL){ //리스트의 끝까지 반복문으로 탐색

        if(temp->computing_time > newNodeTime){//새로 들어오는 노드의 시간이 기존것보다 짧다면
            return temp; //해당 노드의 주소를 반환
        }
        else if(temp->computing_time == newNodeTime){//만약 남은시간이 같다면?
            if(temp->priority < newNodePriority){ //priority를 비교해서 새 노드가 더 크다면 앞으로 배치
                return temp;
            }
            else{
                temp = temp->next; //아니라면 다음노드와 비교
            }
            temp = temp->next;
        }else{
            temp = temp->next; //남은 시간이 더 크므로 다음으로 이동
            
        }
    }

    //제일 마지막 노드와 비교하는 부분
    if(temp->computing_time > newNodeTime){//tail의 시간과 비교
        return temp; //tail앞으로 삽입해야 하는경우
    }else{
        return NULL; //제일 뒤에 삽입해야 하는경우
    }

    return NULL;

}

void showList(list head){
    list temp = head;
    while(temp != NULL){
        printf("%d  ", temp->computing_time);
        
        temp = temp->next;
    }

    printf("\n");
    temp = head;
    while(temp != NULL){
        printf("%d  ", temp->enter_time);
        temp = temp->next;
    }
}