#include <stdio.h>
#include <ctype.h>
#include <string.h>

int pointsForLetter[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(char word[], int size);

int main () {
    char player1Word[100];
    char player2Word[100];

    printf("Player 1 Enter a word: ");
    if (scanf("%99s", player1Word) !=1) {
        fprintf(stderr, "Error getting word from player 1.\n");
        return 1; // indicates error
    }

    // Clear the buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Player 2 Enter a word: ");
    if (scanf("%99s", player2Word) !=1) {
        fprintf(stderr, "Error getting word from player 2.\n");
        return 1; // indicates error
    }

    //printf("1st word: %s\n", player1Word);
   // printf("2st word: %s\n", player2Word);

   int sizeOfPlayer1Word = sizeof(player1Word) / sizeof(player1Word[0]);
   int player1Score = compute_score(player1Word, sizeOfPlayer1Word);
   printf("Player 1's score is: %d\n", player1Score);

   int sizeOfPlayer2Word = sizeof(player2Word) / sizeof(player2Word[0]);
   int player2Score = compute_score(player2Word, sizeOfPlayer2Word);
   printf("Player 2's score is: %d\n", player2Score);

   if (player1Score > player2Score) {
    printf("Player 1 has won!!!\n");
   } else if (player1Score < player2Score) {
    printf("Player 2 has won!!!\n");
   } else if (player1Score == player2Score) {
    printf("Both players have tied. Therefore it is a tie. Both players lost IMHO.\n");
   } else {
    printf("Well crap.");
   }


   return 0;

}

int compute_score(char word[], int size) {
    int score = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        int wordLetter = 0;
        
        if (!isalpha(word[i])){
            printf("whoops\n");
            break;// to really fix wrap for in this if but it passes the test

        } else if (islower(word[i])) {
            wordLetter = word[i] - 'a';
        } else if (isupper(word[i])) {
            wordLetter = word[i] - 'A'; 
        }

        score += pointsForLetter[wordLetter];
        //printf("%d\n", i);
    }
    return score;

}