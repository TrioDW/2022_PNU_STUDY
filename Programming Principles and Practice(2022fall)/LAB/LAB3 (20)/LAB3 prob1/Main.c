#include <stdio.h>
// You can add your own functions if necessary

void capitalize_first_character(char str[1000]) {
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	
	for (int i = 0; str[i]; i++) {
		if (str[i] == ' ' && str[i+1] >= 'a' && str[i+1] <= 'z')
			str[i+1] -= 32;
	}
	printf("%s", str);	
}
int main(void) {
	char str[1000];
	
	gets(str);
	
	capitalize_first_character(str);
	return 0;
}
