#include <stdio.h> 
void print_nxn(int n, double M[n][n]); // Function Declaration

/**
* @brief : Calculating the determinant of a square matrix of order n
* @return: the determinant of M
* @param : n - the order of a square matrix M. M - a 2 dimensional array containing values of a matrix M
*/
double determinant(int n, double M[n][n]) {
	double Mk[n-1][n-1], m, ans = 0;

	if (n == 2) {
		return (M[0][0] * M[1][1] - M[1][0] * M[0][1]);
	}
	else {
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0)
				m = M[0][i];
			else if (i % 2 == 1)
				m = -M[0][i];
		
			for (int k = 0; k < n-1; k++) {
				for (int j = 0; j < n-1; j++) {
					if (i <= j)
						Mk[k][j] = M[k+1][j+1];
					else if (i > j)
						Mk[k][j] = M[k+1][j];
				}
			}
		ans += m * determinant(n-1, Mk);
		}
	return ans;
	}
}

int main(void) {
	double M1[3][3] = { {1.7, 3.2, 2.5},
			{2.3, 4.1, 0.7},
			{1.0, 2.0, 3.0} };
	double M2[4][4] = { {2.0, 1.0, 2.0, 1.0},
			{1.7, 3.2, 2.5, 3.0},
			{2.3, 4.1, 0.7, 2.0},
			{1.0, 2.0, 3.0, 4.0} };
	// the values of M3 are hidden on purpose
	double M3[5][5] = { {2.0, 1.0, 2.0, 1.0, 0.0},
			{1.7, 3.2, 2.5, 3.0, 1.0},
			{2.3, 4.1, 0.7, 2.0, 0.0},
			{2.3, 4.1, 0.7, 2.0, 0.0},
			{1.0, 2.0, 3.0, 4.0, 1.0} };
	int option;
	
	scanf("%d",&option);
	
	switch (option) {
		case 1 :
			printf("Matrix M1 = \n");
			print_nxn(3, M1);
			printf("det(M1) = %lf\n", determinant(3, M1));
			break;
		case 2 :
			printf("Matrix M2 = \n");
			print_nxn(4, M2);
			printf("det(M2) = %lf\n", determinant(4, M2));
			break;
		default :
			printf("det(M3) = %lf\n", determinant(5, M3));
			break;
	}

	return 0;
}

// print a Square Matrix M of order n
void print_nxn(int n, double M[n][n]) {
	int row, col;
	for (row=0; row<n; row++) {
		printf("    [ ");
		for (col=0; col<n; col++)
			printf("%6.2lf ", M[row][col]);
		printf("]\n");
	}
}

