//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

// Math | Iteration | clubbing with backtrackking because of brute force method and permutation questions

// 1. Get permutation in lexicographically manner and give the kth permutation
// 2. Use math to solve the problem oh (n-1)!

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string getPermutation(int n, int k)
  {
    string result;
    vector<int> factorial(n + 1, 1);
    k--;
    // we are calculating based on 0 indexed

    for (int i = 1; i <= n; i++)
      factorial[i] = factorial[i - 1] * i;

    vector<int> nums;
    for (int i = 1; i <= n; i++)
      nums.push_back(i);

    for (int i = n - 1; i >= 0; i--)
    {
      int group_size = factorial[i];

      int idx = k / group_size;
      k = k % group_size;
      result += to_string(nums[idx]);
      nums.erase(nums.begin() + idx);
    }
    return result;
  }
};