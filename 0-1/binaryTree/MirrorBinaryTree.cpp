#include <deque>
#include <iostream>

#include "../utils/TreeNode.h"

using namespace std;

void MirrorRecursively(TreeNode* root) {
  if (!root)
    return;

  if (!root->mLeftChild && !root->mRightChild)
    return;

  swap(root->mLeftChild, root->mRightChild);

  if (root->mLeftChild)
    MirrorRecursively(root->mLeftChild);
  if (root->mRightChild)
    MirrorRecursively(root->mRightChild);
}

void LevelOrderTraversal(TreeNode* root) {
  if (!root)
    return;

  std::deque<TreeNode*> dequeTreeNode;
  dequeTreeNode.push_back(root);

  while (dequeTreeNode.size()) {
    TreeNode* node = dequeTreeNode.front();
    dequeTreeNode.pop_front();

    std::cout << node->mValue << std::endl;

    if (node->mLeftChild)
      dequeTreeNode.push_back(node->mLeftChild);
    if (node->mRightChild)
      dequeTreeNode.push_back(node->mRightChild);
  }
}

int main() {
  TreeNode node1(1);
  TreeNode node2(2);
  TreeNode node0(100);
  TreeNode node3(3);
  TreeNode root(250);

  root.mLeftChild = &node0;
  root.mRightChild = &node3;
  node0.mLeftChild = &node1;
  node0.mRightChild = &node2;
  //       250
  //     //   \\
  //   100     3
  // //   \\
  // 1     2
  MirrorRecursively(&root);
  LevelOrderTraversal(&root);
  return 0;
}
