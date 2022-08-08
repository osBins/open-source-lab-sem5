#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Code for Tic-Tac-Toe
void tictactoe()

{

  // welcome message
  char ch;
  do
  {
    char matrix[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    printf("Welcome to Tic-Tac-Toe\n\n\n");

    int index, p = 1, i;
    char token;

    // check validity of position number specified by player and assign token to
    // it
    do
    {
      printf("[ %c ] [ %c ] [ %c ]\n", matrix[1], matrix[2], matrix[3]);
      printf("\n");
      printf("[ %c ] [ %c ] [ %c ]\n", matrix[4], matrix[5], matrix[6]);
      printf("\n");
      printf("[ %c ] [ %c ] [ %c ]\n", matrix[7], matrix[8], matrix[9]);
      printf("\n");
      // decide which player's move it is
      p = (p % 2) ? 1 : 2;

      printf("Player #%d's move", p);
      scanf("%d", &index);
      token = (p == 1) ? 'X' : 'O';

      // assign token to position chosen

      if (index == 1 && matrix[1] == '1')
        matrix[1] = token;
      else if (index == 2 && matrix[2] == '2')
        matrix[2] = token;
      else if (index == 3 && matrix[3] == '3')
        matrix[3] = token;
      else if (index == 4 && matrix[4] == '4')
        matrix[4] = token;
      else if (index == 5 && matrix[5] == '5')
        matrix[5] = token;
      else if (index == 6 && matrix[6] == '6')
        matrix[6] = token;
      else if (index == 7 && matrix[7] == '7')
        matrix[7] = token;
      else if (index == 8 && matrix[8] == '8')
        matrix[8] = token;
      else if (index == 9 && matrix[9] == '9')
        matrix[9] = token;
      else
      {
        printf("Please enter an unoccupied/valid position number\n");
        p--;
      }

      // check winning condition

      if (matrix[1] == matrix[2] && matrix[2] == matrix[3])
        i = 1;
      else if (matrix[4] == matrix[5] && matrix[5] == matrix[6])
        i = 1;
      else if (matrix[7] == matrix[8] && matrix[8] == matrix[9])
        i = 1;
      else if (matrix[1] == matrix[4] && matrix[4] == matrix[7])
        i = 1;
      else if (matrix[2] == matrix[5] && matrix[5] == matrix[8])
        i = 1;
      else if (matrix[3] == matrix[6] && matrix[6] == matrix[9])
        i = 1;
      else if (matrix[1] == matrix[5] && matrix[5] == matrix[9])
        i = 1;
      else if (matrix[3] == matrix[5] && matrix[5] == matrix[7])
        i = 1;
      else if (matrix[1] != '1' && matrix[2] != '2' && matrix[3] != '3' &&
               matrix[4] != '4' && matrix[5] != '5' && matrix[6] != '6' &&
               matrix[7] != '7' && matrix[8] != '8' && matrix[9] != '9')
        i = 0;
      else
        i = 2;
      p++;
    } while (i == 2);

    // print current status of matrix

    printf("[ %c ] [ %c ] [ %c ]\n", matrix[1], matrix[2], matrix[3]);
    printf("\n");
    printf("[ %c ] [ %c ] [ %c ]\n", matrix[4], matrix[5], matrix[6]);
    printf("\n");
    printf("[ %c ] [ %c ] [ %c ]\n", matrix[7], matrix[8], matrix[9]);
    printf("\n");

    if (i == 1)
    {
      --p;
      printf("Player #%d wins\n", p);
      sleep(1);
      printf("Do you want to play again? (Y/N):  ");
      scanf(" %c", &ch);
      sleep(1);
      system("cls");
    }
    else
    {
      printf("Draw\n");
      sleep(1);
      printf("Do you want to play again? (Y/N):  ");
      scanf(" %c", &ch);
      sleep(1);
      system("cls");
    }
  } while (ch == 'y' || ch == 'Y');
}

// Code for Hangman game
void Hangman()

{
  char ch;
  do
  {
    // Take input from player1 for player2 to guess//
    char word[100];
    printf("PLAYER 1:Enter word to guess: ");
    scanf(" %s", word);
    sleep(1);
    system("cls");

    printf("PLAYER 2:Guess the word  ");
    // Take a string "hidden" to print the value of "word" and print them on
    // basis of whether they are true or not//
    int N = strlen(word);
    int hidden[N];
    for (int i = 0; i < N; ++i)
    {
      hidden[i] = 0;
    }
    int gameover = 0;
    // The loop for the entire game//
    while (!gameover)
    {
      // Loop to print * in place of the letter if not guessed yet using fallacy
      // and tautology//
      printf("The word is : ");
      for (int j = 0; j < N; ++j)
      {
        if (hidden[j])
        {
          printf("%c", word[j]);
        }
        else
        {
          printf("*");
        }
      }
      printf("\n");

      // Input of letter and loop to determine the status of "hidden " by
      // equating it to the guess//
      char guess;
      printf("Letter? ");
      scanf(" %c", &guess);

      for (int k = 0; k < N; ++k)
      {
        if (word[k] == guess)
        {
          hidden[k] = 1;
        }
      }
      // Loop to check whether game is over or not//
      gameover = 1;
      for (int m = 0; m < N; ++m)
      {
        if (!hidden[m])
        {
          gameover = 0;
          break;
        }
      }
    }
    // Winning statement//
    printf("Congrats you're AWESOME! The word is \"%s\".\n", word);
    printf("Do you want to play again? (Y/N):  ");
    scanf(" %c", &ch);
    system("cls");
    sleep(1);
  } while (ch == 'Y' || ch == 'y');
}

// Code for Roulette game
void Roulette()
{
  int const MIN_NUMBER = 1, MAX_NUMBER = 36;
  int number, random;
  double bet, winnings = 0;

  char gametype;
  char oddeven, ch;

  do
  { // Main Menu
    printf("Welcome to ROULETTE\n\n");
    printf("How much would you like to bet? (in $)\n");
    scanf("%lf", &bet);
    printf(
        "Would you like to bet on a specific number(N) or on odd/even(O):\n");
    scanf(" %c", &gametype);
    if (gametype == 'n' || gametype == 'N')
    {
      printf("What number would you like to bet on?\n");
      scanf("%d", &number);
      srand(time(NULL));
      printf("Spinning...\n");
      sleep(3);
      random = (rand() % MAX_NUMBER) + MIN_NUMBER;

      printf("The ball landed on %d \n", random);

      if (number != random)
      {
        printf("You lose $%.2lf \n", bet);
        winnings -= bet;
      }

      else
      {
        printf("You win $%.2lf \n", 35 * bet);
        winnings += 35 * bet;
      }
    }

    // User selects even or odd
    if (gametype == 'o' || gametype == 'O')
    {
      printf("Would you like to bet on even (E) or odd (O)?:  ");
      scanf(" %c", &oddeven);
      srand(time(NULL));
      printf("Spinning...\n");
      sleep(3);
      random = (rand() % MAX_NUMBER) + MIN_NUMBER;
      printf("The ball landed on: %d \n", random);

      // User bets on even
      if (oddeven == 'E' || oddeven == 'e')
      {
        // Even win
        if (random % 2 == 0)
        {
          printf("You win $%.2lf\n", 2 * bet);
          winnings += 2 * bet;
        }
        // Even lose
        else
        {
          printf("You lose $%.2lf\n", bet);
          winnings -= bet;
        }
      }
      // If User bets for Odd
      if (oddeven == 'O' || oddeven == 'o')
      {
        // Odd win
        if (random % 2 != 0)
        {
          printf("You win $%.2lf\n", 2 * bet);
          winnings += 2 * bet;
        }
        // Odd lose
        else
        {
          printf("You lose $%.2lf\n\n", bet);
          winnings -= bet;
        }
      }
    }
    printf("You now have a total of $%.2lf", winnings);
    printf("\nDo you want to play again?(Y/N):  ");
    scanf(" %c", &ch);
    system("cls");
    sleep(1);
  } while (ch == 'Y' || ch == 'y');
}

int main()
{
  // Main Arcade Menu screen
Menu:;
  int i, j, space, rows = 10, k = 0;

  for (i = 1; i <= rows; ++i, k = 0)
  {
    for (space = 1; space <= rows - i; ++space)
    {
      printf("  ");
    }
    while (k != 2 * i - 1)
    {
      printf("* ");
      ++k;
    }
    printf("\n");
  }

  // MENU
  printf("     WELCOME TO THE GAMING ARCADE\n\n");

  printf("        THE AVAILABLE GAMES ARE\n\n            1)TIC-TAC-TOE\n\n     "
         "       2)HANGMAN\n\n            3)ROULETTE\n\n            4)EXIT "
         "ARCADE\n\n");

  for (i = rows; i >= 1; --i)
  {
    for (space = 0; space < rows - i; ++space)
      printf("  ");
    for (j = i; j <= 2 * i - 1; ++j)
      printf("* ");
    for (j = 0; j < i - 1; ++j)
      printf("* ");
    printf("\n");
  }

  int c;
Option:
  printf("ENTER THE DESIRED GAME\n");
  scanf("%d", &c);

  if (c == 1)
  {
    system("cls");
    tictactoe();
    goto Menu;
  }
  else if (c == 2)
  {
    system("cls");
    Hangman();
    goto Menu;
  }
  else if (c == 3)
  {
    system("cls");
    Roulette();
    goto Menu;
  }
  else if (c == 4)
  {
    exit(0);
  }
  else
  {
    printf("PLEASE ENTER A VALID OPTION!\n");
    goto Option;
  }

  return 0;
};
