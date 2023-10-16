#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void my_strcmp(char* A, char* B) {
    if (strlen(A) != strlen(B)) {
        printf("False!\n");
        return;
    }
    else {
        for (int i = 0; i < strlen(A); i++) {
            if ((A[i] - B[i]) == 32 || (B[i] - A[i]) == 32 || A[i] == B[i]) {
                continue;
            }
            else {
                printf("False!\n");
                return;
            }
        }
    }
    printf("True!\n");
    return;
}

int main()
{
    char input[100] = { 0, };
    char* p[2];
    int i = 0;
    while (i < 2) {
        scanf("%s", input);
        p[i] = (char*)malloc(sizeof(char) * (strlen(input) + 1));
        strcpy(p[i], input);
        p[i][strlen(input)] = '\0';
        i += 1;
    }

    my_strcmp(p[0], p[1]);

    free(p[0]);
    free(p[1]);

    return 0;
}