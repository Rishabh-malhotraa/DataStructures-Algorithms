#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> left(n, 1);
    vector<int> right(n, 1);
    vector<int> result(n, 0);

    for (int i = 0; i < n; i++)
    {
      int prev = (i == 0) ? 1 : left[i - 1];
      left[i] = prev * nums[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
      int next = (i == n - 1) ? 1 : right[i + 1];
      right[i] = next * nums[i];
    }

    for (int i = 0; i < n; i++)
    {
      int prev = (i == 0) ? 1 : left[i - 1];
      int next = (i == n - 1) ? 1 : right[i + 1];
      result[i] = prev * next;
    }
    return result;
  }
};