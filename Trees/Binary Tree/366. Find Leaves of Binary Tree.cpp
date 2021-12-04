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
  unordered_map<int, vector<int>> heights;

  int dfs(TreeNode *root)
  {
    if (root == NULL)
      return -1;

    int lh = dfs(root->left);
    int rh = dfs(root->right);

    int height = max(lh, rh) + 1;

    heights[height].push_back(root->val);
    return height;
  }

public:
  vector<vector<int>> findLeaves(TreeNode *root)
  {
    if (root == NULL)
      return {};

    dfs(root);
    int n = heights.size();
    vector<vector<int>> leaves(n, vector<int>{});
    for (auto [height, leaves_] : heights)
      leaves[height] = leaves_;
    return leaves;
  }
};