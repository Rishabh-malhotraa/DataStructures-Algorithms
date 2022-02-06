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
  long long minimumDifference(vector<int> &A)
  {
    priority_queue<int> L;                         // storing the smallest N digits in the first part
    priority_queue<int, vector<int>, greater<>> R; // storing the greatest N digits in the right part
    long N = A.size() / 3, left = 0, right = 0, ans = LLONG_MAX;
    vector<long> tmp(A.size());
    for (int i = A.size() - 1; i >= N; --i)
    { // calculate the greatest N digits in the right part
      R.push(A[i]);
      right += A[i];
      if (R.size() > N)
      {
        right -= R.top();
        R.pop();
      }
      if (R.size() == N)
        tmp[i] = right; // `tmp[i]` is the maximum sum of `N` digits in `A[i:]`
    }
    for (int i = 0; i < A.size() - N; ++i)
    {
      L.push(A[i]);
      left += A[i];
      if (L.size() > N)
      {
        left -= L.top();
        L.pop();
      }
      if (L.size() == N)
        ans = min(ans, left - tmp[i + 1]);
    }
    return ans;
  }
};