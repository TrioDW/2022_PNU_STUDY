#include <stdio.h>
int main(void) {
	char msg[] = "^^ \tThis is a Test Message 2022 !!\n Thank You !!!";
	int i;
	
	printf("%s\n", msg);
	
	for (i=0; msg[i] != '\0'; i++) {
	if (msg[i] >= 97 && msg[i] <= 122)
		msg[i] -= 32;
	
	else
		continue;
	}
	
	printf("%s\n", msg);
	return 0;
}
