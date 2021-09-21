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
  TreeNode *xParent = NULL, *yParent = NULL;
  int xDepth = 0, yDepth = 0;

public:
  void dfs(TreeNode *root, int x, int y, int depth, TreeNode *parent)
  {
    if (root == NULL)
      return;

    if (root->val == x)
    {
      xParent = parent;
      xDepth = depth;
    }
    else if (root->val == y)
    {
      yParent = parent;
      yDepth = depth;
    }
    else
    {
      dfs(root->left, x, y, depth + 1, root);
      dfs(root->right, x, y, depth + 1, root);
    }
  }

  bool isCousins(TreeNode *root, int x, int y)
  {
    dfs(root, x, y, 0, NULL);

    if (xParent != yParent && xDepth == yDepth)
      return true;
    return false;
  }
};