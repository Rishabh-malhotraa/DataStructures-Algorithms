/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  typedef tuple<int, int, int, int> Item;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

public:
  vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k)
  {
    m = grid.size(), n = grid[0].size();
    priority_queue<Item, vector<Item>, greater<Item>> pq;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    pq.push({0, grid[start[0]][start[1]], start[0], start[1]});
    visited[start[0]][start[1]] = true;

    int lower = pricing[0], upper = pricing[1];

    vector<vector<int>> items;
    while (pq.empty() == false)
    {
      auto [dist, price, i, j] = pq.top();
      pq.pop();

      if (price >= lower && price <= upper)
        items.push_back({i, j});

      if (items.size() == k)
      {
        return items;
      }

      for (vector<int> &d : dir)
      {
        int ni = i + d[0], nj = j + d[1];

        if (isValid(ni, nj) && grid[ni][nj] != 0 && visited[ni][nj] == false)
        {
          visited[ni][nj] = true;
          pq.push({dist + 1, grid[ni][nj], ni, nj});
        }
      }
    }

    // reverse(items.begin(), items.end());
    return items;
  }
};