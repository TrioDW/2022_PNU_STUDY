#include <stdio.h>

int main(void) {
	int n;

	scanf("%d", &n);

	if (n % 3 == 0)
		printf("%d is ",n);		// 3의 배수
	else
		printf("%d is not ",n);		// 3의 배수가 아님
	printf("a multiple of 3\n");
	
	return 0;
}