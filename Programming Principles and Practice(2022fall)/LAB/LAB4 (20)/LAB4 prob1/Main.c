#include <stdio.h>
// Function Declarations
double my_max(double f1, double f2); // return the larger value between f1 and f2
double my_abs(double f);	// return the magnitude of f, that is |f|

/**
* @brief : Find an approximation to the square root of a non-negative number using the exaustive search method. 
* @return: An approximation to the square root. The square of it should be in the range [x-epsilon, x+epsilon].
          -1 if it can't find an answer.
* @param : x - target number, epsilon - the allowed difference 
*/
double findroot_exhaustive(double x, double epsilon);	
/**
* @brief : Find an approximation to the square root of a non-negative number using the bisection search method. 
* @return: An approximation to the square root. The square of it should be in the range [x-epsilon, x+epsilon].
          -1 if it can't find an answer.
* @param : x - target number, epsilon - the allowed difference 
*/
double findroot_bisection(double x, double epsilon);

double findroot_bisection(double x, double epsilon) {
	double low = 0.0;
	double high = my_max(1.0,x);
	double ans = (high+low)/2;
	int numGuesses = 0;
	
	double diff = my_abs(ans*ans - x);
	
	while (diff >= epsilon) {
		if ((ans*ans) > x)
			high = ans;
		else
			low = ans;
		
		ans = (high + low) / 2;
		diff = my_abs(ans*ans -x);
		numGuesses = numGuesses + 1;
	}
	
	printf("# of Guesses = %d\n", numGuesses);
		
	return ans;
}

int main() {
	double x;
	double epsilon = 0.001;

	scanf("%lf",&x);
	
	if (x > 0) {
		printf("[EXHAUSTIVE] sqrt(%lf) ~= %.20lf\n",x,findroot_exhaustive(x,epsilon));
		printf("[BISECTION ] sqrt(%lf) ~= %.20lf\n",x,findroot_bisection(x,epsilon));
	}	

	return 0;
} 

double findroot_exhaustive(double x, double epsilon) {
	double step = epsilon * epsilon;
	double ans = 0.0;
	int numGuesses = 0;
	
	double diff = my_abs(ans*ans - x);
	
	while (diff >= epsilon && ans*ans <= x) {
		ans = ans + step;
		diff = my_abs(ans*ans -x);
		numGuesses = numGuesses + 1;
	}
	if (diff >= epsilon) ans = -1.0;	
	
	printf("# of Guesses = %d\n", numGuesses);
		
	return ans;	
}

double my_abs(double f) {
	if (f < 0) f=-f;
	return f;
}

double my_max(double f1, double f2) {
	if (f1 < f2) f1=f2;
	return f1;
}