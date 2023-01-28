#include <stdio.h> 

int main(void) {
	int i,j;
	int n1,n2,n3;

	for(j=0; j<10 ; j=j+1) {
		n1 = 9 - j;
		n2 = 1 + 3*j/2;
		n3 = 9 - j/2;
		for(i=0;i<n1;i=i+1) printf(". ");
		for(i=0;i<n2;i=i+1) printf("* ");
		for(i=0;i<n3;i=i+1) printf(". ");
		printf("\n");
	}
	for(j=0; j<9 ; j=j+1) {
		n1 = 2 * (j+1);
		n2 = 13 - j*2 + j/2;
		n3 = 4 - j/2;
		for(i=0;i<n1;i=i+1) printf(". ");
		for(i=0;i<n2;i=i+1) printf("* ");
		for(i=0;i<n3;i=i+1) printf(". ");
		printf("\n");
	}
	return 0;
}