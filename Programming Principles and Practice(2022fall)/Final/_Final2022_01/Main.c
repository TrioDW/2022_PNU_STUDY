#include <stdio.h>

int smart_calculator(int a, int b, int* add, int*sub, int*mul, int* div){
	
	static int cumsum;
	
	*add = a + b;
	*sub = a - b;
	*mul = a * b;
	*div = a / b;
	
	cumsum += *add + *sub + *mul + *div;
	return cumsum;
}

void print_result(int a, int b, int add, int sub, int mul, int div, int cumsum){
	printf("a=%d, b=%d, a+b=%d, a-b=%d, a*b=%d, a/b=%d, cumsum=%d\n",
				a, b, add, sub, mul, div, cumsum);
}

int main(void){
	int cmd;
	
	scanf("%d", &cmd);
	
	int a, b, add, sub, mul, div, cumsum;
	
	switch(cmd){
		case 1:
			a = 2; b = 1;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = 0; b = 1;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = 1; b = -3;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			break;
			// Remaining codes are hidden on purpose
		case 2:
			a = 9; b = 8;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = -2; b = 5;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = 10; b = 3;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = 7; b = 7;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = 5; b = 2;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			break;
		case 3:
			a = 1; b = 10;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = 50; b = 5;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = 10; b = 4;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = -49; b = 7;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = 100; b = 33;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			break;
		case 4:
			a = -33; b = 3;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = 12; b = 8;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = 1024; b = 512;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = 1920; b = 1080;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = -4096; b = -99;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			break;
		default:
			a = 0; b = -1;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = 45; b = 15;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = 99; b = 33;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = 1000000; b = 25;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = -1009; b = 1008;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = 987654; b = 321123;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			a = -951951; b = 357357;
			cumsum = smart_calculator(a, b, &add, &sub, &mul, &div);
			print_result(a, b, add, sub, mul, div, cumsum);
			break;
		}
}