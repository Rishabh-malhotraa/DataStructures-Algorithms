#include <bits/stdc++.h>
using namespace std;

// Graph | Trees | BFS Level Order | Outdegrees

// https://assets.leetcode.com/static_assets/discuss/uploads/files/1469152741497-1463645059503_1214297289.jpg
// For Visial Explanation

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
