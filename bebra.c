#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define NumOfTries 5

void generate(int length);
void playgame(char *gameword, int wordlen);

char gameword[100];

char alphabet[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u',
    'v', 'w', 'x', 'y', 'z'
};

int main() {
    int wordlen = 0;

    printf("Enter the length of the word: ");
    scanf("%d", &wordlen);

    srand(time(NULL));
    generate(wordlen);
    playgame(gameword, wordlen);

    return 0;
}

void generate(int length) {
    int LenAlph = sizeof(alphabet) / sizeof(alphabet[0]);

    for (int i = 0; i < length; i++) {
        int randomindex = rand() % LenAlph;

        if (i == 0) {
            gameword[i] = toupper(alphabet[randomindex]);
        } else {
            gameword[i] = alphabet[randomindex];
        }
    }

    gameword[length] = '\0';
}

void playgame(char *gameword, int wordlen) {

    char guess;
    char displayer[wordlen + 1]; 
    int triesLeft = NumOfTries;
    int guessedLetters[26]; 

    
    for (int i = 0; i < wordlen; i++) {
        displayer[i] = '_';
    }
    displayer[wordlen] = '\0';
    while (triesLeft > 0) {

        printf("\nWord: ");
        for (int i = 0; i < wordlen; i++) {
            printf("%c ", displayer[i]);
        }

        printf("\nTries left: %d\n", triesLeft);
        printf("Enter a letter: ");

        scanf(" %c", &guess);
        guess = tolower(guess);

        if (guessedLetters[guess - 'a']) {
            printf("You've already guessed '%c'. Try another.\n", guess);
            continue;
        }

        guessedLetters[guess - 'a'] = 1;

        int correct = 0;
        for (int i = 0; i < wordlen; i++) {
            if (tolower(gameword[i]) == guess) {
                displayer[i] = gameword[i];
                correct = 1;
            }
        }

        if (!correct) {
            triesLeft--;
            printf("Wrong guess!\n");
        }

    
        if (strcmp(displayer, gameword) == 0) {
            printf("\nCongratulations! You guessed the word: %s\n", gameword);
            return;
        }
    }

    printf("\nGame Over! The correct word was: %s\n", gameword);
}

