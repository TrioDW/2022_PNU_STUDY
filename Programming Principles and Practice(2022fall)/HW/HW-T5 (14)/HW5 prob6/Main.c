#include <stdio.h> 
int main(void)
{
	int i;		// index

	unsigned int num=0;	// number
	unsigned int nd, len;
	char str[11];       // Max Digits + 1
	char rstr[11];      // Max Digits + 1

	scanf("%d",&num);
 
	sprintf(str, "%d", num);
	printf("%d is [%s]\n",num, str);
	return 0;
}
