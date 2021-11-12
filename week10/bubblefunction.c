#include <stdio.h>
#define COUNT 10

void bubblesort(int *, int);
void swap(int *, int *);

int main()
{
	int score[COUNT];
	int i, j, tmp, tot = 0;
	double avg;

	for (i = 0; i < COUNT; i++) {
		printf("input: ");
		scanf("%d", &score[i]);
		tot += score[i];
	}

    bubblesort(score, COUNT);
	
	printf("\nSorted: ");
	for (i = 0; i < COUNT; i++) {
		printf("%d ", score[i]);
	}
		avg = (double)tot / COUNT;
	printf("\n\n총합: %d, 평균: %.1lf\n", tot, avg);
	return 0;
}

void bubblesort(int *score, int n){
    int i, j;

    for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-1; j++)
			if (score[j]>score[j + 1]) { //swapping
				swap(score+j, score+j+1);
			}
	}

}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
