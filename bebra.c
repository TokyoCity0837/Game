#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum{Max_Length = 8};

char* randWord(FILE* file, int length, char* string);

int main(){

    srand(time(NULL));

    int userNum = 0;
    char str[Max_Length];

    printf("Введите длину слова: ");
    scanf("%d", &userNum);

    FILE* list = fopen("dictionary.txt", "r");

    char* len = randWord(list, userNum, str);

    fclose(list);
    printf("%s\n", len);

}


char* randWord(FILE* file, int length, char* string) {
    int c;
    int i = 0;
    int count = 0;
    char temp[100];

    while ((c = fgetc(file)) != EOF) {
        if (c != '\n' && c != '\0') {
            if (i < sizeof(temp) - 1) {
                temp[i++] = c;
            }
        } else {
            temp[i] = '\0';
            if (strlen(temp) == length) {
                count++;
                if (rand() % count == 0) {
                    strcpy(string, temp);
                }
            }
            i = 0; 
        }
    }

    if (count == 0) return NULL;
    return string;
}