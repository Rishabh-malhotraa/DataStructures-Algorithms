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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  void dfs(TreeNode *root, int x, int y, map<int, multiset<pair<int, int>>> &cols)
  {
    if (root == NULL)
      return;

    cols[x].insert(make_pair(y, root->val));

    dfs(root->left, x - 1, y + 1, cols);
    dfs(root->right, x + 1, y + 1, cols);
  }

  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    map<int, multiset<pair<int, int>>> cols; // <x,  [y, value] >
    dfs(root, 0, 0, cols);

    vector<vector<int>> result;

    for (auto &[x, col] : cols)
    {
      vector<int> nodeArr;
      for (auto &[y, nodeVal] : col)
        nodeArr.push_back(nodeVal);
      result.push_back(nodeArr);
    }
    return result;
  }
};

// VARIATION 2 IF VALUE OF SAME THEN LEFT TO RIGHT SHOULD BE GIVEN PRECEDENCE

class Solution
{
private:
  map<int, map<int, vector<int>>> cols;

  void dfs(TreeNode *root, int x, int y)
  {
    if (root == NULL)
      return;

    cols[x][y].push_back(root->val);

    dfs(root->left, x - 1, y + 1);
    dfs(root->right, x + 1, y + 1);
  }

public:
  vector<vector<int>> verticalOrder(TreeNode *root)
  {
    vector<vector<int>> result;
    dfs(root, 0, 0);

    for (auto &[x, col] : cols)
    {
      vector<int> nodeArr;
      for (auto &[y, nodeVals] : col)
        for (int nodeVal : nodeVals)
          nodeArr.push_back(nodeVal);

      result.push_back(nodeArr);
    }
    return result;
  }
};
