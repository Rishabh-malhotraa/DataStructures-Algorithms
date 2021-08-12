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
    if (n == 0)
      return 0;
    vector<int> bs(n, 0);
    vector<int> ss(n, 0);
    vector<int> cds(n, 0);

    bs[0] = -prices[0];
    for (int i = 1; i < n; i++)
    {
      bs[i] = max(bs[i - 1], -(prices[i] - cds[i - 1]));
      ss[i] = max(ss[i - 1], prices[i] + bs[i - 1]);
      cds[i] = max(cds[i - 1], ss[i - 1]);
    }
    return ss[n - 1];
  }
};