/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// O(NlogN + N) => Time Complexity

class XORPairs
{
private:
  void getRidOfDuplicates(vector<int> &nums)
  {
    set<int> s(nums.begin(), nums.end());
    nums.clear();
    for (int el : s)
      nums.push_back(el);
  }

public:
  int getMinimumXorPair(vector<int> &nums)
  {
    getRidOfDuplicates(nums);
    int result = INT_MAX;
    for (int i = 0; i < nums.size() - 1; i++)
      result = min(result, nums[i] ^ nums[i + 1]);
    return result;
  }
};
