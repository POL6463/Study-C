#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define timeStep 20 //주어진 시간 단위인 20만큼을 정의했다.
#define BILLION 1000000000L

typedef struct node_type
{
    int process_id;           //프로세스 id
    int priority;             // priority 중요도
    int computing_time;       //총 사용할 시간
    int time_left;            //남은시간
    int enter_time;           //들어온시간
    struct node_type *before; //이전 노드
    struct node_type *next;   //다음 노드
} node;                       //연결리스트로 쓸 구조체 선언

typedef node *list; //구조체의 주소를 담는 변수 list선언

list insert(list, list, int, int, int, int); //입력받은 프로세스를 적절한 위치에 삽입하는 함수이다.
list searchPlace(list, list, int, int);      // insert를 호출하고 어떤위치에 입력해야하는지 검색하는 함수.
list calculate(list, int, FILE *);           // 만약 1이 들어오면 20이라는 시간을 추가하고 프로세스의 시간을 계산한다. - 끝난 프로세스가 있으면 출력파일에 작성
void finalProcess(list, int, FILE *);        //-1이 들어오면 모든 프로세스가 종료될까지 계산을 진행하면서 출력파일을 작성한다.

int main(void)
{
    struct timespec start, stop; //시간측정을 위해 선언
    double accum;
    clock_gettime(CLOCK_MONOTONIC, &start); //시간 측정 시작

    FILE *fp;                                       //입력파일 주소 변수
    FILE *fwp;                                      //출력파일 주소 변수
    list head = NULL, tail = NULL;                  //앞뒤 구분을 위해 head, tail선언
    int time_loc = 0;                               //현지 시간이 얼마나 지났는지 저장할 변수
    int process_id, priority, computing_time, flag; // 입력파일로부터 받을값 변수 선언

    fp = fopen("input.txt", "r");   //입력 파일 오픈
    fwp = fopen("output.txt", "w"); // 출력 파일 오픈
    fprintf(fwp, "Process_id    priority    computing_time    turn_around time\n");
    while (1)
    {
        fscanf(fp, "%d%d%d%d", &flag, &process_id, &priority, &computing_time); //파일에서 하나 꺼냄

        if (flag == -1)
        { // -1나오면 입력 그만 받기
            break;
        }
        else if (flag == 1)
        {                                          // 1이 나오면
            head = calculate(head, time_loc, fwp); //시간이 20 지난만큼 현재 있는 프로세스들 계산
            time_loc += timeStep;                  //시간 단위만큼 증가
        }
        else if (head == NULL)
        {                                      //큐가 비어있을때의 상황
            head = (list)malloc(sizeof(node)); //처음 들어오는 노드이므로 공간할당받고 Head로 지정
            head->process_id = process_id;
            head->priority = priority;
            head->computing_time = computing_time;
            head->enter_time = time_loc;
            head->time_left = computing_time;
            head->before = NULL;
            head->next = NULL;
            tail = head;
            continue;
        }
        else
        {                                                                              //입력받은값 삽입 위해 insert함수 호출
            tail = insert(head, tail, process_id, priority, computing_time, time_loc); // insert 함수 호출
            if (head->before != NULL)
            { //만약 제일 앞부분으로 삽입되었을때 head 조정
                head = head->before;
            }
        }
    }
    finalProcess(head, time_loc, fwp); //앞으로 프로세스가 더 안들어오므로 남은 프로세스 전부 계산

    clock_gettime(CLOCK_MONOTONIC, &stop);
    accum = (stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec) / (double)BILLION;
    printf("time = %.9f\n", accum);
    return 0;
}

