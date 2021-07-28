#include <bits/stdc++.h>
using namespace std;

// 765. Couples Holding Hands

// Union Find | Math | Permutation Graph

/**
 * The swap => breaking the cycke => there could be many cycles
 * The worst case is when you have only one cycles -> you would require n-1 swap
 * for any cycle the number of swaps so that all the nodes
 * would be in correct position would be Ck =  Cycle-Length - 1
 * Sum of all such cases would be => n1 -1 + n2 -1 ..... nk -1 
 * => N - number of connected components
 * -> N - dsu.getDisjointSet()
 * You will 100% have cycles because of the way the questions is constructed
 * 0-> couple[0] -> couple[couple[0]] -> ... -> 0 [Cycle ➰]
*/

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
  int getDisjointSets()
  {
    return count(parent.begin(), parent.end(), -1);
  }
};

class Solution
{
public:
  int minSwapsCouples(vector<int> &row)
  {
    int n = row.size();
    DisjointSet dsu(n);

    for (int i = 0; i < n; i += 2)
      dsu.Union(i, i + 1);

    for (int i = 0; i < n; i += 2)
      dsu.Union(row[i], row[i + 1]);

    return (n / 2) - dsu.getDisjointSets();
  }
};
