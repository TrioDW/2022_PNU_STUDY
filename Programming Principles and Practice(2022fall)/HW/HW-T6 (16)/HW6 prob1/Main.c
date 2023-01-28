#include <stdio.h> 

int main(void) {
	unsigned int b, e, i;
	unsigned int x, y, sum=0;

	scanf("%d%d", &b, &e);
	scanf("%d%d", &x, &y);
	
	for (int i = b; i < e + 1; i++) {
		if (i % x == 0 || i % y == 0) {
			printf("%d ", i);
			sum += i;
		}
	}
	printf("\nsum == %d\n", sum);
	return 0;
}
