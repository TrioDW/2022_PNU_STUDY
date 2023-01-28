#include <stdio.h>

int main(void) {
	int a;

	a = 15;
	printf("%d\n", a);

	for (int i = 0; i < 5; i++) {
		a = a - (a % 3 + 1);
		printf("%d\n", a);
	}

	return 0;
}