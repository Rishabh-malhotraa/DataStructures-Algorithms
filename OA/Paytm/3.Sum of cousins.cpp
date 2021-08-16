//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Level Order Traveral
class Node
{
public:
  int data;
  struct Node *left, *right;
};

int findCousinSum(Node *root, int key)
{
  if (root == NULL)
    return -1;

  if (root->data == key)
  {
    return -1;
  }

  int currSum = 0;

  int size;

  queue<Node *> q;
  q.push(root);

  bool found = false;

  while (!q.empty())
  {
    if (found == true)
    {
      return currSum;
    }

    size = q.size();
    currSum = 0;

    while (size)
    {
      root = q.front();
      q.pop();

      if ((root->left && root->left->data == key) || (root->right && root->right->data == key))
      {
        found = true;
      }

      else
      {
        if (root->left)
        {
          currSum += root->left->data;
          q.push(root->left);
        }

        if (root->right)
        {
          currSum += root->right->data;
          q.push(root->right);
        }
      }

      size--;
    }
  }

  return -1;
}