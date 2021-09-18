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
private:
  TreeNode *buildTree(vector<int> &nums, int left, int right)
  {
    if (left > right)
      return NULL;

    int mid = unsigned(left + right) >> 1;

    TreeNode *node = new TreeNode(nums[mid]);

    node->left = buildTree(nums, left, mid - 1);
    node->right = buildTree(nums, mid + 1, right);

    return node;
  }

public:
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    TreeNode *root = buildTree(nums, 0, nums.size() - 1);
    return root;
  }
};