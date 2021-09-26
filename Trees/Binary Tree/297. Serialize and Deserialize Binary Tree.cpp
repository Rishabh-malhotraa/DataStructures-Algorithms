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

// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

class Codec
{
public:
  char delimeter = ',';
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    if (root == NULL)
      return string(1, delimeter);

    string leftSubtree = serialize(root->left);
    string rightSubtree = serialize(root->right);

    return to_string(root->val) + delimeter + leftSubtree + rightSubtree;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    stringstream ss(data);
    TreeNode *root = buildTree(ss);
    return root;
  }

  TreeNode *buildTree(stringstream &ss)
  {
    string token;
    getline(ss, token, delimeter);
    if (token == "")
      return NULL;

    TreeNode *node = new TreeNode(stoi(token));
    node->left = buildTree(ss);
    node->right = buildTree(ss);

    return node;
  }
};
