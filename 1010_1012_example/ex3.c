#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{   
    char input[100];
    int rows = 0;
    printf("How many lines ? ");
    scanf("%d", &rows);

    char** p = (char**)malloc(sizeof(char*) * rows);

    int max = 0;
    for (int i = 0; i < rows; i++){
        scanf("%s", input);
        p[i] = (char*)malloc(sizeof(char) * (strlen(input) + 1));
        strcpy(p[i], input);
        p[i][strlen(input)] = '\0';

        if (max < strlen(input))
            max = strlen(input);
    }

    for (int i = 0; i < max; i++) {
        for (int j = 0; j < rows; j++) {
            if (i < strlen(p[j]))
                printf("%c", p[j][i]);
        }
    }

    for (int i = 0; i < rows; i++) {
        free(p[i]);
    }
    free(p);

    return 0;
}