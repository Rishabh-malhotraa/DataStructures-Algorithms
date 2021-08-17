// 959. Regions Cut By Slashes
// Union Find | Geometry | Math | Graph
// Find the numbe of connected components

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int n;
  int getIndex(int r, int c, int pos)
  {
    return 4 * (r * n + c) + pos;
  }

public:
  int regionsBySlashes(vector<string> &grid)
  {
    int n = grid.size();
    this->n = n;
    DisjointSet dsu(4 * n * n);

    /*  4 quadrants of a grid
      0
    3   1
      2
    */

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        char ch = grid[i][j];

        // combining the other grids
        if (i > 0)
          dsu.Union(getIndex(i - 1, j, 2), getIndex(i, j, 0));
        if (j > 0)
          dsu.Union(getIndex(i, j - 1, 1), getIndex(i, j, 3));

        if (ch == '\\')
        {
          dsu.Union(getIndex(i, j, 0), getIndex(i, j, 1));
          dsu.Union(getIndex(i, j, 2), getIndex(i, j, 3));
        }
        else if (ch == '/')
        {
          dsu.Union(getIndex(i, j, 0), getIndex(i, j, 3));
          dsu.Union(getIndex(i, j, 1), getIndex(i, j, 2));
        }
        else
        {
          dsu.Union(getIndex(i, j, 0), getIndex(i, j, 1));
          dsu.Union(getIndex(i, j, 2), getIndex(i, j, 3));
          dsu.Union(getIndex(i, j, 0), getIndex(i, j, 2));
        }
        // combine previous cells
      }
    }
    return dsu.disjointSets();
  }
};

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
