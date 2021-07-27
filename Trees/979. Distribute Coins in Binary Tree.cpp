#include <bits/stdc++.h>
using namespace std;

// Very good Questtions on Binary Tree with very elegant solution!

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
public:
  int dfs(TreeNode *root, int &result)
  {
    if (root == NULL)
      return 0;

    int left = dfs(root->left, result);
    int right = dfs(root->right, result);
    result += abs(left) + abs(right);

    return root->val + left + right - 1;
  }

  int distributeCoins(TreeNode *root)
  {
    int result = 0;
    dfs(root, result);
    return result;
  }
};
