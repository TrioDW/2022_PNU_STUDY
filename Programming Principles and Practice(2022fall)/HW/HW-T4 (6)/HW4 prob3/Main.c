#include <stdio.h>

// Put function arguments
void line(int n1, int n2, int n3, int n4) {

	int i;

	for(i=0; i<n1; i=i+1) printf(". ");  
	for(i=0; i<n2; i=i+1) printf("* ");  
	for(i=0; i<n3; i=i+1) printf(". ");  
	for(i=0; i<n4; i=i+1) printf("* ");  
	printf("\n");
}

int main(void) {
	int j;

	for(j=0; j<10; j=j+1)
	{
		int n1 = 9 - j;
		int n2 = 1 + 2*j;
		int n3 = 9 - j;
		int n4 = 0;

		line(n1, n2, n3, n4);
	}
	for(j=0; j<9; j=j+1)
{
	int n1 = 0;
	int n2 = 1 + j;
	int n3 = 17 - 2*j;
	int n4 = 1 + j;
	line(n1, n2, n3, n4);
}
	return 0;
}