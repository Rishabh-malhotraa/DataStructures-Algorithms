/*
 ____  _     _           _     _       __  __       _ _           _             
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _ 
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

int getMaximumSegment(vector<int> &arr, int k)
{
  int result = INT_MIN;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> mins;
  for (int i = 0; i < k - 1; i++)
    pq.push({arr[i], i});

  for (int i = k - 1; i < arr.size(); i++)
  {
    pq.push({arr[i], i});

    result = max(result, pq.top().first);
    mins.push_back(pq.top().first);
    if (pq.top().second <= i + 1 - k)
      pq.pop();
  }

  for (int min : mins)
    cout << min << " ";
  cout << endl;

  return result;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << getMaximumSegment(arr, k) << endl;
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