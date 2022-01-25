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
  bool checkValid(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
      unordered_set<int> cache(matrix[i].begin(), matrix[i].end());
      if (cache.size() < n)
        return false;
    }

    for (int j = 0; j < n; j++)
    {
      unordered_set<int> cache;
      for (int i = 0; i < n; i++)
        cache.insert(matrix[i][j]);

      if (cache.size() < n)
        return false;
    }
    return true;
  }
};