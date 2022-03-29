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
public:
  int maxRotateFunction(vector<int> &nums)
  {
    int sum = 0, window = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
      sum += nums[i];
      window += i * nums[i];
    }
    int result = window;
    for (int i = n - 1; i > 0; i--)
    {
      window = window + sum - n * nums[i];
      result = max(result, window);
    }
    return result;
  }
};

/*
= 0*a[0] + 1*a[1] + 2*a[2] + 3*a[3] + 4*a[4] = F[0]
= 0*a[3] + 1*a[0] + 2*a[1] + 3*a[2] + 4*a[3] = F[0] + sum - n*F[0][0]

F[i+1] = F[i] + sum - n*F[i][0]
a[0] + a[1] + a[2] + a[3]
*/