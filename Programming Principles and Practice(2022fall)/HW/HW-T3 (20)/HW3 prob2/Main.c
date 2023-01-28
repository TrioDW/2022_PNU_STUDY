#include <stdio.h>

int main(void) {
	int n;

	scanf("%d", &n);

	if (n % 2 != 0)
		printf("%d is odd\n",n);		// 홀수
	else
		printf("%d is even\n",n);		// 짝수
	
	return 0;
}