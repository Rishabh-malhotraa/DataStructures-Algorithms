#include <bits/stdc++.h>
using namespace std;

// BFS method of finding bipartite but coloring leads to a better looking code
// WHAT BRUH?? this is way worse than dfs lol EDIT: 15-10-21

class Solution
{
public:
  bool isBipartiteUtil(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &color, int root)
  {
    bool result = true;
    queue<int> q;
    q.push(root);
    visited[root] = true;
    int offset = 0;
    while (!q.empty())
    {
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
        int curr = q.front();

        visited[curr] = true;

        if (color[curr] == (offset + 1) % 2)
          return false;
        else
          color[curr] = offset % 2;

        for (int neighbour : graph[curr])
        {
          if (visited[neighbour] == false)
            q.push(neighbour);
        }
        q.pop();
      }
      offset++;
    }

    return result;
  }

  bool isBipartite(vector<vector<int>> &graph)
  {
    int n = graph.size(), m = graph[0].size();
    bool result = false;
    vector<bool> visited(n, false);
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
      if (visited[i] == false)
        result = isBipartiteUtil(graph, visited, color, i);

      if (result == false)
        break;
    }
    return result;
  }
};