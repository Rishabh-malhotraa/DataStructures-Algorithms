/*
  ____  _     _           _     _       __  __       _ _           _             
  |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _ 
  | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
  |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
  |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

  */

#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, m;

  cin >> m >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> nums = arr;
  sort(nums.begin(), nums.end());

  unordered_map<int, int> keys;
  for (int i = 0; i < nums.size(); i++)
    keys.insert({nums[i], i});

  unordered_map<int, int> freq;
  for (int el : arr)
    freq[el]++;

  vector<int> dp(n, 0);
  int result = 0;
  for (int i = 0; i < n; i++)
  {
    int pos = keys[arr[i]] + freq[arr[i]] - 1;
    freq[arr[i]]--;

    for (int i = 0; i < pos; i++)
      result += dp[i];

    dp[pos] = 1;
  }

  cout << result << endl;
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}