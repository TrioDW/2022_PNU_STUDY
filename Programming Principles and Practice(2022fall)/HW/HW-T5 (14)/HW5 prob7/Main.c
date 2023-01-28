#include <stdio.h>
int main(void) {
	char str[1000];
	int n_word = 0;
	int i;
	
	gets(str);
	int flag = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ' && flag == 0) {
			n_word += 1;
			flag = 1;
		}
		else if (str[i] == ' ')
			flag = 0;
	}
	printf("%d\n", n_word);
	return 0;
}