/*
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

class Solution
{
public:
  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (root == NULL)
      return NULL;

    if (root->val > key)
      root->left = deleteNode(root->left, key);
    else if (root->val < key)
      root->right = deleteNode(root->right, key);
    else
    {
      TreeNode *leftChild = root->left;
      TreeNode *rightChild = root->right;
      if (leftChild && rightChild)
      {

        while (leftChild->right)
          leftChild = leftChild->right;

        leftChild->right = rightChild;
        return root->left;
      }
      else
        return leftChild ? leftChild : rightChild;
    }
    return root;
  }
};