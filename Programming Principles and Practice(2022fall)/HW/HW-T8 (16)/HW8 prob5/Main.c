#include <stdio.h> 
#include <string.h>
#include <ctype.h>

int ispalindrome(char *str) {
	
	static char new_str[1024];

	int i = 0, j = 0; // j가 new_str의 문자열 개수
	
	while (str[i]) {
		
		if (str[i] >= '0' && str[i] <= '9')
			new_str[j++] = str[i++];
		
		else if (str[i] >= 'A' && str[i] <= 'Z')
			new_str[j++] = str[i++];
		
		else if (str[i] >= 'a' && str[i] <= 'z')
			new_str[j++] = str[i++];
		
		else
			i++;
	}
	
	for (int a = 0; a < j; a++) {
		if (isupper(new_str[a]))
			new_str[a] = tolower(new_str[a]);
	}
	
	if (j % 2 == 0) {
		for (int a = 0; a < (j/2); a++) {
			if (new_str[a] != new_str[j-a-1])
				return 0;
		}
		return 1;
	}
	
	else {
		for (int a = 0; a < ((j-1)/2); a++) {
			if (new_str[a] != new_str[j-a-1])
				return 0;
		}
		return 1;
	}
}
int main(void) {
	char buffer[1024];

	gets(buffer);
	printf("[%s] is ", buffer);
	if (ispalindrome(buffer)) puts("a palindrome");
	else puts("not a palindrome");
	
	return 0;
}