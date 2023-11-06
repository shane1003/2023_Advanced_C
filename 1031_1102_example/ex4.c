#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strcmp(char *A, char *B){

    char tmp_A[20];
    char tmp_B[20];
    strcpy(tmp_A, A);
    strcpy(tmp_B, B);

    if(A[0] >= 'A' && A[0] <= 'Z')
        tmp_A[0] += 32;

    if(B[0] >= 'A' && B[0] <= 'Z')
        tmp_B[0] += 32;
    
    return strcmp(tmp_A, tmp_B);
}

int word2dict(char * input, char ** dictionary, int idx){
    int i = 0, j = 0;

    char word[30] = {0, };
    
    while(1){

        if( input[i] == '\t' || input[i] == ';' || input[i] >= '|' || input[i] == ',' || input[i] == '\n' || input[i] == '\0'){
            word[j] = '\0';
            j = 0;
            //printf("%d, %s\n", strlen(word), word);
            if(strlen(word) != 0) {
                dictionary[idx] = (char*)malloc(sizeof(char) * strlen(word) + 1);
                strcpy(dictionary[idx], word);
                idx++;
                //i++;
            }
            if(input[i] == '\0')
                break;
            i++;
        }
            
        else{
            word[j] = input[i];
            i++;
            j++;
        } 

    }

    return idx;
}

void make_dictionary(char ** dictionary){

    char * temp = NULL;

    for (int i = 0; i < 33 ; i++){
        for (int j = 0; j < 33 - 1 - i ; j++){
            if(my_strcmp(dictionary[j], dictionary[j+1]) > 0){
                //printf("%s, %s\n", *(dictionary+j), *(dictionary+j+1));
                temp = *(dictionary + j);
                *(dictionary + j) = *(dictionary + j + 1);
                *(dictionary + j + 1) = temp;
            }
        }
    }
}

int main(void){
    
    FILE * file = fopen("words.txt", "r");

    char *dictionary[33] = {0,};

    int idx = 0;
    while(!feof(file)){
        char input[100] = {0, };
        fgets(input, 100, file);

        input[strlen(input)-1] = '\0';
        if(input[strlen(input)-1] != '\0')
            input[strlen(input)-1] = '\0';

        if (strlen(input) != 0){
            //printf("%s\n", input);
            idx = word2dict(input, &(*dictionary), idx);
        }
    }

    make_dictionary(&(*dictionary));

    for(int k = 0;  k<33; k++){
        printf("%s\n", dictionary[k]);
    }
}