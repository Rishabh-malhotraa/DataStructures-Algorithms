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
  bool isPossible(vector<int> &nums, int target, int splits)
  {
    int count = 0, currSum = 0;

    for (int num : nums)
    {
      currSum += num;
      if (currSum > target)
      {
        currSum = num;
        count++;
      }
    }

    return (count >= splits) ? false : true;
  }

public:
  int splitArray(vector<int> &nums, int m)
  {
    int l = *max_element(nums.begin(), nums.end());
    int r = accumulate(nums.begin(), nums.end(), 0);

    while (l < r)
    {
      int mid = unsigned(l + r) >> 1;

      if (isPossible(nums, mid, m) == false)
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }
};

// DFS BRUTE FORCE SOLUTION

class Solution
{
private:
  int result = INT_MAX;
  void dfs(vector<int> &nums, int idx, int m, int currSum, int currMax)
  {
    int n = nums.size();
    if (idx == n && m == 0)
    {
      result = min(result, currMax);
      return;
    }

    if (idx == n || m == 0)
      return;

    currSum += nums[idx];

    dfs(nums, idx + 1, m, currSum, currMax);
    dfs(nums, idx + 1, m - 1, 0, max(currSum, currMax));
  }

public:
  int splitArray(vector<int> &nums, int m)
  {
    dfs(nums, 0, m, 0, 0);
    return result;
  }
};