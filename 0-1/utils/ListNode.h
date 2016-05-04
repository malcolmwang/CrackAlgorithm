struct ListNode {
  int mValue;
  ListNode* mNext;
};

ListNode* CreateListFromArray(int array[], int length) {
  ListNode* head = new ListNode;
  head->mValue = array[0];
  head->mNext = nullptr;
  ListNode* endNode = head;

  for (int i = 1; i < length; i++) {
    endNode->mNext = new ListNode;
    endNode->mNext->mValue = array[i];
    endNode = endNode->mNext;
    endNode->mNext = nullptr;
  }
  return head;
}
