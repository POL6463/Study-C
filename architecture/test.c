#include <stdio.h>
#include <stdlib.h>

typedef struct node_type{
    int data;
    struct node_type *next;
}node;

typedef node *list;

int searchList(list, int);
list insert(list, list, int, int);
void showList(list);


int main(void){
    FILE *fp;
    list head = NULL, tail = NULL;
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
        }
        else if(nums == 0){
            head = (list)malloc(sizeof(node));
            head->data = dat;
            head->next = NULL;
            tail = head;
        }
        else{
            tail = insert(head, tail, dat, nums);
            if(nums == 4){
                head = head->next;
            }
        }

        showList(head);
        printf("dat : %d\n", dat);


        count++;
    }

    showList(head);

    printf("적중률 = %d/%d\n", hit, count);
   
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