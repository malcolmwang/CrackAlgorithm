#include "../utils/ListNode.h"

ListNode* ReverseList(ListNode* head) {
  ListNode* reversedHead = nullptr;
  ListNode* node = head;
  ListNode* previousNode = nullptr;

  while (node) {
    ListNode* next = node->mNext;

    if (!next)
      reversedHead = node;
    node->mNext = previousNode;
    previousNode = node;
    node = next;
  }
  return reversedHead;
}

int main() {
  int a[] = {2, 6, 7, 0, 9, 3};
  PrintList(ReverseList(CreateListFromArray(a, sizeof(a) / sizeof(int))));
  return 0;
}
