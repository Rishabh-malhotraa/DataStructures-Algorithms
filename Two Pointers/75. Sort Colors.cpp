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
  void sortColors(vector<int> &arr)
  {
    // i feel this is a trick based question! XD
    int n = arr.size();
    int l = 0, r = n - 1, curr = 0;

    // 2   0   2   1   1   0
    // |

    int i = 0;
    while (i <= r)
    {
      if (arr[i] == 0)
        swap(arr[i++], arr[l++]);
      else if (arr[i] == 2)
        swap(arr[i], arr[r--]);
      else
        i++;
    }

    return;
  }
};