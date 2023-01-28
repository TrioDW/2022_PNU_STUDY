#include <stdio.h>

int main(void) {
	int nF, nC;

	printf("Enter Fahrenheit temperature: ");
	scanf("%d", &nF);

	nC = (5.0 / 9.0) * (nF - 32);

	printf("%d degrees Fahrenheit is %d degrees Celsius.\n", nF, nC);

	return 0;
}
