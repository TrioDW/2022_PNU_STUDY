#include <stdio.h>

int main(void) {
	int option = 1;
	
	int	a[10] = {3,7,8,9,2,3,4,6,1,7};
	
	int	i;
	{
		int a2[] = {1,3,5,7,9,1,3,5,7,9};
		int a3[] = {1,3,7,9,9,3,1,7,1,2};
	
		scanf("%d", &option);
		if (option == 2) memcpy(a, a2, sizeof(a));
		else if (option == 3) memcpy(a, a3, sizeof(a));
	}
	for (i = 9; i > -1; i--)
	{
		if (a[i] % 2 == 0)
		{
			printf("Found:a[%d]=%d\n", i, a[i]);
			break;
		}
		if (i == 0)
			printf("No even number\n");
	}


	return 0;
}