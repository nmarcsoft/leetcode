#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

void add(struct ListNode *l1) {
  struct ListNode *toAdd = malloc(sizeof(struct ListNode));
  toAdd->next = NULL;
  toAdd->val = 0;

  l1->next = toAdd;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {

  struct ListNode *toReturn = malloc(sizeof(struct ListNode));
  toReturn->next = NULL;

  if (toReturn == NULL)
    return NULL;

  struct ListNode *cpy = toReturn;
  struct ListNode *l1cpy = l1;
  struct ListNode *l2cpy = l2;

  int toAdd = 0;
  int value = 0;

  while (l1cpy != NULL && l2cpy != NULL) {
    value = l1cpy->val + l2cpy->val + toAdd;

    if (value >= 10) {
      toAdd = 1;
      cpy->val = value % 10;
    } else {
      toAdd = 0;
      cpy->val = value;
    }

    l1cpy = l1cpy->next;
    l2cpy = l2cpy->next;
    if (l1cpy || l2cpy) {
      add(cpy);
      cpy = cpy->next;
    }
  }

  while (l1cpy != NULL) {
    value = l1cpy->val + toAdd;

    if (value >= 10) {
      toAdd = 1;
      cpy->val = value % 10;
    } else {
      toAdd = 0;
      cpy->val = value;
    }
    l1cpy = l1cpy->next;
    if (l1cpy) {
      add(cpy);
      cpy = cpy->next;
    }
  }

  while (l2cpy != NULL) {
    value = l2cpy->val + toAdd;

    if (value >= 10) {
      toAdd = 1;
      cpy->val = value % 10;
    } else {
      toAdd = 0;
      cpy->val = value;
    }
    l2cpy = l2cpy->next;
    if (l2cpy) {
      add(cpy);
      cpy = cpy->next;
    }
  }

  if (toAdd != 0) {
    add(cpy);
    cpy->next->val = toAdd;
  }

  return toReturn;
}
