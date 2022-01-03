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
  int N;
  int getDistance(vector<int> &houses, int l, int r, int median)
  {
    int distance = 0;
    for (int i = l; i <= r; i++)
      distance += abs(houses[i] - median);
    return distance;
  }

  int dfs(vector<vector<int>> &distance, vector<vector<int>> &dp, int i, int k)
  {
    if (i == N && k == 0)
      return 0;
    if (i == N || k == 0)
      return 1e5;

    if (dp[i][k] != -1)
      return dp[i][k];

    int cost = INT_MAX;
    for (int j = i; j < N; j++)
      cost = min(cost, distance[i][j] + dfs(distance, dp, j + 1, k - 1));

    return dp[i][k] = cost;
  }

public:
  int minDistance(vector<int> &houses, int k)
  {
    int n = houses.size();
    if (k == n)
      return 0;
    sort(houses.begin(), houses.end());
    this->N = n;
    vector<vector<int>> distance(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        int median = houses[(i + j) / 2];
        distance[i][j] = getDistance(houses, i, j, median);
      }
    }
    return dfs(distance, dp, 0, k);
  }
};