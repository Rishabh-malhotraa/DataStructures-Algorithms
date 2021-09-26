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
private:
  vector<TreeNode *> result;

public:
  vector<TreeNode *> splitBST(TreeNode *root, int target)
  {
    TreeNode *parent = new TreeNode();
    parent->left = root;
    parent->right = root;
  }
  TreeNode *deleteNode(TreeNode *root, int target)
  {
    if (root == NULL)
      return NULL;

    if (root->val > target)
      root->left = deleteNode(root->left, target);
    else if (root->val <= target)
    {
      TreeNode *greaterValues = root->right;
      root->right = NULL;
      result.push_back(root);
      return root->right;
    }
  }
};