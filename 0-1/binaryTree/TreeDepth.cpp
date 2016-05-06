#include <iostream>

#include "../utils/TreeNode.h"

using namespace std;

int TreeDepth(TreeNode* root) {
  if (root == nullptr)
    return 0;

  int left = TreeDepth(root->mLeftChild);
  int right = TreeDepth(root->mRightChild);

  return (left > right) ? (left + 1) : (right + 1);
}

int main() {
  //        2
  //     //   \\
  //   6       7
  // //   \\
  // 0     9
  int a[] = {2, 6, 7, 0, 9, 3};
  TreeNode* root = CreateBinaryTreeFromArray(a, 6);
  std::cout << TreeDepth(root) << std::endl;

  return 0;
}
