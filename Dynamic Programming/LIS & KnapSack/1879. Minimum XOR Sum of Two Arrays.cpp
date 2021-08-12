//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dfs(vector<int> &dp, vector<int> &nums1, vector<int> &nums2, int i, int mask)
  {
    if (i >= nums1.size())
      return 0;
    if (dp[mask] == INT_MAX)
    {
      for (int j = 0; j < nums2.size(); j++)
      {
        if ((mask & (1 << j)) == 0)
          dp[mask] = min(dp[mask], (nums1[i] ^ nums2[j]) + dfs(dp, nums1, nums2, i + 1, (mask | 1 << j)));
      }
    }
    return dp[mask];
  }

  int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
  {
    vector<int> dp(1 << nums2.size(), INT_MAX);
    int result = dfs(dp, nums1, nums2, 0, 0);
    return result;
  }
};