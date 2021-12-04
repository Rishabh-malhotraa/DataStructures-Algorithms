/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

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

class Order
{
public:
  int decreasing;
  int increasing;
};

class Solution
{
private:
  Order dfs(TreeNode *root, int &result)
  {
    if (root == NULL)
      return {0, 0};

    Order leftSequence = dfs(root->left, result);
    Order rightSequence = dfs(root->right, result);
    Order sequence = {1, 1};
    if (root->left)
    {
      int leftVal = root->left->val;
      if (root->val - leftVal == 1)
        sequence.decreasing = max(sequence.decreasing, leftSequence.decreasing + 1);
      else if (root->val - leftVal == -1)
        sequence.increasing = max(sequence.increasing, leftSequence.increasing + 1);
    }
    if (root->right)
    {
      int rightVal = root->right->val;
      if (root->val - rightVal == 1)
        sequence.decreasing = max(sequence.decreasing, rightSequence.decreasing + 1);
      else if (root->val - rightVal == -1)
        sequence.increasing = max(sequence.increasing, rightSequence.increasing + 1);
    }
    result = max(result, sequence.increasing);
    // cout << root->val << " " << sequence.decreasing << " " << sequence.increasing << " " << result << endl;
    return sequence;
  }

public:
  int longestConsecutive(TreeNode *root)
  {
    int result = 0;
    dfs(root, result);
    return result;
  }
};