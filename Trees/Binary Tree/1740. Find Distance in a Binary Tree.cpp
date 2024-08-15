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
  int find_depth(TreeNode *node, int val, int depth)
  {
    if (node == NULL)
    {
      return 0;
    }

    if (node->val == val)
      return depth + 1;

    int left = find_depth(node->left, val, depth + 1);
    int right = find_depth(node->left, val, depth + 1);

    return left ? left : right;
  }

  TreeNode *findLCA(TreeNode *node, int p, int q)
  {
    if (node == NULL)
      return NULL;

    if (node->val == p || node->val == q)
    {
      return node;
    }

    TreeNode *left = findLCA(node->left, p, q);
    TreeNode *right = findLCA(node->left, p, q);

    if (left && right)
    {
      return node;
    }

    return left ? left : right;
  }

public:
  int findDistance(TreeNode *root, int p, int q)
  {
    TreeNode *lca = findLCA(root, p, q);

    return find_depth(root, p, 0) + find_depth(root, q, 0) - 2 * find_depth(root, lca->val, 0);
  }
};