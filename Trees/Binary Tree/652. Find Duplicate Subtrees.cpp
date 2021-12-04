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
private:
  unordered_map<string, int> cache;
  vector<TreeNode *> duplicateSubtrees;
  string delimeter = ".";
  string nullDelimeter = "|";

  string dfs(TreeNode *root)
  {
    if (root == NULL)
      return nullDelimeter;

    string left = dfs(root->left);
    string right = dfs(root->right);

    string value = to_string(root->val);

    string serializeString = value + delimeter + left + delimeter + right;

    // cout << serializeString << setw(50) << root->val << " " << endl;

    if (cache.find(serializeString) != cache.end() && cache[serializeString] == 1)
      duplicateSubtrees.push_back(root);

    cache[serializeString]++;
    return serializeString;
  }

public:
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
  {
    // serialize the tree in postorder fashion
    dfs(root);

    return duplicateSubtrees;
  }
};