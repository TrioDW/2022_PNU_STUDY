#include <stdio.h>

int main(void) {
	float num=123.456;
	int 	n=0;
	float	f=0;
	
	n = num;
	f = num - n;
	
	printf("Integral Part = %d\n", n);
	printf("Fractional Part = %.3f\n", f);

	return 0;
}