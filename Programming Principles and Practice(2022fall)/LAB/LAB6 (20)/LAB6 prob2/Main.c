#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool used[7];
int ans[7];
int len;

void permutation (int k, int n, char* str) {
	if (k == n) {
		for (int i = 0; i < n; i++)
			printf("%c", str[ans[i]]);
		printf("\n");
	}
	
	else {
		for (int i = 0; i < len; i++) {
			if (used[i] == false) {
				ans[k] = i;
				used[i] = true;
				permutation(k+1, len, str);
				used[i] = false;
			}
		}
	}
}

void print_all_permutations(char *str) {
	len = strlen(str);
	permutation(0, len, str);
	return;
}

int main(void) { 
	char str[256] = "ABC";

	print_all_permutations(str);
	return 0; 
} 