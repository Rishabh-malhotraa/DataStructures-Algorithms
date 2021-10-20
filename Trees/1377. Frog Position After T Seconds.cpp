/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  vector<list<int>> buildGraph(vector<vector<int>> edgeList, int n)
  {
    vector<list<int>> adjList(n + 1);
    for (vector<int> edges : edgeList)
    {
      int u = edges[0];
      int v = edges[1];
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
    return adjList;
  }
  int target, t;
  double probability = 0.0;
  void dfs(vector<list<int>> &graph, int node, int parent, double probability, int time)
  {
    int n = (parent == -1) ? graph[node].size() : graph[node].size() - 1;
    if (node == target && (time == t || n == 0))
      this->probability = probability;
    else
    {
      for (int &neighbours : graph[node])
        if (time < t && neighbours != parent)
          dfs(graph, neighbours, node, (probability / n), time + 1);
    }
  }

public:
  double frogPosition(int n, vector<vector<int>> &edges, int _t, int _target)
  {
    target = _target, t = _t;
    auto graph = buildGraph(edges, n);
    dfs(graph, 1, -1, 1.0, 0);
    return this->probability;
  }
};
