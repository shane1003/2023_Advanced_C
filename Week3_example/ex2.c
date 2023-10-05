#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int input = 0;
	int i = 0;
	int* numbers = (int*)malloc(sizeof(int));

	for (i = 0;; i++) {
		printf("숫자 입력 : ");
		scanf("%d", &input);

		if (input == 0)
			break;
		else {
			if (i == 0)
				numbers[0] = input;
			else {
				numbers = (int*)realloc(numbers, sizeof(int) * (i + 1));
				numbers[i] = input;
			}
		}
	}

	int even_Sum = 0;

	for (int j = 0; j < i; j++)
		if (numbers[j] % 2 == 0)
			even_Sum += numbers[j];

	printf("짝수 숫자의 합 : %d", even_Sum);

	free(numbers);

	return 0;
}