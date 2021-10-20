/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int cost;
  vector<Node *> children;
  Node *parent;
};

int getCheapestCost(Node *rootNode)
{
  priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;

  pq.push({0, rootNode});

  while (!pq.empty())
  {
    auto [cost, node] = pq.top();
    pq.pop();

    if (node->children.size() == 0)
      return cost;

    for (Node *neighbour : node->children)
    {
      pq.push({cost + neighbour->cost, neighbour});
    }
  }
  return -1;
}

int main()
{
  return 0;
}