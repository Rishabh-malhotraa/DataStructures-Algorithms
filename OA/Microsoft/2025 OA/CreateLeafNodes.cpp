/*


The problem focuses on a data structure called a binary tree.

A node of a binary tree has an ID (an integer value) and pointers to two other nodes, called the left subtree and the right subtree. If the left subtree or right subtree does not exist, its corresponding pointer value is

nullptr

For example, the figure below shows a binary tree consisting of six nodes. Here, node 3 does not have a right subtree, and nodes 4, 5, and 9 are leaves—they do not have any subtrees.

Assume that the following declarations are given:

struct tree {
    int x;
    tree* l;
    tree* r;
}

Attribute x holds the node's ID, whereas attributes l and r hold the left and right subtree, respectively.

Your task is to expand the tree by replacing every leaf with a new node whose subtrees are both leaves. The IDs of each new node and its two leaves should correspond to the ID of the leaf they replaced. Here is

the expanded tree from the previous example:







 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverseToLeafNode(TreeNode* node) {
  if (node == NULL)
    return;

  // leaf node
  if (node->left == NULL && node->right == NULL) {
    node->left = new TreeNode(node->val, NULL, NULL);
    node->right = new TreeNode(node->val, NULL, NULL);
  }
  else {
    traverseToLeafNode(node->left);
    traverseToLeafNode(node->right);
  }
}

TreeNode* solution(TreeNode* T) {
  // Implement your solution here
  traverseToLeafNode(T);
  return T;
}
