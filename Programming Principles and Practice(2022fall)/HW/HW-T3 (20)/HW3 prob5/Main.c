#include <stdio.h> 

int main(void)
{
	int y;

	scanf("%d",&y);
	if((y % 4 == 0 & y % 100 == 0 & y % 400 == 0) | (y % 4 == 0 & y % 100 != 0))
		printf("leap\n");
	else
		printf("not leap\n");

	return 0;
}