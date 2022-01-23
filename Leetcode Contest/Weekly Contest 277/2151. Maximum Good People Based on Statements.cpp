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
private:
  bool isValid(vector<vector<int>> &A, int mask)
  {
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
      bool isIPersonGood = mask >> i & 1;

      if (isIPersonGood)
      {
        // validate ith persons claims
        for (int j = 0; j < n; j++)
        {
          if (A[i][j] == 2)
            continue;
          int isJPersonGood = mask >> j & 1;

          // if asserstion is wrong return false, i.e. of one says true and other says false
          if (isJPersonGood ^ A[i][j])
            return false;
        }
      }
    }
    return true;
  }

public:
  int maximumGood(vector<vector<int>> &statements)
  {
    int n = statements.size();
    int result = 0;
    for (int i = 0; i < (1 << n); i++)
    {
      if (isValid(statements, i))
      {
        result = max(result, __builtin_popcount(i));
      }
    }
    return result;
  }
};