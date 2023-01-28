#include <stdio.h>
// Convert/Return a temperature in fahrenheit into one in celsius. 
double Fahrenheit2Celsius(int nF) {
	
	
	double nC = 5 * ((double)nF - 32) / 9;

	return nC;
}
int main(void) {
	int nF = 20;
	
	puts("[Loop with while]\n");

	while (nF <= 100) {
		printf("%3d.0(F) == %4.1f(C)\n", nF, Fahrenheit2Celsius(nF));	
		
		nF += 5;
	}
	
	puts("\n\n[Loop with for]\n");
	
	nF = 20;
	

	for (int i = 0; i < 17; i++) {
		printf("%3d.0(F) == %4.1f(C)\n", nF, Fahrenheit2Celsius(nF));	
		nF += 5;
	}
	
	return 0;
}