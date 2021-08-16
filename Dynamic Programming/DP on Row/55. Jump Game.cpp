//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Greedy | Dynamic Programming

// Greedy-esk Solution
class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int n = nums.size(), end = 0;

    for (int i = 0; i < n; i++)
    {
      if (i > end)
        return false;
      end = max(end, i + nums[i]);
    }
    return true;
  }
};

// Dp-esk Solution
class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int n = nums.size();
    vector<bool> dp(n, false);
    dp[0] = true;

    for (int i = 0; i < n; i++)
    {
      if (dp[i] == false)
        return false;

      int next_steps = nums[i];

      for (int j = 1; j <= next_steps; j++)
        dp[i + j] = true;
    }
    return true;
  }
};