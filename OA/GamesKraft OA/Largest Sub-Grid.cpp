#include <bits/stdc++.h>
using namespace std;

// TC : 10/14 passed

//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

// Most of the people just copied the solution from LC 😢
// https://leetcode.com/discuss/interview-question/850974/hackerrank-online-assessment-roblox-new-grad-how-to-solve-this

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int sumRegion(int row1, int col1, int row2, int col2)
{
  return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
}

bool isPossible(vector<vector<int>> &grid, int k, int maxSum)
{
  int n = grid.size();
  if (k != 0)
    k--;
  for (int i = 0; i + k < n; i++)
  {
    for (int j = 0; j + k < n; j++)
    {
      int sum = sumRegion(i, j, i + k, j + k);
      if (sum > maxSum)
        return false;
    }
  }
  return true;
}

int largestSubgrid(vector<vector<int>> matrix, int maxSum)
{

  int row = matrix.size();
  int col = row > 0 ? matrix[0].size() : 0;
  int n = matrix.size();

  dp = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));

  for (int i = 1; i <= row; i++)
    for (int j = 1; j <= col; j++)
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];

  int l = 0, r = n;

  int result = 0;
  while (l < r)
  {
    int mid = unsigned(l + r) >> 1;
    if (isPossible(matrix, mid, maxSum))
    {
      result = l;
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }

  return result;
}