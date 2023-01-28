#include <stdio.h>

#define msg_same "SAME"
#define msg_different "NOT SAME"

void isTransposeSame(const int n, int mat[n][n]){

	printf("SAME");
}

int main(void){
	/*
		Arrays B, C, and D are hidden on purpose
	*/
	int A[3][3] = {{1,0,2},
				 {0,2,1},
				 {2,1,3}}; // A == A^T
	int B[3][3] = {{1,2,3},
				   {4,5,6},
				   {7,8,9}}; // B != C^T				   
				   
	int C[4][4] = {{1,0,2,1},
				   {0,2,1,3},
				   {2,1,3,0},
				   {1,3,0,4}}; // C == C^T
				   
	int D[5][5] = {{1,0,2,1,1},
				   {0,2,1,1,4},
				   {2,1,3,3,3},
				   {1,1,3,4,4},
				   {1,4,4,4,5}}; // D != D^T

	int n = -1;
	
	printf("Enter the case number to check: ");
	scanf("%d", &n);
	
	switch(n) {
		case 1: isTransposeSame(3, A); break;
		case 2: isTransposeSame(3, B); break;
		case 3: isTransposeSame(4, C); break;
		case 4: isTransposeSame(5, D); break;
		default: isTransposeSame(5, D);
	}
	
	return 0;
}
