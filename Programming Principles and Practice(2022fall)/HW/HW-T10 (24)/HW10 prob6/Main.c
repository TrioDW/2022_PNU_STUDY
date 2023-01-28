#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void add_memory (int* s, int* *ar) {
	int size = *s + 1;
	int* t = (int*)malloc(sizeof(int) * size), i;
	
	for (i = 0; i < *s; i++)
		t[i] = (*ar)[i];
	free(*ar);
	*ar = t;
	*s = size;
}

int * read_numbers_binary(char *filename) {

	FILE* fpbin = fopen(filename, "r");
	int size = 1, *result = (int*)malloc(sizeof(int)), nval;
	while (fread(&nval, sizeof(int), 1, fpbin)) {
		result[size - 1] = nval;
		add_memory(&size, &result);
	}
	result[size-1] = -1;
	fclose(fpbin);
	return result;
}

int * read_numbers_csv(char *filename) {
	FILE* fpcsv = fopen(filename, "r");
	int size = 1, *result = (int*)malloc(sizeof(int));
	char buf[100];
	
	while (fgets(buf, sizeof(buf), fpcsv)) {
		int nval = 0, i;
		for (i = 0; buf[i]; i++) {
			if (buf[i] == ',' || buf[i] == '\n') {
				result[size - 1] = nval;
				add_memory(&size, &result);
				nval = 0;
			}
			else 
				nval = nval * 10 + (buf[i] - '0');
		}
	}
	result[size - 1] = -1;
	fclose(fpcsv);
	return result;
}
void save_numbers_binary(int *pn, char *filename) {
	FILE *fd = fopen(filename, "wb");
	int *pcur = pn;
	
	if (fd) {
		while (*pcur >= 0) pcur++;
		fwrite(pn, sizeof(int), pcur-pn, fd);
		fclose(fd);
	}
}

void save_numbers_csv(int *pn, char *filename) {
	FILE *fd = fopen(filename, "wt");	// Explicitly specify text mode
	int *pcur = pn;
	
	if (fd) {
		while (*pcur >= 0) {
			fprintf(fd, "%d", *pcur++);	
			while (*pcur >= 0) {
				fprintf(fd, ",%d", *pcur++);
				if ( (pcur-pn) % 8 == 0) {
					fprintf(fd, "\n");
					break;
				}
			}
		}
		fclose(fd);
	}
}

int get_max(int *values) {
	int nmax = 0;
	
	if (values) {
		while (*values >= 0) {
			if (*values > nmax)
				nmax = *values;
			values++;
		}
	}
	return nmax;
}

int * generate_numbers(int nnums) {
	int *pnum = (int *)malloc(sizeof(int)*(nnums+1));
	int *pcur = pnum;

	assert(pnum);	
	
	while (pcur < pnum + nnums) 
		*pcur++ = rand();
	
	*pcur = -1;
	
	return pnum;	
}
int main(void) {
	int testcase = 1, bbinary = 0;
	char *filename = "output"; 
	int test_values1[] = {1, 9, 178, 15, 2345, 2, 2, 34, 12, 5, -1};
	int *values = test_values1;
	
	scanf("%d", &testcase);
	switch (testcase) {
		case 2 :
			bbinary = 1;
		break;				
		case 3 :
			srand(11);
			values = generate_numbers(100);			
			break;
		case 4 :
			bbinary = 1;
			srand(21);
			values = generate_numbers(100);			
			break;			
		case 5 :
			srand(11);
			values = generate_numbers(10000);
			break;
		case 6 :
			srand(21);
			bbinary = 1;
			values = generate_numbers(10000);
			break;
		default :
			break;			
	}
	if (bbinary) {
		save_numbers_binary(values, filename);
		printf("Max : %d\n", get_max(read_numbers_binary(filename)));
	}
	else {
		save_numbers_csv(values, filename);		
		printf("Max : %d\n", get_max(read_numbers_csv(filename)));
	}
	
	return 0;
}