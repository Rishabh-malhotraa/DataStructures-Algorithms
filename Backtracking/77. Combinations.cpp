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
  vector<vector<int>> result;

  void backtrack(int start, int n, int k, vector<int> list)
  {
    if (list.size() == k)
    {
      result.push_back(list);
      return;
    }

    for (int i = start; i <= n; i++)
    {
      list.push_back(i);
      backtrack(i + 1, n, k, list);
      list.pop_back();
    }
  }

  vector<vector<int>> combine(int n, int k)
  {

    backtrack(1, n, k, {});

    return result;
  }
};