//노드 삽입하는 함수
list insert(list head, list tail, int process_id, int priority, int computing_time, int enter_time)
{

    list temp = NULL;
    list insertPlace = NULL; //삽입할 위치의 다음 노드를 받아오는 변수 초기화

    //받은값으로 공간 할당, 데이터 삽입
    temp = (list)malloc(sizeof(node));
    temp->process_id = process_id;
    temp->priority = priority;
    temp->computing_time = computing_time;
    temp->enter_time = enter_time;
    temp->time_left = computing_time;

    // computing_time을 비교해서 삽입할 위치를 반환하는 searchPlace 함수 호출
    insertPlace = searchPlace(head, tail, computing_time, priority);

    if (insertPlace == head)
    {                        //넣어야 하는곳이 제일 처음이면
        temp->next = head;   //다음을 head였던 노드를 바라보게
        temp->before = NULL; //이제 head 이므로 before는 널
        head->before = temp; //제일 앞에 삽입했으므로 before에 저장
        return tail;
    }
    else if (insertPlace)
    {                                       //만약 리턴값이 null이 아닌 노드의 주소가 반환되었을떄
        temp->next = insertPlace;           //새로운 노드가 next로 삽입할 위치의 노드를 바라보게
        temp->before = insertPlace->before; //사이에 삽입해야 하므로 이전값을 이전 노드의 이전값과 동일하게
        insertPlace->before->next = temp;   //이전노드가 새 노드를 바라보게
        insertPlace->before = temp;         //교환당하는 노드 앞에 새 노드 넣기
        return tail;
    }
    else
    { //제일 마지막으로 넣어야 하면 - tail다음으로 삽입
        temp->before = tail;
        temp->next = NULL;
        tail->next = temp;
        tail = tail->next;
        return tail;
    }

    return tail;
}

//남은시간 비교하고 삽입해야하는 위치의 노드의 주소를 반환해주는 함수
list searchPlace(list head, list tail, int newNodeTime, int newNodePriority)
{

    list temp = head;
    while (temp->next != NULL)
    { //리스트의 끝까지 반복문으로 탐색

        if (temp->time_left > newNodeTime)
        {                //새로 들어오는 노드의 시간이 기존것보다 짧다면
            return temp; //해당 노드의 주소를 반환
        }

        else
        {
            temp = temp->next; //남은 시간이 더 크므로 다음으로 이동
        }
    }

    //제일 마지막 노드와 비교하는 부분
    if (temp->time_left > newNodeTime)
    {                // tail의 시간과 비교
        return temp; // tail앞으로 삽입해야 하는경우
    }
    else
    {
        return NULL; //제일 뒤에 삽입해야 하는경우
    }

    return NULL;
}

list calculate(list head, int time, FILE *fwp)
{
    list temp = head;
    int workTime = timeStep;
    int turn_around_time = 0;
    while (temp != NULL)
    { //시간 20만큼 연산
        if (head->time_left <= workTime)
        {                                                                                                                //만약 남은시간이 20보다 적으면
            time += temp->time_left;                                                                                     //프로그램이 시작하고 진행된 시간 해당 프로세스의 남은 시간만큼 추가                                                                                          //현재 시간 남은만큼 더하고
            turn_around_time = time - temp->enter_time;                                                                  //핸재 프로그램이 진행된 시간에 들어왔을때의 시간을 빼서 turn around time 계산                                                                      //반환시간은 현재시간 - 들어온 시간
            fprintf(fwp, "%2d%16d%16d%16d\n", temp->process_id, temp->priority, temp->computing_time, turn_around_time); //프로세스가 종료되었으므로 출력파일에 작성
            workTime -= temp->time_left;
            if (temp->next == NULL)
            {
                break;
            }
            head = temp->next; //제일 앞 프로세스가 종료되었으므로 Head를 다음으로 이동
            temp = temp->next;
            free(head->before);  //종료된함수 공간 할당 해제
            head->before = NULL; //제일 앞이므로 앞에있는 노드 NULL로 바꾼다.
        }
        else
        {
            temp->time_left -= workTime; //시간이 지나도 프로세스가 끝나지 않았으므로 남은 시간 차감.
            workTime = 0;
            break;
        }
    }
    return head;
}

void finalProcess(list head, int time, FILE *fwp)
{
    int turn_around_time;
    while (head != NULL) //리스트가 빌때까지 진행
    {
        time += head->time_left;                                                                                     //로컬시간 프로세스 하나가 끝날때만큼 증가
        turn_around_time = time - head->enter_time;                                                                  // turn_around_time 계산
        fprintf(fwp, "%2d%16d%16d%16d\n", head->process_id, head->priority, head->computing_time, turn_around_time); //출력 한번 해주고

        head = head->next; // Head 다음으로 이동
    }
}
