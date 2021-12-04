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
      1
  2      5
3   4      6
*/

class Solution
{
private:
  pair<TreeNode *, TreeNode *> dfs(TreeNode *node)
  {
    if (node->left == NULL && node->right == NULL)
      return {node, node};

    auto &[leftStart, leftEnd] = dfs(node->left);

    auto &[rightStart, rightEnd] = dfs(node->right);

    node->right = leftStart;
    leftEnd->right = rightStart;

    return {node, rightEnd};
    // return ;
  }

public:
  void flatten(TreeNode *root)
  {
    dfs(root);
    return;
  }
};