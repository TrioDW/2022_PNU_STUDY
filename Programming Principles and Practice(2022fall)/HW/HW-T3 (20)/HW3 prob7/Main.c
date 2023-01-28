#include <stdio.h> 

int main(void) {
	int n1,n2,j,i;

	for (j=0; j<3; j=j+1) {
		n1 = 3 - j;
		n2 = 1 + j;
		for(i=0;i<n1;i=i+1) printf(".");
			for(i=0;i<n2;i=i+1) printf("*");
				printf("\n");
	}
	return 0;
}