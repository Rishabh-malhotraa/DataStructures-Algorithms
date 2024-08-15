/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

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

  1
 2 3
4   5




*/

class Solution
{
private:
  string CAMERA = "CAMERA";
  string NO_CAMERA = "NO_CAMERA";
  string NOT_NEEDED = "NOT_NEEDED";

  string dfs(TreeNode *root, int &sum)
  {
    if (root == NULL)
    {
      return NOT_NEEDED;
    }

    string left = dfs(root->left, sum);
    string right = dfs(root->right, sum);

    // cout << root->val << " SUM : -- "  << sum  << "  " << left << "  " << right << endl;

    if (left == NO_CAMERA || right == NO_CAMERA)
    {
      sum++;
      return CAMERA;
    }
    else if ((left == CAMERA || right == CAMERA))
      return NOT_NEEDED;
    else
      return NO_CAMERA;
  }

public:
  int minCameraCover(TreeNode *root)
  {
    int sum = 0;
    string s = dfs(root, sum);
    return (s == NO_CAMERA) ? ++sum : sum;
  }
};