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
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution
{
public:
  Node *lowestCommonAncestor(Node *p, Node *q)
  {
    Node *p1 = p, *p2 = q;

    while (p1 != p2)
    {
      p1 = p1->parent ? p1->parent : q;
      p2 = p2->parent ? p2->parent : p;
    }
    return p1;
  }
};

class Solution
{
public:
  Node *lowestCommonAncestor(Node *p, Node *q)
  {
    unordered_set<Node *> cache;
    Node *p1 = p, *p2 = q;

    for (; p1 != NULL; p1 = p1->parent)
      cache.insert(p1);

    for (; p2 != NULL; p2 = p2->parent)
      if (cache.find(p2) != cache.end())
        return p2;

    return NULL;
  }
};
