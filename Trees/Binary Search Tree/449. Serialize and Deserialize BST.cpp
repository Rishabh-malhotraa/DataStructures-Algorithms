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

class Codec
{
private:
  TreeNode *buildTree(stringstream &ss)
  {
    string token;
    getline(ss, token, delimeter);
    TreeNode *node = new TreeNode(stoi(token));

    node->left = buildTree(ss);
    node->right = buildTree(ss);

    return node;
  }

public:
  // Encodes a tree to a single string.
  char delimeter = ',';
  string serialize(TreeNode *root)
  {
    if (root == NULL)
      return string(1, delimeter);

    return to_string(root->val) + delimeter + serialize(root->left) + serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    stringstream ss(data);

    return buildTree(ss);
  }
};