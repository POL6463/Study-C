#include <stdio.h>
#include <stdlib.h>

typedef struct node_type{
    int data;
    struct node_type *next;
}node;

typedef node *list;

int searchList(list, int);
void insert(list, list, int, int);
void showList(list);


int main(void){
    FILE *fp;
    list head, tail;
    int dat, count = 0, hit = 0;
    int nums;

    fp = fopen("input.txt", "r");

    while(1){

        fscanf(fp, "%d", &dat);
        if(dat == 99){
            break;
        }

        nums = searchList(head, dat);
        if(nums == 5){
            hit++;
        }else if(nums == 0){
            head = (list)malloc(sizeof(node));
            head->data = dat;
            head->next = NULL;
            tail = head;
        }else{
            insert(head, tail, dat, nums);
        }

        

        count++;
    }

    showList(head);
   
    return 0;

}

int searchList(list head, int dat){
    list temp = head;
    int count = 0;


    if(head == NULL){
        return 0;
    }
    else{

        while(temp != NULL){

            if(temp->data == dat){
                return 5;
            }
            else{
                count++;
                return count;
            }
            temp = temp->next;
        }
    }
    return 0;
}

void insert(list head, list tail, int dat, int nums){
    list temp;
    if(nums == 4){
        temp = (list)malloc(sizeof(node));
        temp->next = NULL;
        tail->next = temp;
        tail = tail->next;
        head = head->next;
        
    }
    else{
        temp = (list)malloc(sizeof(node));
        temp->next = NULL;
        tail->next = temp;
        tail = tail->next;
    }

}

void showList(list head){
    list temp = head;
    while(temp != NULL){
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}