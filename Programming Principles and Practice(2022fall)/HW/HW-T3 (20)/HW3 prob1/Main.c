#include <stdio.h>

int main(void) {
	int nPulseRate;

	printf("Input pulse rate: ");
	scanf("%d", &nPulseRate);

	if (nPulseRate >= 60 & nPulseRate <= 90)
		printf("Normal pulse rate\n");		// 정상 혈압
	else
		printf("Abnormal pulse rate\n");	// 비정상 혈압
	
	return 0;
}