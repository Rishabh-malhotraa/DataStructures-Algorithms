//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// a b b c d

class Solution
{
private:
  vector<vector<string>> result;

  bool isPallindrome(string &s, int left, int right)
  {
    while (left < right)
      if (s[left++] != s[right--])
        return false;
    return true;
  }

  void dfs(int start, string s, vector<string> list)
  {
    int n = s.size();
    if (start == s.size())
    {
      result.push_back(list);
      return;
    }

    for (int end = start; end < n; end++)
    {
      if (isPallindrome(s, start, end))
      {
        list.push_back(s.substr(start, end - start + 1));
        dfs(end + 1, s, list);
        list.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s)
  {
    dfs(0, s, {});
    return result;
  }
};