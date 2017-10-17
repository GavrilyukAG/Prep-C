#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// #include <boolean.h>
#define TRUE 1
#define FALSE 0
#define STRUCTURE_CAP 10

typedef struct Table{
    int count;
    char* printWords;
}Table;

void deletePunct(char* word){                 //удаляем знаки препинания после слова
    if (ispunct(word[strlen(word) - 1]))
        word[strlen(word) - 1] = '\0';
}

int checkWord(Table* Words, char* word, int counter){   //проверяем есть ли данное слово в таблице 
    for (int i = 0; i < counter; i++){
        if (strcmp(Words[i].printWords, word) == 0){
            return 1;
        }
    }
    return 0;
}

int numberOfRepeats(Table* Words, char** fileName, int fileNumber, int size){  //количество уникальных слов во всех файлах
    char* currentWord = (char*) malloc(sizeof(char*) * 1024);
    FILE* f;

    for (int i = 0; i < fileNumber; i++){
        f = fopen(fileName[i], "r");
        if (!f){
            printf("Error: file doesn't exist");
            return 1;
        }

        while (fscanf(f, "%s", currentWord) != EOF){
            deletePunct(currentWord);
            for (int counter = 0; counter < size; counter++){
                if (strcmp(Words[counter].printWords, currentWord) == 0){
                    Words[counter].count++;
                    break;
                }
                
            }
        }
        fclose(f);
    }
    free(currentWord);
    return 0;
}

int identWords(Table* Words, char** fileName, int fileNumber, int n, int* size, int* cap){  //находим уникальные слова
    int isRecord = TRUE;
    int sizeOfStruct = 0;
    int countCurWordInFiles = 1;  //количество считанного слова в файлах(без повторения в каждом)
    char* curWord = (char*) malloc(sizeof(char*) * 1024);  //считанное слово из данного файла
    char* curWordNextF = (char*) malloc(sizeof(char*) * 1024);  //считанное слово из след. файла
    FILE* f;
    FILE* f1;

    for (int i = 0; i < fileNumber - 1; i++){
        f = fopen(fileName[i], "r");
        if (!f){
            printf("Error: file doesn't exist");
            return 1;
        }

        while (fscanf(f, "%s", curWord) != EOF){   
            countCurWordInFiles = 1;
            deletePunct(curWord);
            //printf("!!!!!%s", curWord);
            if (checkWord(Words, curWord, sizeOfStruct)){
                 continue;
                }

            for (int j = i + 1; j < fileNumber; j++){
                f1 = fopen(fileName[j], "r");
                if (!f1){
                    printf("Error: file doesn't exist");
                    return 1;
                }
                isRecord = TRUE;

                while (fscanf(f1, "%s", curWordNextF) != EOF){
                    deletePunct(curWordNextF);
                    //printf("-%s\n", curWordNextF);
                    if (checkWord(Words, curWordNextF, sizeOfStruct)) continue;

                    if (strcmp(curWord, curWordNextF) == 0 && isRecord){
                        countCurWordInFiles++;
                        isRecord = FALSE;
                        if (countCurWordInFiles > n){
                            strcpy(Words[sizeOfStruct].printWords, curWord);
                            //printf(">>>>%s\n",Words[size].printWords);
                            sizeOfStruct++;
                            if (sizeOfStruct == (*cap - 1)){
                                *cap *= 2;
                                Words = (Table*) realloc(Words, sizeof(Table) * (*cap));
                            }
                            break;
                        }
                    }
                }
                fclose(f1);
            }
        }
        fclose(f);
    }
    *size = sizeOfStruct;
    free(curWord);
    free(curWordNextF);

    return 0;
}
// fgets
// mmap
//set ds

void printStruct(Table* Words, int size){
    for (int i = 0; i < size; i++){
        printf("%s-%d\n", Words[i].printWords, Words[i].count);
    }
}

int main(int argc,char* argv[]){

    int n = atoi(argv[1]);//strto*
    int fileNumber = argc - 2;
    
    if(n >= fileNumber){
        printf("Error: N must be less than number of files");
        return 1;
    } else if(n < 1){
        printf("Error: N must be more than 1");
        return 1;
    } else if(fileNumber == 0){
        printf("Error: Enter files name");
        return 1;
    }

    char** fileName =  argv +2;
    

    int size = 0;
    int cap = STRUCTURE_CAP;
    Table* Words = NULL;
    Words =  malloc(sizeof(Table) * STRUCTURE_CAP);
    for (int i = 0; i < STRUCTURE_CAP; i++){
        Words[i].count = 0;
        Words[i].printWords = (char*) malloc(1024);
    }

    identWords(Words, fileName, fileNumber, n, &size, &cap);
    numberOfRepeats(Words, fileName, fileNumber, size);
    printStruct(Words, size);

    for (int i = 0; i < fileNumber; i++){
        free(fileName[i]);
    }
    free(fileName);

    for (int i = 0; i < cap; i++){
        free(Words[i].printWords);
    }
    free(Words);
    
    return 0;
}