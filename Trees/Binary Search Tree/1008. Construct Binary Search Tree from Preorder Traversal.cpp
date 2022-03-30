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

8 5 1 7 10 12

    8
   /
  5
 /
1

*/

class Solution
{
private:
  int getPivot(int l, int r, vector<int> &nums, int value)
  {
    while (l <= r)
    {
      int mid = unsigned(l + r) / 2;
      if (nums[mid] < value)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return l;
  }

  TreeNode *buildTree(int idx, int n, vector<int> &nums)
  {
    if (idx > n)
      return NULL;

    int value = nums[idx++];
    int pivot = getPivot(idx, n, nums, value);

    TreeNode *root = new TreeNode(value);
    root->left = buildTree(idx, pivot - 1, nums);
    root->right = buildTree(pivot, n, nums);

    return root;
  }

public:
  TreeNode *bstFromPreorder(vector<int> &preorder)
  {
    if (preorder.size() == 0)
      return NULL;

    return buildTree(0, preorder.size() - 1, preorder);
  }
};