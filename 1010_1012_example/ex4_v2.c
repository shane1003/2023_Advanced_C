#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rome_cat(char** rome, int mode, int num) {

    char rome_alphabet[3][4][3] = { { {'C'}, {"CD"}, {'D'}, {"CM"} } , { {'X'}, {"XL"}, {'L'}, {"XC"} }, { {'I'}, {"IV"}, {'V'}, {"IX"} } };

    char alphabet[5] = { 0, };


    int i = 0;
    if (num < 4)
        for (i = 0; i < num; i++)
            strcat(alphabet, rome_alphabet[mode][0]);
    else if (num == 4)
        strcat(alphabet, rome_alphabet[mode][1]);
    else if (num >= 5 && num < 9)
    {
        strcat(alphabet, rome_alphabet[mode][2]);
        for (i = 0; i < (num - 5); i++)
            strcat(alphabet, rome_alphabet[mode][0]);
    }
    else strcat(alphabet, rome_alphabet[mode][3]);


    if (*rome == NULL) {
        *rome = (char*)malloc(sizeof(char) * (strlen(alphabet) + 1));
        strcpy(*rome, alphabet);
        return;
    }
    else {
        char* temp = NULL;
        temp = (char*)realloc(*rome, sizeof(char) * (strlen(*rome) + strlen(alphabet) + 1));
        if (temp != NULL)
            *rome = temp;
        strcat(*rome, alphabet);
        return;
    }

    return;

}

int main() {
    int num;;
    char* rome = NULL;

    printf("Number : ");
    scanf("%d", &num);

    //각 자리수 구하기
    int thous = num / 1000;
    int num_split[] = { (num % 1000) / 100, (num % 100) / 10, (num % 10) };
    int cnt = 0;
    int print_num[2] = { 0,0 };

    print_num[0] = num_split[0] != 0 ? num_split[0] * 100 : (num_split[1] != 0 ? num_split[1] * 10 : num_split[2]);
    print_num[1] = num_split[1] != 0 ? num_split[1] * 10 : num_split[2];

    if (thous == 1) { //1000
        printf("1000 = M, 1");
        return 0;
    }
    else {
        for (int i = 0; i < 3; i++) {
            if (num_split[i] != 0) {
                rome_cat(&rome, i, num_split[i]);
                cnt++;
            }
        }

        switch (cnt) {
        case 3:
            printf("%d = %d + %d + %d = %s, %d", num, (num % 1000) / 100 * 100, (num % 100) / 10 * 10, (num % 10), rome, strlen(rome));
            break;
        case 2:
            printf("%d = %d + %d = %s, %d", num, print_num[0], print_num[1], rome, strlen(rome));
            break;
        case 1:
            printf("%d = %s, %d", print_num[0], rome, strlen(rome));
            break;
        }
    }

    return 0;
}
