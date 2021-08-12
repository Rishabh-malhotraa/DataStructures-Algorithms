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
  vector<double> medianSlidingWindow(vector<int> &nums, int k)
  {

    vector<double> res;
    vector<long long> med;

    for (int i = 0; i < k; i++)
      med.insert(lower_bound(med.begin(), med.end(), nums[i]), nums[i]);
    if (k % 2 == 0)
      res.push_back((double)(med[k / 2] + med[k / 2 - 1]) / 2);
    else
      res.push_back((double)med[k / 2]);

    for (int i = k; i < nums.size(); i++)
    {
      med.erase(lower_bound(med.begin(), med.end(), nums[i - k]));
      med.insert(lower_bound(med.begin(), med.end(), nums[i]), nums[i]);
      if (k % 2 == 0)
        res.push_back((double)(med[k / 2] + med[k / 2 - 1]) / 2);
      else
        res.push_back((double)med[k / 2]);
    }
    return res;
  }
};