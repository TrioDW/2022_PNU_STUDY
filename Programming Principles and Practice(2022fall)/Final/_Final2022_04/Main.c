#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define NSIZE	10
#define INT_MAX 2147483647

void print_int_array(int *p_na, int n) 
{
	int *pcur = p_na;
	while (pcur < p_na+n-1)
		printf("%d, ", *pcur++);
	printf("%d\n", *pcur);
}

void sort_int_array(int *p_na, int n) {
	
	int* temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i- 1; j++) {
			if (p_na[j] > p_na[j+1]) {
				temp = p_na[j];
				p_na[j] = p_na[j+1];
				p_na[j+1] = temp;
			}
		}
	}
}

int main(void)
{
	int na[NSIZE];
	for(int k = 0; k < NSIZE; k++){
		scanf("%d", na+k);
	}
	
	printf("Before sorting:\n");
	print_int_array(na, NSIZE);
	sort_int_array(na, NSIZE);
	printf("After sorting:\n");
	print_int_array(na, NSIZE);

	return 0;
}
