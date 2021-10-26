/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

int m, n;

vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<char> cdir = {'R', 'L', 'D', 'U'};

bool isValid(int i, int j)
{
  return (i >= 0 && i < m && j >= 0 && j < n);
}

string dfs(int i, int j, vector<vector<int>> &matrix)
{
  matrix[i][j] = 0;
  int idx = 0;
  string path;
  for (vector<int> &d : dir)
  {
    int ni = i + d[0];
    int nj = j + d[1];
    if (isValid(ni, nj) && matrix[ni][nj] == 1)
    {
      path += cdir[idx];
      path += dfs(ni, nj, matrix);
    }
    idx++;
  }

  path += 'B';
  return path;
}

int solve(vector<vector<int>> &matrix)
{
  m = matrix.size(), n = matrix[0].size();
  // string path;
  int distinctIslands = 0;
  unordered_set<string> cache;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (matrix[i][j] == 1)
      {
        string shape = dfs(i, j, matrix);
        cout << shape << endl;
        if (cache.find(shape) == cache.end())
        {
          cache.insert(shape);
          distinctIslands++;
        }
      }
    }
  }

  return distinctIslands;
}
