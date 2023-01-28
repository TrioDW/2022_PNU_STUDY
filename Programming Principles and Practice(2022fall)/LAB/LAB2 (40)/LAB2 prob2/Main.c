#include <stdio.h>

int main()
{
	int X, Y;
	
	while(1) {
		printf("Enter an integer number no less than 100: ");
		scanf("%d", &X);
		
		if (X < 100) {
			printf("Sorry, the number you entered is less than 100\n");
			continue;
		}
		
		else {
			Y = (X % 100) / 10;
			
			if (Y % 2 == 0)
				printf("The 2nd last number of %d is %d and it is even\n", X, Y);
			
			else
				printf("The 2nd last number of %d is %d and it is odd\n", X, Y);
			
			break;
		}
		
	}
	return 0;
}