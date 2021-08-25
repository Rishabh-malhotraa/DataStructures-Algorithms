//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for (int i = 0; i < n; i++)
    {
      if (i > 0 && nums[i - 1] == nums[i])
        continue;

      for (int j = i + 1; j < n; j++)
      {
        if (j > i + 1 && nums[j - 1] == nums[j])
          continue;
        // do 2 sum once the two indcies are fixed
        int sum = nums[i] + nums[j] - target;
        int l = j + 1;
        int r = n - 1;
        // bidirectional sweep

        while (l < r)
        {
          int checkSum = sum + nums[l] + nums[r];

          if (checkSum > 0)
            r--;
          else if (checkSum < 0)
            l++;
          else
          {
            result.push_back({nums[i], nums[j], nums[l++], nums[r--]});

            while (l < r && nums[l] == result.back()[2])
              l++;

            while (l < r && nums[r] == result.back()[3])
              r--;
          }
        }
      }
    }
    return result;
  }
};