#include <stdio.h> 

int main(void)
{
	int n;

	scanf("%d", &n);
	if (n % 2 == 0 & n % 3 == 0)
		printf("a multiple of 6.\n");
	if (n % 2 != 0 | n % 3 != 0) 
		printf("not a multiple of 6.\n");
	
	return 0;
}