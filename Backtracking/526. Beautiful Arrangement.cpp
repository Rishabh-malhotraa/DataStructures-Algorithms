//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Permutation with check

class Solution
{
public:
  int result = 0;
  void permutations(vector<int> &arr, int idx)
  {
    int n = arr.size();
    if (idx == n)
    {
      result++;
      return;
    }

    for (int i = idx; i < n; i++)
    {
      if (arr[i] % idx == 0 || idx % arr[i] == 0)
      {
        swap(arr[i], arr[idx]);
        permutations(arr, idx + 1);
        swap(arr[i], arr[idx]);
      }
    }
  }

  int countArrangement(int n)
  {
    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; i++)
      nums[i] = i;

    permutations(nums, 1);
    return result;
  }
};