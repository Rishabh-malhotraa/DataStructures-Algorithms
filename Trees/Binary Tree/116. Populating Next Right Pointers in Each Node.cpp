/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
  Node *connect(Node *root)
  {
    if (root == NULL)
      return NULL;

    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
      int len = q.size();
      for (int i = 0; i < len; i++)
      {
        Node *node = q.front();
        q.pop();

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);

        if (i == len - 1)
          node->next = NULL;
        else
        {
          node->next = q.front();
        }
      }
    }
    return root;
  }
};