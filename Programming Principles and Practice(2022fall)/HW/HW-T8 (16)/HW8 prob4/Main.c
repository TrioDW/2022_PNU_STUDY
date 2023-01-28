#include <stdio.h>

char *mystrstr(char *str, char *substr) {
	int cnt = 0, i, chk = 0;

	while (*substr) {
		cnt++;
		*substr++;
	}

	for (i = 0; i < cnt; i++) 
		*substr--;
	
	if (cnt == 0) {
		return str;
	}

	if (cnt == 1) {
		while (*str) {
			if (*str == *substr)
				return str;
			else
				str++;
		}
	}
	
	else {
		while (*str) {
			if (*str == *substr) {
				chk++;
				if (cnt == chk)
					return (str - cnt + 1);
				else {
					str++;
					substr++;
				}
			}
			else 
				*str++;
		}
		return 0;
	}
}
void find_str(char * str, char * substr) {
	char* pos = mystrstr(str, substr);
	if(pos) 
		printf("found the string '%s' in '%s' at position: %ld\n", substr, str, pos - str);
	else
		printf("the string '%s' was not found in '%s'\n", substr, str);
}
 
int main(void) {
	char* str = "one two three";
	find_str(str, "two");
	find_str(str, "");
	find_str(str, "nine");
	find_str(str, "n");

	return 0;
}