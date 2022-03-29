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
  int numbersMissing(vector<int> &nums, int mid)
  {
    int diff = (nums[mid] - nums[0] - 1) - (mid - 1);
    // cout << nums[mid] << "  " << diff << endl;
    return diff;
  }

public:
  int missingElement(vector<int> &nums, int k)
  {
    int n = nums.size();
    int l = 0, r = n - 1;

    while (l < r)
    {
      int mid = unsigned(l + r + 1) / 2;
      if (numbersMissing(nums, mid) >= k)
        r = mid - 1;
      else
        l = mid;
    }
    int delta = k - numbersMissing(nums, l);
    return nums[l] + delta;
  }
};

/*


     X
   4 7 9 10
       |

 4 -  9  => 5 - 3 => 2
 4- {5,6,7,8} - 9

 3
 we have 4 missing number to which we have we have

     l
 1,2 4

 */