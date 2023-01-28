#include <stdio.h>

void character_checker(char c){
	
	if (c >= 65 && c <= 90) 
		printf("%c is an uppercase letter", c);
	
	else if (c >= 97 && c <= 122)
		printf("%c is a lowercase letter", c);

	else if (c >= 45 && c <= 54)
		printf("%c is a digit", c);

	else
		printf("%c is neither alphabet nor digit", c);

	return 0;

}

int main() {
	char ch;
	scanf("%s", &ch);
	character_checker(ch);
	return 0;
}