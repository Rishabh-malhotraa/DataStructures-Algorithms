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
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void dfs(TreeNode *node, int target, unordered_set<int> &cache, int &result)
{
  if (node == NULL || result == 1)
    return;

  int value = node->val;
  int key = target - value;
  // a + b = target
  // b = target - a;

  if (cache.find(key) != cache.end())
  {
    result = 1;
    return;
  }
  cache.insert(value);
  dfs(node->left, target, cache, result);
  dfs(node->right, target, cache, result);
  return;
}

int Solution::t2Sum(TreeNode *root, int B)
{
  if (root == NULL)
    return 0;
  unordered_set<int> cache; // this will help us retrieve number in O(1)
  int result = 0;
  dfs(root, B, cache, result);
  return result;
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// you need to tell if there exist n1->value + n2->value = B
/*



         10  ----
        / \
       9   20
      / \  / \
     5       45    --- 50

 Method 1 : Brute Force -- DFS

 10 ->  Root -> Left -> Right

cache -> 10 ,

 n1 + n2 = b
lets say b = 20
n1 = 9  --> n2 = 11
n2 = b - n1


TC: O(N)
SC: O(N) -- use a cache to lookup elements in O(1) time


         12  ----     50     target = 10
        / \
       9   13
      / \  / \
    1         45



12 --> 50

suppose we take 10  target value b: 5



root -> left -> right

         12
        / \
       9   13
      / \  / \
     1       45



rec(12)
    rec 9                         rec(13)
      rec(1) rec(NULL)              rec(NULL)  rec(45)
     NULL  NULL                                /   \
cache = 12 9 1 13


key = target - value
target = 46
result = 1
*/
