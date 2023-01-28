#include <stdio.h>
int main(void) {
	int input_values;
	int n_hours, n_minutes, n_seconds;
	
	scanf("%d", &input_values);
	
	n_minutes = input_values / 60;
	n_seconds = input_values - n_minutes * 60;
	n_hours = n_minutes / 60;
	n_minutes -= n_hours * 60;

	
	printf("%d seconds is equivalent to %d hours, %d minutes and %d seconds", input_values, n_hours, n_minutes, n_seconds);

	return 0;
}
