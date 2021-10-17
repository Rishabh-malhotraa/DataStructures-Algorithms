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
  bool isSameSet(int u, int v)
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
  vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
  {
    int n = edges.size() + 1;
    DisjointSet dsu(n);
    bool isCyclic = false, hasTwoParent = false;
    vector<int> removedEdge, cyclicEdge;
    vector<int> parent(n + 1, -1);
    for (vector<int> &edge : edges)
    {
      int u = edge[0], v = edge[1];

      if (parent[v] == -1)
        parent[v] = u;
      else
      {
        hasTwoParent = true;
        removedEdge = edge;
        break;
      }
    }

    // check if the disjoint things have a cycle or not
    for (vector<int> &edge : edges)
    {
      int u = edge[0], v = edge[1];
      if (edge == removedEdge)
      {
        continue;
      }

      if (dsu.isSameSet(u, v))
      {
        cyclicEdge = edge;
        isCyclic = true;
        break;
      }
      dsu.Union(u, v);
    }

    // Remove the edge which creatres a cycle
    if (hasTwoParent == false)
      return cyclicEdge;

    // you removed the correct edge or the wrong edge
    if (isCyclic == false)
      return removedEdge;
    else
    {
      // removed the wrong edge there is still a cycle
      // now find the node with two parents
      // and remove the other parent -> node combination for that node
      int v = removedEdge.back();
      int u = parent[v];
      return vector<int>{u, v};
    }
  }
};
