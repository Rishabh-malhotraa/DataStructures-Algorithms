/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Keep Removing leaves until you have just one or two node left
 * That would be youe nodes with minimum height (middle nodes)
 * This questions is similar to finidng the middle nodes
 * But unlike in linked list (or skewd tree) there could be branching
 * So we remove all the nodes from the edges!!!
*/

class Solution
{
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
  {
    if (n == 1)
      return {0};

    vector<list<int>> adj(n);
    vector<int> outdegree(n, 0);
    vector<int> result;
    queue<int> leaves;

    for (vector<int> &edge : edges)
    {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
      outdegree[v]++;
      outdegree[u]++;
    }

    for (int i = 0; i < n; i++)
    {
      if (outdegree[i] == 1)
      {
        leaves.push(i);
        outdegree[i]--;
      }
    }
    while (leaves.empty() == false)
    {
      int n = leaves.size();
      result.clear(); // level order!!!

      for (int i = 0; i < n; i++)
      {
        int curr = leaves.front();
        result.push_back(curr);
        leaves.pop();
        for (int neighbour : adj[curr])
        {
          outdegree[neighbour]--;
          if (outdegree[neighbour] == 1)
            leaves.push(neighbour);
        }
      }
    }
    return result;
  }
};
