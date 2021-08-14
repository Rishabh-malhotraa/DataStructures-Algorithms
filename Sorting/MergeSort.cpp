//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class MergeSort
{
private:
  void merge(int left, int mid, int right, vector<int> &nums)
  {
    int len = right - left + 1;

    vector<int> temp(len);

    for (int i = 0, p = left, q = mid + 1; i < len; i++)
    {
      if (p < mid)
        temp[i] = nums[q++];
      else if (q > right)
        temp[i] = nums[p++];
      else if (nums[p] > nums[q])
        temp[i] = nums[q++];
      else
        temp[i] = nums[p++];
    }

    for (int i = 0; i < len; i++)
      nums[i + left] = temp[i];

    return;
  }

  void mergeSort(int left, int right, vector<int> &nums)
  {
    if (left < right)
    {
      int mid = unsigned(left + right) >> 1;

      mergeSort(left, mid, nums);
      mergeSort(mid + 1, right, nums);

      merge(left, mid, right, nums);
    }
  }

public:
  vector<int> sortArray(vector<int> &nums)
  {
    mergeSort(0, nums.size() - 1, nums);
    return nums;
  }
};
