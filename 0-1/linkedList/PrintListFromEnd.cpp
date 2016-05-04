#include <iostream>

#include "../utils/ListNode.h"

void PrintListReversingly(ListNode* head) {
  if (head) {
    if (head->mNext) {
      PrintListReversingly(head->mNext);
    }
    std::cout << head->mValue << std::endl;
  }
}

int main() {
  int a[] = {2, 6, 7, 0, 9, 3};
  PrintListReversingly(CreateListFromArray(a, sizeof(a) / sizeof(int)));
  return 0;
}
