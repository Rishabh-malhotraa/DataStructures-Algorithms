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
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
  {
    if (root1 == NULL)
      return root2;
    if (root2 == NULL)
      return root1;

    TreeNode *root = new TreeNode(root1->val + root2->val);

    root->left = mergeTrees(root1->left, root2->left);
    root->right = mergeTrees(root1->right, root2->right);

    return root;
  }
};

// UGLY Solution

class Solution
{
public:
  TreeNode *mergeTrees(TreeNode *n1, TreeNode *n2)
  {
    if (!n1 && !n2)
      return NULL;

    TreeNode *l1, *l2, *r1, *r2;
    int v1 = 0, v2 = 0;
    if (n1)
    {
      l1 = n1->left, r1 = n1->right;
      v1 = n1->val;
    }
    if (n2)
    {
      l2 = n2->left, r2 = n2->right;
      v2 = n2->val;
    }

    TreeNode *node = new TreeNode(v1 + v2);

    node->left = mergeTrees(l1, l2);
    node->right = mergeTrees(r1, r2);

    return node;
  }
};