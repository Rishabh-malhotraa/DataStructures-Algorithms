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

// BACKTRACKING QUESTION ^.^ | UGLY SOLUTION BUT WHAT CAN YOU DO

class Solution
{
public:
  vector<string> result;

public:
  void dfs(TreeNode *root, string path)
  {
    if (!root)
      return;

    if (root->left == NULL && root->right == NULL)
      result.push_back(path + to_string(root->val));
    else
    {
      dfs(root->left, path + to_string(root->val) + "->");
      dfs(root->right, path + to_string(root->val) + "->");
    }
  }

  vector<string> binaryTreePaths(TreeNode *root)
  {
    dfs(root, "");
    return result;
  }
};