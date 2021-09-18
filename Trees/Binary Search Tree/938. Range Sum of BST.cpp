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
 * You can do a dfs on the entire tree and add those nodes to the result which follow the condition
 * but since you have a BST you can truncate your search  
*/
class Solution
{
private:
  int result = 0;

public:
  int rangeSumBST(TreeNode *root, int low, int high)
  {
    if (root != NULL)
    {
      if (root->val >= low && root->val <= high)
        result += root->val;
      if (root->val >= low)
        dfs(root->left, low, high);
      if (root->val <= R)
        dfs(root->right, low, high)
    }
    return result;
  }
};