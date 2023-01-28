#include <stdio.h> 
/**
* @brief : determine whether n is a palindromic number or not 
* @return: 1 if n is a palindromic number, 0 otherwise
* @param : n - a non-negative integer to be checked
*/
int is_palindromic_number(unsigned int n) {
	char numm[32];
	
	sprintf(numm, "%d", n);

	int cnt = 0;

	while (n != 0) {
		n /= 10;
		++cnt;
	}

	if (cnt % 2 == 0) {
		for (int i = 0; i < (cnt/2); i++) {
			if (numm[i] != numm[cnt - i - 1]) {
				return 0;
			}
		}
		return 1;
	}
	
	else {
		for (int i = 0; i < ((cnt-1)/2); i++) {
			if (numm[i] != numm[cnt - i - 1])
				return 0;
		}
		return 1;
	}
}

int main(void) {
	unsigned int num;
	
	scanf("%d",&num);
	
	if (is_palindromic_number(num))
		printf("is a palindromic number\n");
	else 
		printf("is not a palindromic number\n");

	return 0;
}