//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
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
  vector<vector<int>> result;
  void dfs(TreeNode *root, int sum, int target, vector<int> path)
  {
    if (root == NULL)
      return;

    if (root->left == NULL && root->right == NULL)
    {
      if (sum + root->val == target)
      {
        path.push_back(root->val);
        result.push_back(path);
        path.pop_back();
      }
      return;
    }

    path.push_back(root->val);
    dfs(root->left, sum + root->val, target, path);
    dfs(root->right, sum + root->val, target, path);
    path.pop_back();
  }

public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum)
  {
    dfs(root, 0, targetSum, {});
    return result;
  }
};