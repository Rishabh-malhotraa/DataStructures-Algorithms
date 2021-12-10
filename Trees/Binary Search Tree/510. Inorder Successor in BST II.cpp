// Definition for a Node.
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
  Node *left;
  Node *right;
  Node *parent;
};

class Solution
{
public:
  Node *inorderSuccessor(Node *node)
  {
    if (!node->right)
    {
      while (node->parent != NULL && node->parent->val < node->val)
        node = node->parent;
      return node->parent;
    }
    node = node->right;

    while (node->left)
      node = node->left;

    return node;
  }
};