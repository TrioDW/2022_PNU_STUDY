#include <stdio.h> 

int main(void)
{
	int a[10]={11,22,33,44,55};
	int i, j, n=5;

	scanf("%d", &j);
	if (j < 1 || j > n)
		j = n;

	for (int i = j - 1; i < n; i++) {
		a[i] = a[i+1];
	}

	n -= 1;
	for(i=0;i<n;++i) 
		printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}