/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// ASKED IN MY GOOGLE PHONE SCREEN

// Somehow I managed to mess it up D:

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

class Order
{
public:
  int increasing;
  int decreasing;
};

/*

      4
      /
     5
   /  \
  3    6
 / \    \
1   11   8


       4
      /
     5  {}
   /  \
  3    6 {1,2}
 / \    \
1   11   8 {1,1}

5=> {3,3}
3=> {2,1}

*/

Order dfs(TreeNode *root, int &result)
{

  if (root = NULL)
    return {0, 0};

  if (!root->left && !root->right)
    return {1, 1};

  Order left = dfs(root->left, result);
  Order right = dfs(root->left, result);

  int increasing = 1, decreasing = 1;
  if (root->left)
  {
    if (root->val > root->left->val)
      decreasing = max(decreasing, 1 + left.decreasing);
    else if ((root->val < root->left->val))
      increasing = max(increasing, 1 + left.increasing);
  }

  if (root->right)
  {
    if (root->val > root->right->val)
      decreasing = max(decreasing, 1 + right.decreasing);
    else if ((root->val < root->right->val))
      increasing = max(increasing, 1 + right.increasing);
  }

  result = max(result, increasing + decreasing - 1);

  return {increasing, decreasing};

  /*

        5
     /     \
    3       6
 {4, 2}  {2, 6}  dec, inc

 5 > childLeft  -> increasinfg
 5 < childRight -> incrasing, decreasing

 result = increasing + decreasing + 1
 */
}

int longestIncreaingPath(TreeNode *root)
{
  int result = 0;
  dfs(root, result);
  return result;
}