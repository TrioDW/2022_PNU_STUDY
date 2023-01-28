#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define	DEF_RATE	1.8 // default rate (%)
#define	DEF_TERM 	1 // default term (yr)

int inter_calc(int dep, double rate, int yrs) {
	double ans = 1;
	
	for (int i = 0; i < yrs; i++)
		ans *= (1 + rate);
	
	return ((dep * ans) - dep);
}

int main(int argc, char *argv[]) {
	int myargc = 1, i;
	char my_cmd_line[1000]; 
	char *myargv[20]={"bankint", NULL};
	char *token = NULL;

	gets(my_cmd_line);
	
	token = strtok(my_cmd_line, " ");
	
	while (token) {
		myargv[myargc++] = token;
		token = strtok(NULL, " ");
	}

	return mymain(myargc, myargv);
}

int mymain(int argc, char *argv[]) {

	int deposit;
	double rate = DEF_RATE/100;
	int term = DEF_TERM;

	if (argc == 1) {
		printf("Usage: bankint <deposit_money> <interest_rate(%)> <term(year(s))>\n");
		printf("Default interest = 1.8%, Default term = 1 year");
	}
	else {
		if (argc >= 2)
			deposit = atoi(argv[1]);
		if (argc >= 3)
			rate = atof(argv[2])/100;
		if (argc == 4)
			term = atoi(argv[3]);
		printf("Total Interest = KRW %d\n", inter_calc(deposit, rate, term));
	}

	return 0;
}