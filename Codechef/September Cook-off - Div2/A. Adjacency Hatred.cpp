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
  int n;
  cin >> n;
  vector<int> arr(n);
  int countOdd = 0, countEven = 0;
  vector<int> odd, even;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    if (arr[i] % 2 == 0)
    {
      even.push_back(arr[i]);
      countEven++;
    }
    else
    {
      odd.push_back(arr[i]);
      countOdd++;
    }
  }

  if (countEven == 0 || countOdd == 0)
    cout << "-1" << endl;
  else
  {
    even.insert(even.end(), odd.begin(), odd.end());
    for (int el : even)
      cout << el << " ";
    cout << endl;
  }

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