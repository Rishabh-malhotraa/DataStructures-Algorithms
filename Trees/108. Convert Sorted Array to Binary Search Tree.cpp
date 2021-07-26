#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// merge sort way of building a balenced binary tree :DDD

class Solution
{
private:
  TreeNode *buildTree(int left, int right, vector<int> &nums)
  {
    if (left > right)
      return NULL;
    int mid = unsigned(left + right) >> 1;
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = buildTree(left, mid - 1, nums);
    root->right = buildTree(mid + 1, right, nums);
    return root;
  }

public:
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    return buildTree(0, nums.size() - 1, nums);
  }
};