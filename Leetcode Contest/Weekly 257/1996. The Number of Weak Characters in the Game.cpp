/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// To take care of the edge cases you need to sort the 2nd paramenter in opposite order

class Solution
{
public:
  int numberOfWeakCharacters(vector<vector<int>> &properties)
  {
    sort(properties.begin(), properties.end(), [](vector<int> &a, vector<int> &b)
         {
           if (a[0] == b[0])
             return a[1] < b[1];
           return a[0] > b[0];
         });

    int n = properties.size(), count = 0;
    int previousMax = properties[0][1];
    for (vector<int> &property : properties)
    {
      if (property[1] > previousMax)
        count++;
      previousMax = max(previousMax, property[1]);
    }
    return count;
  }
};

// -- CONTEST SOLUTION ------- //

class Solution
{
private:
  int getUpperBound(int l, int r, vector<vector<int>> &arr, int value)
  {
    while (l < r)
    {
      int mid = unsigned(l + r + 1) >> 1;

      if (arr[mid][0] <= value)
        r = mid - 1;
      else
        l = mid;
    }
    return l;
  }

public:
  int numberOfWeakCharacters(vector<vector<int>> &A)
  {
    sort(A.begin(), A.end(), greater<vector<int>>());
    int n = A.size(), count = 0;
    vector<int> prevLowest = A[0];
    vector<vector<int>> dp(n, {INT_MAX, INT_MAX});
    dp[0] = A[0];
    int i = 0;

    for (int i = 1; i < n; i++)
    {

      if (A[i][1] < dp[i - 1][1] && A[i][0] < dp[i - 1][0])
        count++;

      else if (A[i][0] == dp[i - 1][0])
      {
        int findEl = A[i][0];
        int upperBound = getUpperBound(0, i, A, A[i][0]);

        if (dp[upperBound][0] > A[i][0] && dp[upperBound][1] > A[i][1])
          count++;
      }
      if (dp[i - 1][1] < A[i][1])
        dp[i] = A[i];
      else
        dp[i] = dp[i - 1];
    }

    return count;
  }
};