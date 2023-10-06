#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char* words[3];

	char input[100] = { 0, };

	for (int i = 0; i < 3; i++) {
		printf("%d 번째 문자열 : ", i + 1);
		gets(input);
		
		words[i] = (char*)malloc(sizeof(char) * (strlen(input) + 1));
		strcpy(words[i], input);
	}

	printf("\n\n-- 입력과 반대로 출력(포인터) : 글자 순서도 거꾸로 --\n\n");
	
	for (int i = 2; i > -1; i--) {
		printf("%d : ", i + 1);
		for (int j = strlen(words[i]); j > -1; j-- ) {
			printf("%c", words[i][j]);
		}
		printf("\n");
	}

	return 0;
}