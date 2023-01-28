#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct student {
	int id;
	char name[12];
	double points;
} STUD;

STUD * sort_students(STUD *ps) {
	STUD temp;
	
	int cnt = 0;
	while (ps[cnt++].id != -1);
	
	for (int i = 0; i < cnt - 2; i++) {
		for (int j = 0; j < cnt - i - 2; j++) {
			if (ps[j].points < ps[j+1].points) {
				temp = ps[j];
				ps[j] = ps[j+1];
				ps[j+1] = temp;
			}
		}
	}
	return ps;
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
	STUD test_data[] = { {1, "Choi", 9.9}, {2, "Park", 0.1}, {3, "Kim", 5.0 }, 
	{4, "Lee", 9.9 }, {5, "Moon", 9.5 }, {6, "Kang", 7.0 }, {7, "Jeon", 0.9 }, {-1, "", 0 } };
	STUD *students = test_data, *sorted_students = NULL;
	int test_case = 1;
	
	scanf("%d", &test_case);
	srand(10);
	
	switch (test_case) {
		case 2 :
			students = generate_data(100);
			break;
		case 3 :
			students = generate_data(300);
			break;
		case 4 :
			students = generate_data(890);
			break;
		default :
			break;
	}
	sorted_students = sort_students(students);	
	print_tops(sorted_students);
	
	return 0;	
}