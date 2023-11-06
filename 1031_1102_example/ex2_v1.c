#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void input_split(char** lecture, int* credit, float* grade, char* input, int idx){
    char temp[30] = {0,};
    int i = 0;
    int j = 0;
    for(i, j=0; input[i]!='\t'; i++ , j++){
        temp[j] = input[i];
    }
    temp[j] = '\0';
    //printf("malloc\n");
    lecture[idx] = (char*)malloc(sizeof(char) * strlen(temp)+1);
    strcpy(lecture[idx], temp);

    for(j = 0; input[i]=='\t'; i++);

    for(i, j=0; input[i]!='\t'; i++ , j++){
        temp[j] = input[i];
    }
    temp[j] = '\0';
    credit[idx] = (int)temp[0]%49 + 1;

    for(j = 0; input[i]=='\t'; i++);

    for(i, j=0; input[i]!='\0'; i++ , j++){
        temp[j] = input[i];
    }
    temp[j] = '\0';

    if(temp[0] == 'A')
        grade[idx] = 4.0;
    else if(temp[0] == 'B')
        grade[idx] = 3.0;
    else if(temp[0] == 'C')
        grade[idx] = 2.0;
    else if(temp[0] == 'D')
        grade[idx] = 1.0;
    else
        grade[idx] = 0;


    if(temp[1] == '+')
        grade[idx] += 0.5;
}

int main(void){
    
    FILE * fs = fopen("grade.txt", "r");
    char input[100] = {'\0'};
    char* lecture[7] = {0,};
    int credit[7];
    float grade[7];

    int tot_credit = 0;
    float tot_grade = 0;

    fgets(input, 100, fs);
    int idx = 0;
    for(fgets(input, 100, fs); !feof(fs); fgets(input, 100, fs)){
        input[strlen(input)-1] = '\0';
        input_split(&(lecture), &(credit), &(grade), input, idx);
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