//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

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
  TreeNode *helper(vector<int> preorder, int rootIdx, int left, int right, unordered_map<int, int> cache)
  {
    if (rootIdx > preorder.size() || left > right)
      return NULL;
    else
    {
      int value = preorder[rootIdx];
      TreeNode *root = new TreeNode(value);
      int pivot = cache[value];

      root->left = helper(preorder, rootIdx + 1, left, pivot - 1, cache);
      root->right = helper(preorder, rootIdx + (pivot - left + 1), pivot + 1, right, cache);
      return root;
    }
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    unordered_map<int, int> cache;
    int idx = 0;
    for (int &el : inorder)
      cache[el] = idx++;
    return helper(preorder, 0, 0, idx - 1, cache);
  }
};