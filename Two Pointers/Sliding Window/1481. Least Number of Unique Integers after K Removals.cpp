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
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k)
  {
    int n = arr.size(), bucket = n - k, distinctElements = 0;

    if (bucket == 0)
      return 0;

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
      freq[arr[i]]++;

    vector<int> count;

    for (auto &[key, value] : freq)
      count.push_back(value);

    sort(count.begin(), count.end(), greater<int>());

    for (auto el : count)
    {
      if (el >= bucket)
        return ++distinctElements;
      else
      {
        bucket -= el;
        distinctElements++;
      }
    }
    return 0;
  }
};

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  Solution *sol = new Solution();

  cout << sol->findLeastNumOfUniqueInts(arr, k) << endl;
}

int main()
{
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

/*
INPUT
4
3 1
5 5 4
7 3
1 1 2 3 3 3 4
13 3
1 3 3 3 6 10 10 13 14 15 15 15 15
*/