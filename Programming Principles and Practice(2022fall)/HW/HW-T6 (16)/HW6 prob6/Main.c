#include <stdio.h>
/**
* @brief : Get the minimum number of cells to repaint from the given m*n board to make a 8*8 chess board 
* @return: The minimum number of cells to repaint from the given m*n board (>=0)
         : return -1 if m < 8 or n < 8.
* @param : m - # of rows, n - # of columns, 
           board - consists of m*n cells, board[i][j] == 0(painted in black)/1(painted in white)
*/
int min_num_cell_to_repaint(int m, int n, int board[m][n]) {
	int a = 0, b = 0, i = 0, j = 0, k = 0;
	int num[1001] = {0}, num2[1001] = {0}, num_a = 0, num_b = 0;

	while (a + 8 <= m) {
		for(i = a; i < a + 8; i++) {
			for(j = b; j < b + 8; j++) {
				if ((j+i) % 2 == 0 && board[i][j] != 1)
					num_a += 1;
				if ((j+i) % 2 == 1 && board[i][j] != 0)
					num_a += 1;
				if ((j+i) % 2 == 0 && board[i][j] != 0)
					num_b += 1;
				if ((j+i) % 2 == 1 && board[i][j] != 1)
					num_b += 1;
			}
		}
		b++;
		
		if (b + 8 > n) {
			a++;
			b = 0;
		}
		
		num[k] = num_a;
		num2[k] = num_b;
		k++;
		num_a = 0;
		num_b = 0;
	}

	int min = m * n, min2 = m * n;

	for (int i = 0; num[i] != 0; i++) {
		if (num2[i] < min2)
			min2 = num2[i];
		if (num[i] < min2)
			min2 = num[i];
	}

	if (min2 < min)
		return min2;
	if (min2 > min)
		return min;
}

int main(void) {
	int board1[8][8] = { {1,0,1,0,1,0,1,0},
						 {0,1,0,1,0,1,0,1},
						 {1,0,1,0,1,0,1,0},
						 {0,1,0,0,0,1,0,1},
						 {1,0,1,0,1,0,1,0},
						 {0,1,0,1,0,1,0,1},
						 {1,0,1,0,1,0,1,0},
						 {0,1,0,1,0,1,0,1}   
					   };
	int board2[10][13] = { {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {1,1,1,1,1,1,1,1,1,1,0,1,0},
						   {1,1,1,1,1,1,1,1,1,1,0,1,0}
					     };
	// The values of board3 are hidden on purpose
	int board3[11][13] = { {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {1,1,1,1,1,1,1,1,1,1,0,1,0},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {1,1,1,1,1,1,1,1,1,1,0,1,0},
						   {1,1,1,1,1,1,1,1,1,1,0,1,0}
					     };
	
	int option, n_repaint;
	
	scanf("%d", &option);
	
	switch (option) {
		case 1 :
			n_repaint = min_num_cell_to_repaint(8,8,board1);
			break;
		case 2 :
			n_repaint = min_num_cell_to_repaint(10,13,board2);
			break;
		default :
			n_repaint = min_num_cell_to_repaint(11,13,board3);
			break;
	}
	printf("%d\n", n_repaint);
	return 0;
}
