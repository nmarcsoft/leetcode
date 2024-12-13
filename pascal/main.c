/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **generate(int numRows, int *returnSize, int **returnColumnSizes) {

  returnColumnSizes = malloc(sizeof(int *) * numRows);

  for (int i = 0; i < numRows; i++) {
    int *toPut = calloc(sizeof(int), numRows);
    for (int j = 0; j < numRows / 2; j++)
      memcpy(returnColumnSizes[i], toPut, numRows);
  }

  return returnColumnSizes;
}
