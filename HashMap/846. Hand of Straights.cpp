/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/*
cards  -> [1,2,3,6,2,3,4,7,8]

           1 2 2 3 3 4 6 7 8
      [1 2 3]  [2 3 4]   [6 7 8]

      1 2 3
        2 3 4
               6 7 8


  [1] -> 1
  [2] -> 2
  [3] -> 2
  [4] -> 1
  [6] -> 1
  [7] -> 1
  [8] -> 1



  [1] -> 1
  [2] -> 1
  [3] -> 1
  [4] -> 1
  [5] -> 1

*/

class Solution
{
public:
  bool isNStraightHand(vector<int> &hand, int groupSize)
  {
    map<int, int> freq;
    for (int el : hand)
      freq[el]++;

    for (auto [el, count] : freq)
    {
      if (count == 0)
        continue;

      for (int i = el; i < (el + groupSize); i++)
      {
        if (freq.find(i) != freq.end() && freq[i] >= count)
          freq[i] -= count;
        else
          return false;
      }
    }

    return true;
  }
};