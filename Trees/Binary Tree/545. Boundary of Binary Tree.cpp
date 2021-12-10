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

/*
Observations

Preorder Traversal

-> left child of root is always lb
-> right child of root is always rb

-> left child of lb => lb
    -> right of lb => lb only is lb->left == NULL
-> right child of rb => rb
    -> left of rb => rb only is rb->right == NULL

*/

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
  bool isLeaf(TreeNode *node)
  {
    return node && node->left == NULL && node->right == NULL;
  }

  void dfs(TreeNode *root, vector<int> &boundry, bool lb, bool rb)
  {
    bool added = false;
    if (root == NULL)
      return;

    if (lb || isLeaf(root))
    {
      added = true;
      boundry.push_back(root->val);
    }

    dfs(root->left, boundry, lb, rb && root->right == NULL);
    dfs(root->right, boundry, lb && root->left == NULL, rb);

    if (rb && !added)
      boundry.push_back(root->val);
  }

public:
  vector<int> boundaryOfBinaryTree(TreeNode *root)
  {
    vector<int> boundry;
    if (root == NULL)
      return boundry;

    boundry.push_back(root->val);

    dfs(root->left, boundry, true, false);
    dfs(root->right, boundry, false, true);

    return boundry;
  }
};