#include <stdio.h>

char *mystrcat(char *dest, char *src) {
	
	int cnt_1 = 0, cnt_2 = 0;
	
	while (*dest) {
		*dest++;
		cnt_1++;
	}
	
	while (*src) {
		*src++;
		cnt_2++;
	}
	
	for (int i = 0; i < cnt_1; i++)
		*dest--;
	
	for (int i = 0; i < cnt_2; i++)
		*src--;
	
	int idx = cnt_1;
	
	for (int i = 0; i < cnt_2; i++) 
		dest[idx++] = src[i];
	
	return dest;
}

int main(void) {
	char str[256] = "Hello ";
	char * pstr2 = "Good Bye World !!!";
	
	printf("%s\n", mystrcat(mystrcat(str, " World !!! ..."), pstr2 ));

	return 0;
}