#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <unistd.h>
#define timeStep 20
#define BILLION 1000000000L

typedef struct priorityQueue* queuePointer; // 탐색 및 저장을 위한 노드 포인터 선언
typedef struct queueHead* headPointer; // 헤드 포인터 선언

int turnAroundTime = 0; // 프로세스를 완료하는데 걸린 시간
int fcfsPriority = 0; // // FCFS 기준 우선순위 (들어오는 순서대로 +1)

struct priorityQueue { // 노드 구조체
    int fcfsPriority; // FCFS 기준 우선순위
    int priority; // 기존 우선순위
    int processId; // 프로세스 id
    int computingTime; // 처리시간
    queuePointer link; // 다음 노드를 가리키는 링크
};

struct queueHead { // 헤드를 가리키는 링크 구조체
    queuePointer headLink; // 헤드를 가리키는 링크
};
// Priority에 따른 3개 Queue 선언 및 초기화
headPointer queue; // 순서대로 들어오는 프로세스들을 저장할 선형 큐

// 초기화 함수
void initialize_queue(void) {
    queue = (headPointer)malloc(sizeof(struct queueHead)); // 큐에 동적할당
    queue->headLink = NULL; // 메모리 할당 후 가리키는 노드는 없음
}

int insert_queue(char type, int processId, int priority, int computingTime) {
    queuePointer pointer, node; // 탐색을 위한 pointer 노드와 새로 들어온 프로세스 데이터 저장을 위한 node 노드 선언
    node = (queuePointer)malloc(sizeof(struct priorityQueue)); // 새로 들어온 프로세스 데이터 저장을 위해 node에 동적할당

    node->priority = priority; // 기존 우선순위 저장
    node->fcfsPriority = fcfsPriority; // FCFS 기준 우선순위 저장
    node->link = NULL; // 가리키는 노드는 없음
    node->processId = processId; // 프로세스 아이디 저장
    node->computingTime = computingTime; // 실행시간 저장

    pointer = queue->headLink; // 탐색할 pointer에 선형 큐가 가리키는 노드 링크를 줌 -> pointer가 헤드노드를 가리킴

    if (queue->headLink == NULL) { // 노드가 한 개도 없는 경우
        queue->headLink = node; // 헤더는 새로운 노드를 가리킴 (1순위 당첨)
        return 0;
    }

    for (pointer = queue->headLink; pointer != NULL; pointer = pointer->link) { // 처음 노드부터 마지막 노드까지 탐색
        if (pointer->fcfsPriority <= fcfsPriority && pointer->link == NULL) { // FCFS 우선순위가 낮고 가리키는 노드가 없는 경우 -> 늦게 들어오면 우선순위가 낮음
            pointer->link = node; // 아무것도 가리키고 있지 않은 포인터 링크가 새로 들어온 프로세스를 가리키도록 함
            node->link = NULL; // 새로 들어온 프로세스가 가리키는 노드는 없음
        }
    }

    fcfsPriority++; // FCFS는 들어온 순서대로 우선순위가 높으므로, 하나씩 증가시켜 우선순위를 낮춤
    return 0;
}

// FCFS는 시간할당량이 없으므로 스케줄링 함수가 필요 없음
// 출력 함수
void print_queue(void) {
    queuePointer pointer; // 탐색을 위한 pointer 노드 선언
    for (pointer = queue->headLink; pointer != NULL; pointer = pointer->link) { // 처음 노드부터 마지막 노드까지 탐색
        turnAroundTime += pointer->computingTime; // 프로세스를 완료하는데 걸리는 시간 계산 == 대기시간 + 실행시간
        if (pointer->priority < 0) { // 기존 우선순위가 음수면 작으면 실시간 프로세스
            printf("%-15d %-15s %-15d %-15d %-15d\n", pointer->processId, "Real Time", pointer->priority, pointer->computingTime, turnAroundTime);
        }
        else { // 기존 우선순위가 양수면 일반 프로세스
            printf("%-15d %-15s %-15d %-15d %-15d\n", pointer->processId, "Queue", pointer->priority, pointer->computingTime, turnAroundTime);
        }
        queue->headLink = pointer->link; // 출력한 프로세스는 지우기
        if (pointer->link == NULL) // 끝까지 갔으면
            return; // 출력 끝
    }
}

int main() {
    struct timespec start, stop;
    double accum;
    FILE* inputFile = fopen("input.txt", "r"); // input 파일 읽기
    int type = 0; // 스위치 사용을 위해 타입 초기화
    int processId; // 프로세스 아이디
    int priority; // 기존 우선순위
    int computingTime; // 실행시간
    clock_gettime(CLOCK_MONOTONIC, &start);


    initialize_queue(); // 먼저 초기화

    printf("%-15s %-15s %-15s %-15s %-15s\n","Process Id","Type","Priority", "Computing Time","Turn around time"); // 출력시 맨 위에 띄울 헤더

    while (type != -1) {
        fscanf(inputFile, "%d %d %d %d", &type, &processId, &priority, &computingTime); // 파일에서 한 줄씩 입력 받기

        switch (type) { // 타입을 기준으로 메소드 변경
        case 0: // 타입이 0이면 프로세스 생성
            insert_queue(type, processId, priority, computingTime); // 삽입 함수로 프로세스 삽입
            break;
        case 1: // 타입이 1이면 스케줄 함수
            break; // 그러나 FCFS는 비선점 알고리즘이므로 스케줄이 필요없음
        case -1: // 타입이 -1인 경우 모든 프로세스 입력 완료
            print_queue(); // 실행 완료된 프로세스 출력
            break;
        }
    }
    fclose(inputFile); // 파일 닫기
    //showList(head, fwp); //마지막으로 메모리에 있는 숫자들 출력
    clock_gettime(CLOCK_MONOTONIC, &stop);
    accum = (stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec) / (double)BILLION;
    printf("time = %.9f\n", accum);
    return 0;
}