/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/
// 1,2,3,3,4,4,5,5
// 123 345

// we need to greedily keep increaseing the window unitl we cannot | after that
// we start a new window || if we dont do that, test cases like these would fail
// [1,2,3,4,5,5,6,7]  -> 1 2 3 4 5  ||  5 6 7
// but if we dont greedily increase int window 1 2 3 || 4 5 6 7 || <5>

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPossible(vector<int> &nums)
  {
    unordered_map<int, int> freq, endAt;
    for (int el : nums)
      freq[el]++;

    int count = 0;

    for (int el : nums)
    {
      if (freq[el] == 0)
        continue;

      freq[el]--;
      if (endAt[el - 1] > 0)
      {
        endAt[el - 1]--;
        endAt[el]++;
      }
      else if (freq[el + 1] && freq[el + 2])
      {
        freq[el + 1]--, freq[el + 2]--;
        endAt[el + 2]++;
      }
      else
        return false;
    }
    return true;
  }
};
