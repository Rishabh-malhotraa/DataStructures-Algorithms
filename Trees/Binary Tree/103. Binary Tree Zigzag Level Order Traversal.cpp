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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {

    if (!root)
      return {};

    queue<TreeNode *> q({root});
    vector<vector<int>> result;
    bool shouldReverse = false;
    while (q.empty() == false)
    {
      int n = q.size();
      vector<int> level;
      for (int i = 0; i < n; i++)
      {
        TreeNode *curr = q.front();
        q.pop();
        level.push_back(curr->val);

        if (curr->left)
          q.push(curr->left);
        if (curr->right)
          q.push(curr->right);
      }

      if (shouldReverse == true)
        reverse(level.begin(), level.end());

      shouldReverse = !shouldReverse;
      result.push_back(level);
    }
    return result;
  }
};
