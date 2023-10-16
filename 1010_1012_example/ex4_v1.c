#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rome_cat(char** rome, const char* alphabet) {

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

}

int main() {
    int num, thous, hund, ten, one;
    int i;

    char** rome = NULL;

    printf("Number : ");
    scanf("%d", &num);

    //각 자리수 구하기
    thous = num / 1000;
    hund = (num % 1000) / 100;
    ten = (num % 100) / 10;
    one = (num % 10);


    //1000의자리
    if (num == 1000)
        rome_cat(&rome, "M");

    //100의 자리
    if (hund < 4)
        for (i = 0; i < hund; i++)
            rome_cat(&rome, "C");
    else if (hund == 4)
        rome_cat(&rome, "CD");
    else if (hund >= 5 && hund < 9)
    {
        rome_cat(&rome, "D");
        for (i = 0; i < (hund - 5); i++)
            rome_cat(&rome, "C");
    }
    else rome_cat(&rome, "CM");


    //10의 자리
    if (ten < 4)
        for (i = 0; i < ten; i++)
            rome_cat(&rome, "X");
    else if (ten == 4)
        rome_cat(&rome, "XL");
    else if (ten >= 5 && ten < 9)
    {
        rome_cat(&rome, "L");
        for (i = 0; i < (ten - 5); i++)
            rome_cat(&rome, "X");
    }
    else rome_cat(&rome, "XC");


    //1의자리
    if (one < 4)
        for (i = 0; i < one; i++)
            rome_cat(&rome, "I");
    else if (one == 4)
        rome_cat(rome, "IV");
    else if (one >= 5 && one < 9)
    {
        rome_cat(&rome, "V");
        for (i = 0; i < (one - 5); i++)
            rome_cat(&rome, "I");
    }
    else rome_cat(&rome, "IX");

    if (thous == 1) { //1000
        printf("%d = %s, %d", thous*1000, rome, strlen(rome));
    }
    else {
        if (hund == 0) {
            if (ten == 0)  // 1의 자리만
                printf("%d = %s, %d", num, rome, strlen(rome));
            else {
                if (one == 0) // 10의 자리만
                    printf("%d = %s, %d", num, rome, strlen(rome));
                else //10의자리, 1의자리
                    printf("%d = %d + %d = %s, %d", num, ten * 10, one, rome, strlen(rome));
            }
        }
        else {
            if (ten == 0) {
                if(one == 0) // 100의 자리만
                    printf("%d = %s, %d", num, rome, strlen(rome));

                else //100의 자리, 1의 자리
                    printf("%d = %d + %d = %s, %d", num, hund * 100, one, rome, strlen(rome));
            }
            else {
                if (one == 0) //100의 자리, 10의 자리
                    printf("%d = %d + %d = %s, %d", num, hund * 100, ten * 10, rome, strlen(rome));

                else //100의 자리, 10의 자리, 1의 자리
                    printf("%d = %d + %d + %d = %s, %d", num, hund * 100, ten * 10, one, rome, strlen(rome));
            }
        }

    }

    return 0;
}
