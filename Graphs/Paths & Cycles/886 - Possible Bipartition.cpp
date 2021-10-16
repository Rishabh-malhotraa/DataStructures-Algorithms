#include <bits/stdc++.h>
using namespace std;

// DFS Method of coloring the graph

class Solution
{
private:
  enum States
  {
    WHITE,
    GREY,
    BLACK
  };

  bool dfs(vector<list<int>> &graph, vector<int> &state, int node, int color)
  {
    if (state[node] != WHITE)
      return color == state[node];

    state[node] = color;
    int nextColor = (color == BLACK) ? GREY : BLACK;
    for (int neighbour : graph[node])
    {
      bool result = dfs(graph, state, neighbour, nextColor);
      if (result == false)
        return false;
    }
    return true;
  }

public:
  bool possibleBipartition(int n, vector<vector<int>> &dislikes)
  {
    vector<int> state(n + 1, WHITE);
    vector<list<int>> graph(n + 1);
    bool result = true;
    for (vector<int> &edges : dislikes)
    {
      graph[edges[0]].push_back(edges[1]);
      graph[edges[1]].push_back(edges[0]);
    }

    for (int i = 1; i < n + 1; i++)
    {
      if (state[i] == WHITE)
      {
        result = dfs(graph, state, i, BLACK);
        if (result == false)
          return result;
      }
    }
    return result;
  }
};
