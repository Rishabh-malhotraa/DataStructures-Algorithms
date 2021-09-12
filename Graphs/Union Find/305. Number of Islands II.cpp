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
    parent.resize(N, -2);
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

  void add(int idx)
  {
    parent[idx] = -1;
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

class Solution
{
private:
  int m, n;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  int getIdx(int x, int y)
  {
    return n * x + y;
  }

public:
  vector<int> numIslands2(int m, int n, vector<vector<int>> &positions)
  {
    this->m = m, this->n = n;
    DisjointSet dsu(m * n);
    vector<int> result;
    vector<vector<int>> grid(m, vector<int>(n, 0));

    for (vector<int> &position : positions)
    {
      int i = position[0], j = position[1];
      grid[i][j] = 1;
      dsu.add(getIdx(i, j));

      for (vector<int> &d : dir)
      {
        int ni = i + d[0], nj = j + d[1];
        if (isValid(ni, nj) && grid[ni][nj] == 1)
          dsu.Union(getIdx(ni, nj), getIdx(i, j));
      }
      result.push_back(dsu.getDisjointSets());
    }

    return result;
  }
};
