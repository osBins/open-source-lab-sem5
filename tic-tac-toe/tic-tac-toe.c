#include <stdio.h>

void currentStatus();
int winningCondition();

char matrix[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main() {
  char option;
ttt:
  if (option == 'y') {
    char matrix[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  }

  // welcome message
  printf("Welcome to Tic-Tac-Toe\n\n\n");

  int index, p = 1, i;
  char token;

  // check validity of position number specified by player and assign token to
  // it
  do {
    currentStatus();
    // decide which player's move it is
    p = (p % 2) ? 1 : 2;

    printf("Player #%d's move", p);
    scanf("%d", &index);
    token = (p == 1) ? 'X' : 'O';

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
    else {
      printf("Please enter an unoccupied/valid position number\n");
      p--;
    }
    i = winningCondition();
    p++;
  } while (i == 2);

  currentStatus();

  if (i == 1) {
    --p;
    printf("Player #%d wins\n", p);
  } else
    printf("Draw\n");

  printf("Do you want to play again?(y/n)\n");
  fflush(stdin);
  scanf(" %c", &option);
  if (option == 'y') {
    goto ttt;
  }
  return 0;
}
int winningCondition() {
  if (matrix[1] == matrix[2] && matrix[2] == matrix[3])
    return 1;
  else if (matrix[4] == matrix[5] && matrix[5] == matrix[6])
    return 1;
  else if (matrix[7] == matrix[8] && matrix[8] == matrix[9])
    return 1;
  else if (matrix[1] == matrix[4] && matrix[4] == matrix[7])
    return 1;
  else if (matrix[2] == matrix[5] && matrix[5] == matrix[8])
    return 1;
  else if (matrix[3] == matrix[6] && matrix[6] == matrix[9])
    return 1;
  else if (matrix[1] == matrix[5] && matrix[5] == matrix[9])
    return 1;
  else if (matrix[3] == matrix[5] && matrix[5] == matrix[7])
    return 1;
  else if (matrix[1] != '1' && matrix[2] != '2' && matrix[3] != '3' &&
           matrix[4] != '4' && matrix[5] != '5' && matrix[6] != '6' &&
           matrix[7] != '7' && matrix[8] != '8' && matrix[9] != '9')
    return 0;
  else
    return 2;
}
void currentStatus() {
  printf("[ %c ] [ %c ] [ %c ]\n", matrix[1], matrix[2], matrix[3]);
  printf("\n");
  printf("[ %c ] [ %c ] [ %c ]\n", matrix[4], matrix[5], matrix[6]);
  printf("\n");
  printf("[ %c ] [ %c ] [ %c ]\n", matrix[7], matrix[8], matrix[9]);
  printf("\n");
}