#include <stdio.h>

char find_delim (char c, char* delim) {
	while (*delim && c != *delim)
		delim++;
	
	return *delim;
}

char *mystrtok(char *str, char *delim) {
	
	static char *psave = 0;
	
	if (str)
		psave = str;
	
	char* start = 0;
	
	if (psave) {
		str = psave;
		
		while (find_delim(*str, delim))
			str++;
		
		if (*str) {
			start = str++;
			
			while (*str && !find_delim(*str, delim))
				str++;
			
			if (*str) {
				psave = str + 1;
				*str = '\0';
			}
			else
				psave = 0;
		}
	}
	
	return start;
}

int main(void) {
	char *pstr, *ptoken, *delim;
	int test = 0;

	char test_str[][256] = { "T1,T2 T3, T4  ,T5,,",", ",
		"abc\t  x\ny  z\n\nk", " \t\n",
		"#include <stdio.h>\nint\tmain(void){ int x=3;","# <>\n\t(){}=;"};
	
	scanf("%d", &test);
	if (test > 2 || test < 0) test = 0;
	pstr = test_str[2*test];
	delim = test_str[2*test+1];

	ptoken = mystrtok(pstr, delim);
	
	while (ptoken) {
		printf("%s\n",ptoken);
		ptoken = mystrtok(0, delim);		
	}
		
	return 0;
}