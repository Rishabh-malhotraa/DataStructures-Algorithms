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
  int p = 1e7 + 7;

  vector<long long> roll;

  bool isMatch(string s, int len, int size, string &ans)
  {
    int hash = 0;
    for (int i = 0; i < size; i++)
      hash = (hash * 26 + (s[i] - 'a')) % p;

    unordered_map<int, vector<int>> mp;
    mp[hash].push_back(0);

    for (int j = size; j < len; j++)
    {
      hash = ((hash - roll[size - 1] * (s[j - size] - 'a')) % p + p) % p;
      hash = (hash * 26 + (s[j] - 'a')) % p;

      if (mp.find(hash) != mp.end())
      {
        for (int start : mp[hash])
        {
          string temp = s.substr(start, size);
          string curr = s.substr(j - size + 1, size);
          if (temp == curr)
          {
            ans = temp;
            return true;
          }
        }
      }
      mp[hash].push_back(j - size + 1);
    }
    return false;
  }

  string longestDupSubstring(string s)
  {
    int len = s.length();
    int low = 1, high = len;
    string ans = "";
    roll.resize(len);
    roll[0] = 1;

    for (int i = 1; i < len; i++)
      roll[i] = (26 * roll[i - 1]) % p;

    while (low <= high)
    {
      int mid = (low + high) / 2;
      string temp = "";
      bool flag = isMatch(s, len, mid, temp);
      if (flag == true)
      {
        if (temp.length() > ans.length())
          ans = temp;
        low = mid + 1;
      }
      else
        high = mid - 1;
    }
    return ans;
  }
};