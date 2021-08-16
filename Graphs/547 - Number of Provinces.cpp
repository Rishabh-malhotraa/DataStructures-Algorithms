#include <bits/stdc++.h>
using namespace std;

// Disjoint Sets find number of connected comppnents

class DisjointSet
{
private:
  vector<int> parent;
  vector<int> rank;

public:
  DisjointSet(int N)
  {
    parent.resize(N, -1);
    rank.resize(N, 1);
  }
  int find(int u)
  {
    if (parent[u] == -1)
      return u;

    else
      return parent[u] = find(parent[u]);
  }
  bool check(int u, int v)
  {
    return (find(u) == find(v)) ? true : false;
  }
  void Union(int u, int v)
  {
    u = find(u);
    v = find(v);

    if (u == v)
      return;
    else
    {
      if (rank[u] > rank[v])
      {
        parent[v] = u;
        rank[u] += rank[v];
      }
      else
      {
        parent[u] = v;
        rank[v] += rank[u];
      }
    }
  }
  int disjointSets()
  {
    return count(parent.begin(), parent.end(), -1);
  }
};

class Solution
{
public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int n = isConnected.size();
    DisjointSet dsu(n);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (isConnected[i][j])
          dsu.Union(i, j);
      }
    }
    return dsu.disjointSets();
  }
};
