//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

/**
 * DFS | Union Find | BFS
 * Brute force is to calculate dfs for every water cell and calculate the max component size
 * 
 * Efficient solution is using union find by caching the componet size's in dsu
 * the TC then would be O(N^2) else it would be O(N^3)
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
  int getRank(int u)
  {
    return rank[u];
  }
  int getMaxRank()
  {
    return *max_element(rank.begin(), rank.end());
  }
};

class Solution
{
private:
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  int n;
  bool isValid(int x, int y)
  {
    return (x >= 0 && x < n && y >= 0 && y < n);
  }
  int getIdx(int x, int y)
  {
    return (x * n + y);
  }

public:
  int largestIsland(vector<vector<int>> &grid)
  {
    n = grid.size();
    DisjointSet dsu(n * n);

    // Calculating the size of all components
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          for (vector<int> &d : dir)
          {
            int x = i + d[0];
            int y = j + d[1];

            if (isValid(x, y) && grid[x][y] == 1)
              dsu.Union(getIdx(i, j), getIdx(x, y));
          }
        }
      }
    }

    int result = dsu.getMaxRank();

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 0)
        {
          set<int> cache;
          int size = 1;
          for (vector<int> &d : dir)
          {
            int x = i + d[0];
            int y = j + d[1];
            if (isValid(x, y) && grid[x][y] == 1)
            {
              int parent = dsu.find(getIdx(x, y));
              if (cache.find(parent) == cache.end())
              {
                cache.insert(parent);
                size += dsu.getRank(parent);
              }
            }
          } // end of visting adjacent neighbours
          result = max(result, size);
        }
      }
    }
    return result;
  }
};