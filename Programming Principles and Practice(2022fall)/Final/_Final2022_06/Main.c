#include <stdio.h>
#include <stdlib.h>
#define MSG_LEN_MAX 256
/*
DESCRIPTION
	'mystrcpy' copies a string from src to dest
ARGUMENTS
	src: char array storing a null-terminated string
	dest: char array
*/
void mystrcpy(char dest[], char src[]) {
	while (*src) { *dest++ = *src++; }
    *dest='\0';
}

/*
DESCRIPTION
	'mystrlen' returns the length of a given string str.
	It returns the count of the character that is not null 
		from the beginning of the given string str.
ARGUMENTS
	str: char array storing a null-terminated string
RETURN
	count : byte length of the string str
*/
int mystrlen(char str[]) {
	int count = 0;
	while (*str != '\0') {
		count++;
		str++;
	}
    return count;
}
int main(int argc, char* argv[]){
	/* [시작] 1. 구름에서 테스트 케이스 실행을 위한 부분 */ 
	int test_case = -1;
	argv = NULL;
	scanf("%d", &test_case);
	switch( test_case ){
		case 1: //Hello
			argc = 1;
			argv = calloc(sizeof(char*), argc+1);
			break;
		case 2: //Hello my major is CSE
			argc = 3;
			argv = calloc(sizeof(char*), argc+1);
			argv[1] = "-m";
			argv[2] = "CSE";
			break;
		case 3: //Hello my major is CSE and my name is Daniel
			argc = 5;
			argv = calloc(sizeof(char*), argc+1);
			argv[1] = "-m";
			argv[2] = "CSE";
			argv[3] = "-n";
			argv[4] = "Daniel";
			break;
		case 4: //Hello my major is CSE and my name is Daniel
			argc = 5;
			argv = calloc(sizeof(char*), argc+1);
			argv[1] = "-n";
			argv[2] = "Daniel";			
			argv[3] = "-m";
			argv[4] = "CSE";
			break;
		case 5: //Hello my name is Daniel
			argc = 3;
			argv = calloc(sizeof(char*), argc+1);
			argv[1] = "-n";
			argv[2] = "Daniel";
			break;
		case 6: //Hello my major is ART and my name is Leonardo
			argc = 5;
			argv = calloc(sizeof(char*), argc+1);
			argv[1] = "-n";
			argv[2] = "Leonardo";			
			argv[3] = "-m";
			argv[4] = "ART";
			break;
		case 7: //Hello my major is ARCHITECT and my name is Richard
			argc = 5;
			argv = calloc(sizeof(char*), argc+1);
			argv[1] = "-m";
			argv[2] = "ARCHITECT";			
			argv[3] = "-n";
			argv[4] = "Richard";
			break;
		case 8: //Hello my major is MEDICAL
			argc = 3;
			argv = calloc(sizeof(char*), argc+1);
			argv[1] = "-m";
			argv[2] = "MEDICAL";
			break;
		case 9: //Hello my name is GildongHong
			argc = 3;
			argv = calloc(sizeof(char*), argc+1);
			argv[1] = "-n";
			argv[2] = "GildongHong";
			break;
		case 10: //Hello my major is CPRE and my name is Turing
			argc = 5;
			argv = calloc(sizeof(char*), argc+1);
			argv[1] = "-n";
			argv[2] = "Turing";			
			argv[3] = "-m";
			argv[4] = "CPRE";
			break;
		default: //Hello
			argc = 1;
			argv = calloc(sizeof(char*), argc+1);
			break;
	} 
	argv[0] = "introduction.exe";
	argv[argc] = NULL;
	/* [끝] 1. 구름에서 테스트 케이스 실행을 위한 부분 */ 
	// char array to include the introduction sentence
	char introduction[10] = "Hello";
	
	// - print the introduction message
	// - do not include newline character(s) at the end
	printf("%s", introduction);
	/* [시작] 2. 구름에서 테스트 케이스 실행을 위한 부분 */ 
	free(argv);
	/* [끝] 2. 구름에서 테스트 케이스 실행을 위한 부분 */ 
	return 0;
}