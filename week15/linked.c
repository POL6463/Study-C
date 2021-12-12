#include <stdio.h>
#include <stdlib.h>

typedef struct node_type{
    int data;
    struct node_type *next;
}node;
typedef node *list;
void traverse(list);

int main(void){
    int buf = 0;
    list head = NULL, tail = NULL;

    while (1)
    {
        printf("input data: ");
        scanf("%d", &buf);
        if(buf <= 0){
            break;
        }
        if(head == NULL){
            head = (list)malloc(sizeof(node));
            head->data = buf;
            head->next = NULL;
            tail = head;
        }
        else{
            tail->next = (list)malloc(sizeof(node));
            tail = tail->next;
            tail->data = buf;
            tail->next = NULL;
        }
    }   

    traverse(head);

    return 0;
    
}

void traverse(list head){
    list temp = head;
    if(head == NULL){
        printf("리스트가 비어있습니다\n");
        return;
    }
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}