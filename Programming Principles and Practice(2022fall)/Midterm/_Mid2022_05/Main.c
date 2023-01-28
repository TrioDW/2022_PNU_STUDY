#include <stdio.h>
#define ROUND 10
unsigned int _consecutive_point=0;

int cnt = 0;

int cal_points(char fc_result){
	
	if (fc_result == 'W') {
		cnt++;
		return cnt;
	}

	
	else {
		cnt = 0;
		return -1;
	}

	// your code here
}

int main(){
    char result[ROUND];
    for(int i=0; i<ROUND; i++){
        scanf("%c", &result[i]);
    }

    unsigned int sum=0;
    for(int i=0; i<ROUND; i++) {
        sum += cal_points(result[i]);
    }
    printf("%d", sum);
}
