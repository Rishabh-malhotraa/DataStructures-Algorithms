/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// ==================================================================
//                    USING UNION FIND
// ==================================================================

class DisjointSet
{
private:
  vector<int> parent;
  vector<int> rank;

public:
  DisjointSet(int N, vector<vector<char>> &grid)
  {
    parent.resize(N, -1);
    rank.resize(N, 1);

    for (int i = 0; i < N; i++)
    {
      if (grid[i / grid[0].size()][i % grid[0].size()] == '0')
        parent[i] = -2;
    }
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


class Solution
{
public:
  int m, n;
  int getIdx(int x, int y)
  {
    return x * n + y;
  }

  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  int numIslands(vector<vector<char>> &grid)
  {
    m = grid.size(), n = grid[0].size();
    DisjointSet dsu(m * n, grid);
    // vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == '1')
        {

          for (vector<int> &d : dir)
          {
            int ni = i + d[0], nj = j + d[1];
            if (isValid(ni, nj) && grid[ni][nj] == '1')
              dsu.Union(getIdx(ni, nj), getIdx(i, j));
          }
        }
      }
    }
    return dsu.getDisjointSets();
  }
};

// ==================================================================
//                    USING DEPTH FIRST SEARCH
// ==================================================================

class getIsland
{
private:
  int m, n;
  const int VISITED = 2;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  void dfs(int i, int j, vector<vector<int>> &matrix)
  {
    matrix[i][j] = VISITED;

    for (vector<int> &d : dir)
    {
      int ni = i + d[0], nj = j + d[1];
      if (isValid(ni, nj) && matrix[ni][nj] == 1)
        dfs(ni, nj, matrix);
    }
    return;
  }

public:
  int getIslands(vector<vector<int>> &matrix)
  {
    m = matrix.size(), n = matrix[0].size();
    int count = 0;

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (matrix[i][j] == 1)
        {
          dfs(i, j, matrix);
          count++;
        }

    return count;
  }
};
