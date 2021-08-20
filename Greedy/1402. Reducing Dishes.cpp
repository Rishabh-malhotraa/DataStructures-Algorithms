/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Greedy | HARD

class Solution
{
public:
  int maxSatisfaction(vector<int> &A)
  {
    int n = A.size(), curr = 0, result = 0;
    sort(A.begin(), A.end());
    for (int i = n - 1; i >= 0 && A[i] + curr >= 0; i--)
    {
      curr += A[i];
      result += curr;
    }
    return result;
  }
};
