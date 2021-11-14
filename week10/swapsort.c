#include <stdio.h>
#define COUNT 10

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

	for (i = 0; i < COUNT-1; i++) {
		for (j = 0; j < COUNT-1; j++)
			if (score[j]>score[j + 1]) { //swapping
				swap(score+j, score+j+1);
			}
	}
	printf("\nSorted: ");
	for (i = 0; i < COUNT; i++) {
		printf("%d ", score[i]);
	}
		avg = (double)tot / COUNT;
	printf("\n\n총합: %d, 평균: %.1lf\n", tot, avg);
	return 0;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
	
}