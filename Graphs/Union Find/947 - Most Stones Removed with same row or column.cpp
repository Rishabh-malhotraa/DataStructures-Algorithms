#include <bits/stdc++.h>
using namespace std;

// Disjoint union set

// Number of components removed = (all components in group1 - 1) + (all components in group2 - 1) ....
// Number of components removed = N - number of disjoint sets

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
private:
  bool isConnected(vector<int> &a, vector<int> &b)
  {
    return (a[0] == b[0] || a[1] == b[1]);
  }

public:
  int removeStones(vector<vector<int>> &stones)
  {
    int n = stones.size();
    DisjointSet dsu(n);

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (isConnected(stones[i], stones[j]))
          dsu.Union(i, j);
      }
    }
    return n - dsu.disjointSets();
  }
};