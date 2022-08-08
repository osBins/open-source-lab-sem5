#include <stdio.h>
#include <string.h>

int main() {
  // Take input from player1 for player2 to guess//
  char word[100];
  printf("PLAYER 1:Enter word to guess: ");
  scanf(" %s", word);

  printf("PLAYER 2:Guess the word  ");
  // Take a string "hidden" to print the value of "word" and print them on basis
  // of whether they are true or not//
  int N = strlen(word);
  int hidden[N];
  for (int i = 0; i < N; ++i) {
    hidden[i] = 0;
  }
  int gameover = 0;
  // The loop for the entire game//
  while (!gameover) {
    // Loop to print * in place of the letter if not guessed yet using fallacy
    // and tautology//
    printf("The word is : ");
    for (int j = 0; j < N; ++j) {
      if (hidden[j]) {
        printf("%c", word[j]);
      } else {
        printf("*");
      }
    }
    printf("\n");

    // Input of letter and loop to determine the status of "hidden " by equating
    // it to the guess//
    char guess;
    printf("Letter? ");
    scanf(" %c", &guess);

    for (int k = 0; k < N; ++k) {
      if (word[k] == guess) {
        hidden[k] = 1;
      }
    }
    // Loop to check whether game is over or not//
    gameover = 1;
    for (int m = 0; m < N; ++m) {
      if (!hidden[m]) {
        gameover = 0;
        break;
      }
    }
  }
  // Winning statement//
  printf("Congrats you're AWESOME! The word is \"%s\".\n", word);

  return 0;
}