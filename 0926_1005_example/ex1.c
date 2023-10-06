#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int num_Cnt = 0;

	printf("입력할 개수는? ");
	scanf("%d", &num_Cnt);

	int* numbers = (int*)malloc(sizeof(int) * num_Cnt);

	for (int i = 0; i < num_Cnt; i++) {
		printf("%d 번째 숫자 : ", i + 1);
		scanf("%d", &numbers[i]);
	}

	int even_Sum = 0;

	for (int i = 0; i < num_Cnt; i++) {
		if (numbers[i] % 2 == 0)
			even_Sum += numbers[i];
	}
	printf("입력한 짝수합 ==> %d\n", even_Sum);

	free(numbers);

	return 0;
}