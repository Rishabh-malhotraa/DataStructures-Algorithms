/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class SparseVector
{
private:
  vector<int> nums;

public:
  SparseVector(vector<int> &nums)
  {
    this->nums = nums;
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector &vec)
  {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += nums[i] * vec.nums[i];
    }
    return sum;
  }
};

// if one of the vector is sparce
class SparseVector
{
private:
  vector<int> nums;

public:
  SparseVector(vector<int> &nums)
  {
    this->nums = nums;
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector &vec)
  {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += nums[i] * vec.nums[i];
    }
    return sum;
  }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);