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
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    pair<int, int> dp[n];
    dp[0].first = 0;
    dp[n - 1].second = 0;
    int min_value = prices[0];
    int bd = 0, sd = 0;
    for (int i = 1; i < n; i++)
    {
      min_value = min(min_value, prices[i]);
      int profitOnThatDay = prices[i] - min_value;
      dp[i].first = std::max(dp[i - 1].first, profitOnThatDay);
    }

    int max_value = prices[n - 1];

    // this is basically if you buy today what will your max profit in the future
    for (int i = n - 2; i > 0; i--)
    {
      max_value = max(max_value, prices[i]);
      int profitOnThatDay = max_value - prices[i];
      dp[i].second = std::max(dp[i + 1].second, profitOnThatDay);
    }

    for (int i = 0; i < n; i++)
      std::cout << dp[i].first << " " << dp[i].second << endl;
    std::cout << endl;

    int sum = INT_MIN;

    for (int i = 0; i < n; i++)
      sum = max(sum, dp[i].first + dp[i].second);
    return sum;
  }
};