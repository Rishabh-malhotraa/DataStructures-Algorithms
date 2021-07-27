#include <bits/stdc++.h>
using namespace std;

// Math -- bit manupilation HARD

class Solution
{
public:
  int findIntegers(int n)
  {
    vector<int> dp(32, 0);

    for (int i = 2; i < 32; i++)
      dp[i] = dp[i - 1] + dp[i - 2] + (1 << i - 2);
    /*
    * for a 5 bit number `XXXXX`
    * First Case  is  0----  => dp[n-1] = dp[4]
    * Second Case is  1----  => this would further have two cases
    * n-1 is either 0/1
    * 10--- -> dp[n-2] => dp[3]
    * 11--- -> now we have 2 consecutive 11 so all the 3 digit numbers would 
    * satisfy the condition => 2^(n-2)
    * dp[n] = dp[n-1] + dp[n-2] + 2^(n-2)   
    */
    return n + 1 - helper(n, dp);
  }

  int helper(int n, vector<int> &dp)
  {
    int power = log(n) / log(2);

    if ((1 << power) == n)
      return dp[power];

    int baseNumber = 1 << power;
    int leftOver = n - baseNumber;

    if (leftOver < baseNumber / 2)
      return (dp[power] + helper(leftOver, dp));
    else
      return (dp[power] + dp[power - 1] + leftOver - (baseNumber / 2) + 1);
  }
};