#include <stdio.h>
int main(void) {
	int n, n_d, sum=0;		

	// printf("Enter a positive integer\n");
	scanf("%d", &n);
	if (n <= 0) return 1;

	for (n_d=n; n_d > 0; n_d /= 10) {
		sum = sum + (n_d % 10);
	}

	printf("Sum of all digits of %d=%d\n", n, sum);	
	return 0; 
}
