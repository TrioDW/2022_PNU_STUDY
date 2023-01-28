#include <stdio.h> 

//#define GCD(a,b)	euclidr(a,b)
#define GCD(a,b)	euclid(a,b)

int euclidr(int a, int b) {
	if (b > a) return euclidr(b, a);
	if (b == 0) return a;
	return euclidr(b, a % b);
}

/* Get and return the LCM (Least Common Multiples) of integers a and b */
int LCM(int a,int b) {
	
	return (a*b/GCD(a,b));
}

/* If the GCD of integers a and b is 1, a and b are called co-prime or relatively prime
 * Determine if a and b are co-prime or relatively prime.
 * Return 1 if they are co-prime, otherwise return 0 */
int isCoprime(int a, int b) {
	if (GCD(a,b) == 1)
		return 1;
	else
		return 0;
}

/* Get and return the GCD of integers a and b based on the Euclidean algorithm */
/* Note that recursive call is not allowed in this function */
int euclid(int a, int b) {
	int tmp, n;

	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main(void) {
	int a, b;
	printf("Enter two positive integers\n");
	scanf("%d%d", &a, &b);
	printf("GCD of (%d, %d) is %d\n", a, b, GCD(a, b));
	printf("LCM of (%d, %d) is %d\n", a, b, LCM(a, b));
	printf("(%d, %d) is co-prime (True-1 / False-0) : %d\n", a, b, isCoprime(a, b));
	return 0;
}