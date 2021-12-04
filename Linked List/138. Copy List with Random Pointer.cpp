/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

// Doing this in O(1) is a real challenge, duplicate -> mark -> retrieve

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    Node *node = head;
    Node *preHead = new Node(-1);
    Node *newNode = preHead;
    unordered_map<Node *, int> pointerPosition;
    vector<Node *> copyPointer;
    int i;
    for (i = 0; node != NULL; i++, node = node->next)
    {
      newNode->next = new Node(node->val);
      newNode = newNode->next;
      pointerPosition[node] = i;
      copyPointer.push_back(newNode);
    }
    pointerPosition[node] = i;
    copyPointer.push_back(NULL);

    node = head, newNode = preHead->next;

    while (node != NULL)
    {
      int idx = pointerPosition[node->random];
      newNode->random = copyPointer[idx];

      node = node->next;
      newNode = newNode->next;
    }

    return preHead->next;
  }
};