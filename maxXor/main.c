/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void debug_print(int *getter, size_t size) {
  for (int i = 0; i < size; i++) {
    printf("%d: %d\n", i, getter[i]);
  }
}

int *getMaximumXor(int *nums, int numsSize, int maximumBit, int *returnSize) {
  returnSize = malloc(sizeof(int) * numsSize);

  int id = 0;
  for (int i = numsSize - 1; i >= 0; i--) {
    int xorCurrent = 0;
    int maximum = 0;
    for (int j = 0; j <= i; j++) {
      xorCurrent = xorCurrent ^ nums[j];
    }
    for (int k = 0; k < 1 << maximumBit; k++) {
      if ((xorCurrent ^ k) > maximum) {
        maximum = xorCurrent ^ k;
        returnSize[id] = k;
      }
      if (k == 0)
        k = k | 1;
    }
    id++;
  }

  return returnSize;
}

int main(void) {
  printf("------ TEST1 ------\n");
  int test[4] = {0, 1, 1, 3};
  int *getter = getMaximumXor(test, 4, 2, NULL);
  debug_print(getter, 4);
  printf("------ TEST2 ------\n");
  int test2[4] = {2, 3, 4, 7};
  getter = getMaximumXor(test2, 4, 3, NULL);
  debug_print(getter, 4);
  free(getter);
  return 0;
}
