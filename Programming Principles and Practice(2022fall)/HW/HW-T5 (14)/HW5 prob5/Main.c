#include <stdio.h>

int main(void)
{
	char str[11];
	unsigned int num=0;	// number
	int i; // index

	scanf("%s",str);

	for(i=0; str[i]; i++) {
	num = num * 10 + str[i] - 48;
	}

	printf("[%s] is %d\n",str,num);
	
	return 0;
}