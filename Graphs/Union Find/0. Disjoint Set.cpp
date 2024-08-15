#include <bits/stdc++.h>
using namespace std;

// BARE BONE DSU

class DisjointSet
{
private:
  vector<int> parent;
  vector<int> rank;

public:
  DisjointSet(int N)
  {
    parent.assign(N, -1);
    rank.assign(N, 1);
  }

  int find(int u)
  {
    if (parent[u] == -1)
      return u;

    return parent[u] = find(parent[u]);
  }

  void Union(int u, int v)
  {
    u = find(u);
    v = find(v);

    if (u == v)
      return;

    parent[v] = u;
    rank[u] += rank[v];
  }
};

// == DETAILED UNION FIND :-) ==

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

  // Checks whether two elements are in the same set of not
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

class DisjointSetSimple
{
private:
  vector<int> parent;
  DisjointSetSimple(int n)
  {
    parent.assign(n, -1);
  }

  int find(int node)
  {
    if (parent[node] == -1)
      return node;
    return parent[node] = find(parent[node]);
  }

  void Union(int u, int v)
  {
    u = find(u), v = find(v);

    if (u == v)
      return;
    else
      // we can use rank compression here to make it more efficient
      parent[u] = v;
  }
};