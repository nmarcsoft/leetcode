#include <cstddef>
#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode head = ListNode();
    ListNode *current = &head;

    while (list1 && list2) {
      if (list1->val < list2->val) {
        current->val = list1->val;
        list1 = list1->next;
      } else {
        current->val = list2->val;
        list2 = list2->next;
      }

      current = current->next;
    }

    if (list1) {
      current->next = list1;
    } else {
      current->next = list2;
    }

    return head.next;
  }

  ListNode *createList(const std::vector<int> &vals) {
    if (vals.empty())
      return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
      current->next = new ListNode(vals[i]);
      current = current->next;
    }
    return head;
  }
};

int main(void) {
  Solution solution;
  solution.mergeTwoLists(NULL, NULL);
}
