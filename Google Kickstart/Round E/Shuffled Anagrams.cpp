/*
 ____  _     _           _     _       __  __       _ _           _             
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _ 
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

string solve()
{
  string s;
  cin >> s;

  string result = "IMPOSSIBLE";
  int n = s.size();
  unordered_map<char, int> cache;
  for (char ch : s)
    cache[ch]++;

  int max_el = INT_MIN;
  vector<pair<char, int>> arr;
  for (auto it : cache)
  {
    arr.push_back(it);
    max_el = max(max_el, it.second);
  }

  sort(arr.begin(), arr.end(), [](pair<char, int> &p1, pair<char, int> &p2)
       { return p1.second > p2.second; });

  if (max_el > n / 2)
    return "IMPOSSIBLE";

  string ns = s;

  int idx = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] != arr[idx].first && arr[idx].second != 0)
    {
      ns[i] = arr[idx].first;

      if (!(--arr[idx].second))
        idx++;
    }
    else
    {
      int temp = idx + 1;
      while (temp < n)
      {
        if (s[i] != arr[temp].first && arr[temp].second != 0)
        {
          ns[i] = arr[temp].first;
          arr[temp].second--;
          break;
        }
        temp++;
      }
    }
  }

  return ns;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  int count = 1;
  while (t--)
  {
    cout << "Case #" << count << ": " << solve() << endl;
    count++;
  }
  return 0;
}