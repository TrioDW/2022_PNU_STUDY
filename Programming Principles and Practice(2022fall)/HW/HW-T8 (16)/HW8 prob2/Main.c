#include <stdio.h>

int mystrlen(char *str) {
	int cnt = 0;
	while (*str) 
	{
		*str++;
		cnt++;
	}
	return cnt;
}

char *mystrcpy(char *dest, char *src) {
	int i = 0, j = 0;
	
	while (src[i]) {
		dest[j++] = src[i++];
	}
	dest[j] = '\0';

	return dest;
}

int mystrcmp(char *lhs, char *rhs) {
	for (int i = 0; lhs[i] || rhs[i]; i++) {
		
		if (lhs[i] > rhs[i])
			return 1;

		else if (lhs[i] < rhs[i])
			return -1;
	}

	return 0;
}


int main(void) {
	char str1[256] = "Hello World !!!\n Good Day !!!";
	char str2[256] = "Hello PNU CSE !!!";
	char str3[256];
	
	printf("mystrlen(str1) = %d, mystrlen(str2) = %d\n",
				mystrlen(str1), mystrlen(str2));
	
	printf("mystrcpy(str3,str1) = %s\n", mystrcpy(str3,str1));
	
	printf("mystrcmp(str1,str3) = %d, mystrcmp(str2,str3) = %d", 
				mystrcmp(str1,str3), mystrcmp(str2,str3));
	
	return 0;
}