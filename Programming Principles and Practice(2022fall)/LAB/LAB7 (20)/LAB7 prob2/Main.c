#include <stdio.h>
#include <time.h>
void print_local_time_after_kdays(time_t t, int k) {
	struct tm *pnow;
	t += k * 86400;
	pnow = localtime(&t);
	
	if (pnow != NULL) {
		printf("%d/%d/%d, %02d:%02d:%02d, ", pnow->tm_year + 1900, pnow->tm_mon + 1, pnow->tm_mday, pnow->tm_hour, pnow->tm_min, pnow->tm_sec);
		
		switch (pnow->tm_wday) {
			case 0:
				printf("Sunday");
				break;
			case 1:
				printf("Monday");
				break;
			case 2 :
				printf("Tuesday");
				break;
			case 3 :
				printf("Wednesday");
				break;
			case 4 :
				printf("Thursday");
				break;
			case 5 :
				printf("Friday");
				break;
			case 6 :
				printf("Saturday");
				break;
			default :
				break;
		}
	}

	return;
}
int main(void) {
	int k=0;
	time_t now = 1669856792; // 2022/12/01 01:06:32
	
	scanf("%d", &k);
	
	print_local_time_after_kdays(now, k);

	return 0;
}