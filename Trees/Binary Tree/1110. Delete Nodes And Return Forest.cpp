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
public:
  set<int> s;
  TreeNode *postOrder(TreeNode *root, vector<TreeNode *> &nodes)
  {
    if (root == NULL)
      return NULL;

    root->left = postOrder(root->left, nodes);
    root->right = postOrder(root->right, nodes);

    if (s.find(root->val) != s.end())
    {
      if (root->left)
        nodes.push_back(root->left);
      if (root->right)
        nodes.push_back(root->right);

      return NULL;
    }

    return root;
  }

  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
  {
    vector<TreeNode *> nodes;
    s = set<int>(to_delete.begin(), to_delete.end());

    postOrder(root, nodes);
    if (s.count(root->val) == 0)
      nodes.push_back(root);

    return nodes;
  }
};