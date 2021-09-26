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
  void inorder(TreeNode *root, vector<int> &nums)
  {
    if (!root)
      return;

    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
  }

  TreeNode *buildBalencedTree(vector<int> &nums, int left, int right)
  {
    if (left > right)
      return NULL;

    int mid = unsigned(left + right) >> 1;
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = buildBalencedTree(nums, left, mid - 1);
    root->right = buildBalencedTree(nums, mid + 1, right);
    return root;
  }

  TreeNode *balanceBST(TreeNode *root)
  {
    vector<int> nums;
    inorder(root, nums);
    return buildBalencedTree(nums, 0, nums.size() - 1);
  }
};