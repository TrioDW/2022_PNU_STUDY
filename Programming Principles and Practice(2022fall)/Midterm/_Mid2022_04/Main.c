#include <stdio.h>

int main(void){
	char str[256];
	int i, num = 0;

	gets(str);

	

	for (i = 0; str[i]; i++) {
	
		
		if (str[i] == 'A') {
			num *= 16;
			num += 10;
		}
		
		else if (str[i] == 'B') {
			num *= 16;
			num += 11;
		}
		
		else if (str[i] == 'C'){
			num *= 16;
			num += 12;
		}
		
		else if (str[i] == 'D') {
			num *= 16;
			num += 13;
		}
		
		else if (str[i] == 'E') {
			num *= 16;
			num += 14;
		}
		
		else if (str[i] == 'F') {
			num *= 16;
			num += 15;
		}

		else {
			num *= 16;
			num += str[i] - 48;
		}
			
	}

	printf("%s is converted to %d\n", str, num);
	return 0;
}
