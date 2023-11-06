#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float grade2float(char * temp){

    float grade = 0;

    if(temp[0] == 'A')
        grade = 4.0;
    else if(temp[0] == 'B')
        grade = 3.0;
    else if(temp[0] == 'C')
        grade = 2.0;
    else if(temp[0] == 'D')
        grade = 1.0;
    else
        grade = 0;

    if(temp[1] == '+')
        grade += 0.5;

    return grade;
}

int main(void){
    
    FILE * fs = fopen("grade.txt", "r");
    char input[100] = {'\0'};
    char* lecture[7] = {0,};
    int credit[7];
    float grade[7];

    char * tok_result = NULL;

    int tot_credit = 0;
    float tot_grade = 0;

    fgets(input, 100, fs);
    int idx = 0;
    for(fgets(input, 100, fs); !feof(fs); fgets(input, 100, fs)){
        tok_result = strtok(input, "\t\n");
        lecture[idx] = malloc(sizeof(char) * strlen(tok_result) + 1);
        strcpy(lecture[idx], tok_result);

        tok_result = strtok(NULL, "\t\n");
        credit[idx] = (int)tok_result[0]%49 + 1;

        tok_result = strtok(NULL, "\t\n");
        grade[idx] = grade2float(tok_result);
        idx++;
    }

    for(int i = 0; i< 7 ; i++){
        printf("%s, %0.1f\n", lecture[i], credit[i] * grade[i]);
        tot_credit += credit[i];
        tot_grade += grade[i] * credit[i];
    }

    printf("총 이수 학점 : %d, 총 평점 : %0.3f\n", tot_credit, tot_grade/tot_credit);

    fclose(fs);
    return 0;
}