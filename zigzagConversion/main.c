#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows) {
  int len = strlen(s);
  char *toReturn = (char *)malloc(len + 1);

  if (numRows <= 1)
    return s;

  int group = 2 * numRows - 2;
  int interval;
  int idx;
  int writer = 0;

  for (int i = 1; i < numRows + 1; i++) {
    if (i == numRows)
      interval = group;
    else
      interval = 2 * numRows - 2 * i;

    idx = i - 1;
    while (idx < len) {
      toReturn[writer] = s[idx];
      writer++;

      idx += interval;
      if (interval != group)
        interval = group - interval;
    }
  }
  toReturn[len] = '\0';
  return toReturn;
}
