#include <stdio.h>
#define CONST 0.17

int main(void) {
	float earth = 65;
	float moon = earth * CONST;
	
	printf("%f kg on the Earth - %f kg on the Moon", earth, moon);
	
	return 0;
}