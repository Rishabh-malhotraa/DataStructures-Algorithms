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

// if you are uncomfortable in talking through stringstream
// you can use queue data strucuture after you push all the , seperated values
// in the queue and start popping the top element!

/*
Serialization is the process of converting a data structure or object into a sequence
of bits so that it can be stored in a file or memory buffer, or transmitted across a
network connection link to be reconstructed later in the same or another computer environment.
*/
class Codec
{
public:
  char delimeter = '|';
  char nullDelimeter = 'X';
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    if (root == NULL)
      return string(1, nullDelimeter);

    string hashString = to_string(root->val) + string(1, delimeter) + serialize(root->left) + string(1, delimeter) + serialize(root->right);

    return hashString;
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

    if (token == "X")
      return NULL;

    TreeNode *node = new TreeNode(stoi(token));

    node->left = buildTree(ss);
    node->right = buildTree(ss);

    return node;
  }
};