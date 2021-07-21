#include <bits/stdc++.h>
using namespace std;

enum State
{
  UNVISITED,
  PROCESSING,
  VISITED
};

class Solution
{
private:
  bool hasCycle(vector<vector<int>> &graph, vector<int> &state, int node)
  {
    if (state[node] == VISITED)
      return false;

    state[node] = PROCESSING;

    for (int &neighbour : graph[node])
    {
      if (state[neighbour] == PROCESSING)
        return true;
      if (state[neighbour] == UNVISITED && hasCycle(graph, state, neighbour))
        return true;
    }
    state[node] = VISITED;
    return false;
  }

public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph)
  {
    int n = graph.size();
    vector<int> state(n, UNVISITED);
    vector<int> result;

    for (int i = 0; i < n; i++)
      if (hasCycle(graph, state, i) == false)
        result.push_back(i);

    return result;
  }
};