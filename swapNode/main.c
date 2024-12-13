// https://leetcode.com/problems/swap-nodes-in-pairs/description/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode {
  int val;
  struct ListNode *next;
};

void debug_print(struct ListNode *toPrint) {
  int i = 0;
  while (toPrint != NULL) {
    printf("%d: %d\n", i, toPrint->val);
    i++;
    toPrint = toPrint->next;
  }
}

void swapper(struct ListNode *a, struct ListNode *b) {
  struct ListNode *tmp = b->next;
  b->next = a;
  a->next = tmp;
}

struct ListNode *swapPairs(struct ListNode *head) {
  if (head == NULL)
    return NULL;

  if (head->next == NULL)
    return head;

  struct ListNode *toReturn = head->next;

  struct ListNode *current = head;
  struct ListNode *next = current->next;
  struct ListNode *linker = NULL;
  next = current->next;
  int i = 0;

  while (next != NULL) {
    if (i % 2 == 0) {
      current->next = next->next;
      next->next = current;
      if (linker)
        linker->next = next;
    } else {
      linker = current;
      current = current->next;
      if (!current)
        return toReturn;
      next = current->next;
    }
    i++;
  }
  return toReturn;
}

int main(void) {
  struct ListNode *head = malloc(sizeof(struct ListNode));
  head->val = 1;
  head->next = NULL;

  head = swapPairs(head);
  debug_print(head);

  struct ListNode *node1 = malloc(sizeof(struct ListNode));
  node1->val = 2;
  head->next = node1;
  node1->next = NULL;

  struct ListNode *node2 = malloc(sizeof(struct ListNode));
  node2->val = 3;
  node1->next = node2;
  node2->next = NULL;
  head = swapPairs(head);

  struct ListNode *node3 = malloc(sizeof(struct ListNode));
  node3->val = 4;
  node2->next = node3;
  node3->next = NULL;
  head = swapPairs(head);

  debug_print(head);
}
