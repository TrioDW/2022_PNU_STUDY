#include <stdio.h>

char * mystrrev(char * str) {
	static char revstr[256];

	int cnt = 0;
	
	while (*str) {
		*str++;
		cnt++;
	}

	for (int i = 0; i < cnt; i++)
		*str--;
	
	for (int i = 0; i < cnt; i++) {
		revstr[i] = str[cnt - i - 1];
	}

	return revstr;
}
int main(void) {
	char str[256];
	
	gets(str);
	
	printf("%-20s  : After Reverse >>>\n",str);
	printf("%-20s\n", mystrrev(str));

	return 0;
}