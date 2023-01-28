#include <stdio.h>

#define INT_BITS 32

void print_binary(unsigned int n) {
	char bin[32] = {0, };

	for (int i = 0; n != 0; i++) {
		bin[i] = n % 2;
		n /= 2;
	}

	for (int i = 31; i >= 0; i--)
		printf("%d", bin[i]);
}

int main(void) {
	unsigned int num;
	
	scanf("%d", &num);
	print_binary(num);
	
	return 0;
}
