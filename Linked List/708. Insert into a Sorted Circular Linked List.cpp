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
  Node *next;

  Node() {}

  Node(int _val)
  {
    val = _val;
    next = NULL;
  }

  Node(int _val, Node *_next)
  {
    val = _val;
    next = _next;
  }
};

/*

                insert 7
                |
     4  5  6   11   13  1
                     |

  insert 2 at 3 3 3

*/

class Solution
{
public:
  Node *addNode(Node *node, int key)
  {
    Node *preHead = node;

    Node *temp = node->next;
    Node *newNode = new Node(key);
    node->next = newNode;
    newNode->next = temp;

    return preHead;
  }

  Node *insert(Node *head, int target)
  {
    Node *node = head;

    if (head == NULL)
    {
      Node *node = new Node(target);
      node->next = node;
      return node;
    }
    node = node->next;
    while (node != head)
    {
      if (node->next->val > target && !(node->val > target))
      {
        addNode(node, target);
        return head;
      }

      if (node->val > node->next->val)
      {
        if (target >= node->val || target <= node->next->val)
        {
          addNode(node, target);
          return head;
        }
      }

      node = node->next;
    }

    addNode(node, target);
    return head;
  }
};