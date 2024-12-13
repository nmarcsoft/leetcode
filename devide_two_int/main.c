#include <stdio.h>

// TODO : Les limites
int divide(int dividend, int divisor) {
  int sign = 1;
  if (dividend < 0) {
    if (divisor > 0) {
      sign = -1;
      dividend = -dividend;
    } else {
      dividend = -dividend;
      divisor = -divisor;
    }
  } else {
    if (divisor < 0) {
      sign = -1;
      divisor = -divisor;
    }
  }

  if (dividend < divisor)
    return 0;

  if (divisor == 1) {
    if (sign > 0)
      return dividend;
    return dividend;
  }

  int toReturn = 0;
  while (dividend > 1) {
    dividend -= divisor;
    toReturn++;
  }
  if (sign > 0)
    return toReturn;
  return -toReturn;
}

int main(void) {
  printf("(3) : %d\n", divide(10, 3));
  printf("(-2) : %d\n", divide(7, -3));
  printf("(-2) : %d\n", divide(-1, -1));
  return 0;
}
