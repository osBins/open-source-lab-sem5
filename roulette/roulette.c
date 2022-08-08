#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
  int const MIN_NUMBER = 1, MAX_NUMBER = 36;
  int number, random;
  double bet, winnings = 0;

  char gametype;
  char oddeven, ch;

  do { // Main Menu
    printf("Welcome to ROULETTE\n\n");
    printf("How much would you like to bet? (in $)\n");
    scanf("%lf", &bet);
    printf(
        "Would you like to bet on a specific number(N) or on odd/even(O):\n");
    scanf(" %c", &gametype);
    if (gametype == 'n' || gametype == 'N') {
      printf("What number would you like to bet on?\n");
      scanf("%d", &number);
      if (number == 00)
        number = 37;

      srand(time(NULL));
      printf("Spinning...\n");
      sleep(3);
      random = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;

      printf("The ball landed on %d \n", random);

      if (number != random) {
        printf("You lose $%.2lf \n", bet);
        winnings -= bet;
      }

      else {
        printf("You win $%.2lf \n", 35 * bet);
        winnings += 35 * bet;
      }
    }

    // User selects even or odd
    if (gametype == 'o' || gametype == 'O') {
      printf("Would you like to bet on even (E) or odd (O)?:  ");
      scanf(" %c", &oddeven);
      srand(time(NULL));
      printf("Spinning...\n");
      sleep(3);
      random = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
      printf("The ball landed on: %d \n", random);

      // User bets on even
      if (oddeven == 'E' || oddeven == 'e') {
        // Even win
        if (random % 2 == 0) {
          printf("You win $%.2lf\n", 2 * bet);
          winnings += 2 * bet;
        }
        // Even lose
        else {
          printf("You lose $%.2lf\n", bet);
          winnings -= bet;
        }
      }
      // If User bets for Odd
      if (oddeven == 'O' || oddeven == 'o') {
        // Odd win
        if (random % 2 != 0) {
          printf("You win $%.2lf\n", 2 * bet);
          winnings += 2 * bet;
        }
        // Odd lose
        else {
          printf("You lose $%.2lf\n\n", bet);
          winnings -= bet;
        }
      }
    }
    printf("You now have a total of $%.2lf", winnings);
    printf("\nDo you want to play again?(Y/N):  ");
    scanf(" %c", &ch);
    system("clear");
  } while (ch == 'Y' || ch == 'y');

  return 0;
}