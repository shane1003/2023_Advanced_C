#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	
	char input1[100] = { 0, };
	char input2[100] = { 0, };

	printf("ù ��° ���ڿ� �Է� : ");
	gets(input1);
	printf("�� ��° ���ڿ� �Է� : ");
	gets(input2);

	char* word1 = (char*)malloc(sizeof(char) * (strlen(input1) + 1));
	char* word2 = (char*)malloc(sizeof(char) * (strlen(input1) + 1));
	char* word3 = (char*)malloc(sizeof(char) * (strlen(input1) +strlen(input2) + 1));

	strcpy(word1, input1);
	strcpy(word2, input2);
	strcpy(word3, word1);
	strcat(word3, word2);

	printf("1 : %s\n", word1);
	printf("2 : %s\n", word2);
	printf("3 : %s\n", word3);

	free(word1);
	free(word2);
	free(word3);

	return 0;
}