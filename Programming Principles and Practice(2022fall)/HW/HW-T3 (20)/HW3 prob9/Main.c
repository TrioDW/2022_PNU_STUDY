#include <stdio.h> 

int main(void) {
	int i;			// index
	int ecnt = 0;	// even number count
	int a[10] = {3,7,8,9,2,3,4,6,1,7};
	{// This block is added for automatic scoring. 
		int option;
		int a2[] = {1,3,5,7,9,1,3,5,7,9};
		int a3[] = {1,3,7,9,9,3,1,7,1,2};
	
		scanf("%d", &option);
		if (option == 2) memcpy(a, a2, sizeof(a));
		else if (option == 3) memcpy(a, a3, sizeof(a));
	}

	for(i = 0; i < 10 ; i = i+1) {
		if (a[i] % 2 == 0)
			ecnt += 1;
		

	}
	printf("There are %d even numbers in a[10]\n", ecnt);

	return 0;
}