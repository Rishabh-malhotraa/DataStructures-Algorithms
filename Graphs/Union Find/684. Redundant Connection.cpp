/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

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

  // Find the parent of the Disjoint Set
  int find(int u)
  {
    if (parent[u] == -1)
      return u;

    else
      return parent[u] = find(parent[u]);
  }

  // Merge Two Disjoint Sets
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

  // Checks whether two elements are in the same set or not
  bool check(int u, int v)
  {
    return (find(u) == find(v)) ? true : false;
  }

  // Count the numeber of Disjoint Sets
  int getDisjointSets()
  {
    return count(parent.begin(), parent.end(), -1);
  }

  // Get the size of the Disjoint Set
  int getRank(int u)
  {
    return rank[u];
  }

  // Get the Largest Disjoint Set
  int getMaxRank()
  {
    return *max_element(rank.begin(), rank.end());
  }
};

class Solution
{
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges)
  {
    set<int> s;
    for (vector<int> &edge : edges)
      s.insert(edge[0]), s.insert(edge[1]);
    int n = s.size();

    DisjointSet dsu(n + 1);

    for (vector<int> &edge : edges)
    {
      int u = edge[0], v = edge[1];
      if (dsu.check(u, v))
        return edge;
      else
        dsu.Union(u, v);
    }
    return {};
  }
};