#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char input[100] = { 0, };

    char* output[2] = { 0, };

    printf("Input the String : ");
    scanf("%s", input);

    output[0] = (char*)malloc(sizeof(char) * strlen(input) + 1);
    output[1] = (char*)malloc(sizeof(char) * strlen(input) + 1);

    int i = 0;

    for (i = 0; i < strlen(input); i++) {
        if (input[i] >= 65 && input[i] <= 90) {
            output[0][i] = input[i];
            output[1][i] = input[i] + 32;
        }
        else {
            output[0][i] = input[i] - 32;
            output[1][i] = input[i];
        }
    }

    output[0][i] = '\0';
    output[1][i] = '\0';

    printf("Upper Case : ");
    for (int j = 0; j < strlen(input); j++) {
        printf("%c", output[0][j]);
    }
    printf("\n");

    printf("Lower Case  : ");
    for (int j = 0; j < strlen(input); j++) {
        printf("%c", output[1][j]);
    }
    printf("\n");

    return 0;
}