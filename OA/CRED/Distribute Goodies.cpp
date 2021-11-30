/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Similar to Maximum Profit in Job Scheduling

using namespace std;
int main()
{
  int n;
  cin >> n;

  vector<long long> startTime(n, 0), endTime(n, 0), orders(n, 0);

  for (int i = 0; i < n; i++)
    cin >> startTime[i];

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> endTime[i];
    endTime[i] += startTime[i];
  }

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> orders[i];

  vector<vector<long long>> calls;

  for (int i = 0; i < n; i++)
  {
    calls.push_back({endTime[i], startTime[i], orders[i]});
  }

  sort(calls.begin(), calls.end());

  map<long long, long long> dp = {{0, 0}};

  for (auto call : calls)
  {
    long long curr = prev(dp.lower_bound(call[1]))->second + call[2];
    if (curr > dp.rbegin()->second)
      dp[call[0]] = curr;
  }

  cout << dp.rbegin()->second << endl;
  return 0;
}