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
  vector<int> sumArray;

public:
  Solution(vector<int> &w)
  {
    int n = w.size();
    sumArray.assign(n, 0);
    sumArray[0] = w[0];
    for (int i = 1; i < n; i++)
      sumArray[i] = sumArray[i - 1] + w[i];
  }

  int pickIndex()
  {
    // 2 7 10 14
    int idx = rand() % sumArray.back();

    return upper_bound(sumArray.begin(), sumArray.end(), idx) - sumArray.begin();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */