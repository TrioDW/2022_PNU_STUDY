#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct student {
	int id;
	char name[12];
	double points;
} STUD;

void memory (int* size, STUD* *test) {
	
	int new_size = *size + 1;
	STUD* new_test = (STUD*) malloc (sizeof(STUD) * new_size);
	
	for (int i = 0; i < *size; i++)
		new_test[i] = (*test)[i];
	
	free(*test);
	*test = new_test; *size = new_size;
}

STUD stud_info (char* data) {
	STUD result;
	
	result.id = atoi(strtok(data, " "));
	
	char* name = strtok(NULL, " ");
	char* fix = name;
	do {
		result.name[name-fix] = *name;
	} while (*name++ != '\0');
	
	result.points = (double)atof(strtok(NULL, " "));
	
	return result;
}

STUD * read_students_binary(char *filename) {
	
	FILE* fp = fopen(filename, "r");
	int size = 1;
	
	STUD* test = (STUD*) malloc (sizeof(STUD));
	STUD last = {-1, '\0', 0};
	
	STUD ans;
	
	while (fread(&ans, sizeof(STUD), 1, fp)) {
		test[size-1] = ans;
		memory(&size, &test);
	}
	test[size-1] = last;
	
	fclose(fp);
	
	return test;
}

STUD * read_students_text(char *filename) {
	
	FILE* fp = fopen(filename, "r");
	int size = 1;
	
	STUD* test = (STUD*) malloc(sizeof(STUD));
	STUD last = {-1, '\0', 0};
	
	char buf[100]; STUD ans;
	
	while (fgets(buf, sizeof(buf), fp)) {
		ans = stud_info(buf);
		test[size-1] = ans;
		memory(&size, &test);
	}
	test[size-1] = last;
	
	fclose(fp);
	
	return test;
}
void save_students_text(STUD *ps, char *filename) {
	FILE *fd = fopen(filename, "wt");
	
	if (fd) {
		while (ps->id > 0) {
			fprintf(fd, "%d %s %lf\n", ps->id, ps->name, ps->points);
			ps++;
		}
		fclose(fd);
	}		
}

void save_students_binary(STUD *ps, char *filename) {
	FILE *fd = fopen(filename, "wb");
	STUD *pcur = ps;
	int nitem = 0;
	
	if (fd) {
		while (pcur->id > 0) pcur++;
		fwrite(ps, sizeof(STUD), pcur - ps, fd);
		fclose(fd);
	}		
}

void stud_print(STUD *ps) {
	printf("%03d %-12s %5.1lf\n", ps->id, ps->name, ps->points);
}

void print_students(STUD *ps) {
	while (ps->id > 0) stud_print(ps++);
}

void print_tops(STUD *sorted_ps) {
	double highest_points = sorted_ps->points;
	do {
		stud_print(sorted_ps++);
	} while (sorted_ps->points == highest_points);
}

STUD * sort_students(STUD *ps);
STUD * generate_data(int nitem) {
	FILE *fd = fopen("data/names.csv", "rt");
	STUD *values = NULL;
	if (fd) {
		char names[890][12];
		int i=0;

		values = (STUD *) malloc(sizeof(STUD)*(nitem+1));
		while( fscanf(fd, "%s",names[i])==1)
			i++;
		fclose(fd);

		for (i=0; i<nitem; i++) {
			values[i].id = i+1;
			strcpy(values[i].name, names[i]);
			values[i].points = rand()%100+1.0;
		}
		values[i].id = -1;
	}
	
	return values;		
}
int main(void) {
	char *filename = "data/output";
	STUD test_data[] = { {1, "Choi", 9.9}, {2, "Park", 0.1}, {3, "Kim", 5.0 }, 
	{4, "Lee", 9.9 }, {5, "Moon", 9.5 }, {6, "Kang", 7.0 }, {7, "Jeon", 0.9 }, {-1, "", 0 } };
	STUD *students = test_data, *readin_students = NULL, *sorted_students = NULL;
	int test_case = 1, bbinary = 0;
	
	scanf("%d", &test_case);
	if (test_case % 2) 
		srand(20);
	else {
		srand(30);
		bbinary = 1;
	} 
	
	switch (test_case) {
		case 3 :
		case 4 :
			students = generate_data(100);
			break;
		case 5 :
		case 6 :
			students = generate_data(300);
			break;
		case 7 :
		case 8 :
			students = generate_data(890);
			break;
		default :
			break;
	}
	if (bbinary) {
		save_students_binary(students, filename);
		readin_students = read_students_binary(filename);
	}
	else {
		save_students_text(students, filename);
		readin_students = read_students_text(filename);
	}
	if (readin_students) {
		sorted_students = sort_students(readin_students);	
		print_tops(sorted_students);
	}	
	return 0;	
}
STUD * get_last(STUD *ps) {
	while (ps->id > 0)
		ps++;
	return --ps;
}

STUD * sort_students(STUD *ps) {
	STUD *pcur = NULL, *pend = NULL;
	
	for (pend = get_last(ps); pend > ps; pend--) {
		int n_swap = 0;
		STUD tmp;
		for (pcur = ps; pcur < pend; pcur++ ) {
			if (pcur->points < (pcur+1)->points) {
				tmp = *pcur;
				*pcur = *(pcur+1);
				*(pcur+1) = tmp;
				n_swap++;
			}
		}
		if (n_swap == 0)
			break;
	}		
	return ps;
}