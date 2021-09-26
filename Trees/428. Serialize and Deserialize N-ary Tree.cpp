/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  vector<Node *> children;

  Node() {}
  Node(int _val) : val(_val) {}
  Node(int _val, vector<Node *> _children) : val(_val), children(_children) {}
};

class Codec
{
private:
  char delimeter = ' ';

public:
  // Encodes a tree to a single string.
  string serialize(Node *root)
  {
    if (root == NULL)
      return string(1, delimeter);

    string stream = to_string(root->val) + delimeter + to_string(root->children.size()) + delimeter;

    for (Node *children : root->children)
      stream += serialize(children);

    return stream;
  }

  Node *buildTree(stringstream &ss)
  {
    Node *root;
    int value, child_size;
    if (ss >> value >> child_size)
    {
      root = new Node(value);
      for (int i = 0; i < child_size; i++)
        root->children.push_back(buildTree(ss));
    }
    return root;
  }

  Node *deserialize(string data)
  {
    stringstream ss(data);
    return buildTree(ss);
  }
};
