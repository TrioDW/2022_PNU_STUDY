#include <stdio.h>
#include <assert.h>

int main(void) {
	char *filename = "data/stdint-wrap.h";
	FILE *fp = fopen(filename, "r");
	assert(fp);
	
	char buf[256];
	
	for (int line_number = 1; line_number < 15; line_number++) {
		fgets(buf, sizeof(buf), fp);
		printf("%2d : ", line_number);
		printf(buf);
		}
	
	fclose(fp);
	
	return 0;	
}
