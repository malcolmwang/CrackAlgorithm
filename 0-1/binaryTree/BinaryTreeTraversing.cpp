#include <deque>
#include <iostream>
#include <stack>

#include "../utils/TreeNode.h"

using namespace std;

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

void PreOrderTraversal(TreeNode* root) {
  if (root) {
    stack<TreeNode*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
      TreeNode* node = nodeStack.top();
      nodeStack.pop();

      std::cout << node->mValue << std::endl;

      if (node->mRightChild)
        nodeStack.push(node->mRightChild);
      if (node->mLeftChild)
        nodeStack.push(node->mLeftChild);
    }
  }
}

void InOrderTraversal(TreeNode* root) {
  if (!root)
    return;

  stack<TreeNode*> nodeStack;
  nodeStack.push(root);
  TreeNode* current = root->mLeftChild;

  while (current || !nodeStack.empty()) {
    while (current) {
      nodeStack.push(current);
      current = current->mLeftChild;
    }
    current = nodeStack.top();
    nodeStack.pop();
    std::cout << current->mValue << std::endl;
    current = current->mRightChild;
  }
}

void PostOrderTraversal(TreeNode* root) {
  stack<TreeNode*> nodeStack;
  TreeNode* current = root;
  TreeNode* previousNode = nullptr;

  while (current || !nodeStack.empty()) {
    while (current) {
      nodeStack.push(current);
      current = current->mLeftChild;
    }
    current = nodeStack.top();

    if (!current->mRightChild || current->mRightChild == previousNode) {
      std::cout << current->mValue << std::endl;
      previousNode = current;
      nodeStack.pop();
      current = nullptr;
    } else {
      current = current->mRightChild;
    }
  }
}

int main() {

  TreeNode node1 = {NULL, NULL, 1};
  TreeNode node2 = {NULL, NULL, 2};
  TreeNode node0 = {&node1, &node2, 100};
  TreeNode node3 = {NULL, NULL, 3};
  TreeNode root = {&node0, &node3, 250};

  //       250
  //     //   \\
  //   100     3
  // //   \\
  // 1     2
  LevelOrderTraversal(&root);
  PreOrderTraversal(&root);
  InOrderTraversal(&root);
  PostOrderTraversal(&root);

  return 0;
}
