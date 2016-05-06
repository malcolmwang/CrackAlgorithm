#include <vector>

struct TreeNode {
  TreeNode* mLeftChild;
  TreeNode* mRightChild;
  int mValue;

  TreeNode(int value) {
    mLeftChild = nullptr;
    mRightChild = nullptr;
    mValue = value;
  }

  TreeNode() {
    mLeftChild = nullptr;
    mRightChild = nullptr;
  }
};

TreeNode* CreateBinaryTreeFromArray(int arr[], int length) {
  TreeNode* root = nullptr;
  TreeNode* curNode = nullptr;

  int i = 0;
  root = new TreeNode(arr[0]);
  std::vector<TreeNode*> nodeVector;
  nodeVector.push_back(root);

  while (!nodeVector.empty()) {
    curNode = nodeVector.front();
    nodeVector.erase(nodeVector.begin());

    if (2 * i + 1 >= length) break;
    curNode->mLeftChild = new TreeNode(arr[2 * i + 1]);
    nodeVector.push_back(curNode->mLeftChild);

    if (2 * 1 + 2 >= length) break;
    curNode->mRightChild = new TreeNode(arr[2 * i + 2]);
    nodeVector.push_back(curNode->mRightChild);

    i++;
  }
  return root;
}
