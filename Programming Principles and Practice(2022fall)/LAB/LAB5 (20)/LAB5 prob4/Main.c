#include <stdio.h>
#define MAX_NUMBER	10000

int self_num (int num) {
	
	int i = 0, sum = num;
	int str[6] = {0, };
	
	while (num != 0) {
		str[i] = num % 10;
		num /= 10;
		i++;
	}
	
	for (int i = 0; i < 5; i++) {
		sum += str[i];
	}
	return sum;
}

int main(void) {
	int arr[MAX_NUMBER] = {0, };
	
	for (int i = 1; i < MAX_NUMBER; i++) {
		int ans = self_num(i);
		
		if (ans < 10000)
			arr[ans] = 1;
	}
	
	for (int i = 1; i < MAX_NUMBER; i++) {
		if (arr[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}
