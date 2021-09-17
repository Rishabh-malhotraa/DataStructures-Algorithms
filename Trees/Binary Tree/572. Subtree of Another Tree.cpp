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
  bool isSameTree(TreeNode *t1, TreeNode *t2)
  {
    if (t1 == NULL || t2 == NULL)
      return (t1 == NULL && t2 == NULL);
    else if (t1->val == t2->val)
      return (isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right));
    else
      return false;
  }

  bool isSubtree(TreeNode *root, TreeNode *subRoot)
  {
    if (root == NULL)
      return false;
    if (isSameTree(root, subRoot))
      return true;
    return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
  }
};