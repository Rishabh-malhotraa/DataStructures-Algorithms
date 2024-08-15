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

private:
  map<int, vector<pair<int, int>>> nodesList;

  void inorderTraversal(TreeNode *node, int x, int y)
  {
    if (node == NULL)
      return;

    nodesList[x].push_back({y, node->val});

    inorderTraversal(node->left, x - 1, y + 1);
    inorderTraversal(node->right, x + 1, y + 1);
  }

public:
  vector<vector<int>> verticalOrder(TreeNode *root)
  {
    vector<vector<int>> result;
    inorderTraversal(root, 0, 0);

    for (auto [el, nodes] : nodesList)
    {

      sort(nodes.begin(), nodes.end(), [](pair<int, int> a, pair<int, int> b)
           { return a.first < b.first; });
      vector<int> arr;
      for (auto [_, el] : nodes)
        arr.push_back(el);
      result.push_back(arr);
    }
    return result;
  }
};