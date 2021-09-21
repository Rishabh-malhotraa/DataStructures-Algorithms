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
  void dfs(TreeNode *root, int maxValue, int &result)
  {
    if (root == NULL)
      return;

    maxValue = max(maxValue, root->val);
    if (maxValue == root->val)
      result++;

    dfs(root->left, maxValue, result);
    dfs(root->right, maxValue, result);
  }

  int goodNodes(TreeNode *root)
  {
    int result = 0;
    dfs(root, root->val, result);
    return result;
  }
};

// SOLUTION 2 : w/o passing result again and again

class Solution
{
public:
  int dfs(TreeNode *root, int maxValue)
  {
    int result = 0;
    if (root == NULL)
      return 0;

    maxValue = max(maxValue, root->val);
    if (maxValue == root->val)
      result++;

    result += dfs(root->left, maxValue);
    result += dfs(root->right, maxValue);

    return result;
  }

  int goodNodes(TreeNode *root)
  {
    return dfs(root, root->val);
  }
};